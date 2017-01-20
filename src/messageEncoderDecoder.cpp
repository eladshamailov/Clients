//
// Created by elad on 1/20/17.
//

#include "messageEncoderDecoder.h"
#include <connectionHandler.h>
#include <packets/Packet.h>
#include <packets/DISC.h>
#include <packets/DIRQ.h>
#include <packets/WRQ.h>
#include <packets/ACK.h>
#include <packets/LOGRQ.h>
#include <packets/DELRQ.h>
#include <packets/RRQ.h>

void messageEncoderDecoder::encode(Packet *packet, char *encodedArr) {
    char result[2];
    shortToBytes(packet->getOpCode(), result);

    char zero[1];
    zero[0] = '\0';
    char blockArr[2];
    char packetSize[2];
    char fileNameWithZero[512];
    char userNameWithZero[512];

    short opCode = packet->getOpCode();

    if (opCode == 1) {
        RRQ *RRQPack = (RRQ *) packet;
        strcpy(fileNameWithZero, (RRQPack->getFileName() + '\0').c_str());
        connectArrays(result, 2, fileNameWithZero, 512, encodedArr);
    } else if (opCode == 2) {
        WRQ *WRQPack = (WRQ *) packet;
        strcpy(fileNameWithZero, (WRQPack->getFileName() + '\0').c_str());
        connectArrays(result, 2, fileNameWithZero, 512, encodedArr);
    } else if (opCode == 3) {
        DATA *DATAPack = (DATA *) packet;
        shortToBytes(DATAPack->getBlock(), blockArr);
        shortToBytes(DATAPack->getPacketSize(), packetSize);
        char temp[4];
        connectArrays(result, 2, packetSize, 2, temp);
        char temp2[6];
        connectArrays(temp, 4, blockArr, 2, temp2);
        connectArrays(temp2, 6, DATAPack->getData(), DATAPack->getPacketSize(), encodedArr);
    } else if (opCode == 4) {
        ACK *ACKPack = (ACK *) packet;
        shortToBytes(ACKPack->getBlock(), blockArr);
        connectArrays(result, 2, blockArr, 2, encodedArr);
    } else if (opCode == 7) {
        LOGRQ *LOGRQPack = (LOGRQ *) packet;
        connectArrays(LOGRQPack->getUserName().c_str(), LOGRQPack->getUserName().length(), zero, 1, userNameWithZero);
        connectArrays(result, 2, userNameWithZero, 512, encodedArr);
    } else if (opCode == 8) {
        DELRQ *DELRQPack = (DELRQ *) packet;
        strcpy(fileNameWithZero, (DELRQPack->getFileName() + '\0').c_str());
        connectArrays(result, 2, fileNameWithZero, 512, encodedArr);
    } else { //DIRQ and DISC
        memcpy(encodedArr, result, 2);
    }
}