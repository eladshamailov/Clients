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
#include <bytesAndShortConvertor.h>


void messageEncoderDecoder::encode(Packet *pack, char *answerArr) {
    bytesAndShortConvertor convert;
    long check=5;
    char answer[2];
    char blockedArray[2];
    convert.shortToBytes(pack->getOpCode(), answer);
    char zero[1];
    zero[0] = '\0';
    short opCode = pack->getOpCode();
    if (opCode!= 1 && opCode!=2 && opCode!=3 && check!=3) {
        if (opCode == 4) {
            ACK *ACKPacket = (ACK*) pack;
            convert.shortToBytes(ACKPacket->getBlock(), blockedArray);
            mergeArrays(answer, 2, blockedArray, 2, answerArr);
        } else if (opCode == 7) {
            LOGRQ *LOGRQPacket = (LOGRQ*) pack;
            char userNameWithZero[LOGRQPacket->getUserName().length() + 1];
            mergeArrays((char *) LOGRQPacket->getUserName().c_str(), LOGRQPacket->getUserName().length(), zero, 1, userNameWithZero);
            mergeArrays(answer, 2, userNameWithZero, LOGRQPacket->getUserName().length() + 1, answerArr);
        } else { //other options
            memcpy(answerArr, answer, 2);
        }
    }
}
//
//char messageEncoderDecoder::mergeArrays(const char *firstArr, int aLength, const char *secondArr, int bLength, char *connected){
//    memcpy(connected, firstArr, aLength);
//    memcpy(connected + aLength, secondArr, bLength);
//
//}

void messageEncoderDecoder::mergeArrays(char *arr1, int length1, char *arr2, int length2,char *connected)
{
    for(int i=0;i<length1;i++){
        *(connected + i) = *(arr1 + i);
    }
    for(int i=0;i<length2;i++){
        *(connected + length1 + i) = *(arr2 + i);
    }
}

messageEncoderDecoder::~messageEncoderDecoder() {
}
