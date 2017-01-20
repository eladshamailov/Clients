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
    char userNameWithZero[512];
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
            mergeArrays((char *) LOGRQPacket->getUserName().c_str(), LOGRQPacket->getUserName().length(), zero, 1, userNameWithZero);
            mergeArrays(answer, 2, userNameWithZero, 512, answerArr);
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

char* messageEncoderDecoder::mergeArrays(char *ptr1, int m, char *ptr2, int n,char *connected)
{
    char *p=new char[m+n],i,j,k;
    for(i=0,k=m-1;i<(m/2);i++,k--) //to reverse the fir``st array from ascending to descending
    {
        j=*(ptr1+i);
        *(ptr1+i)=*(ptr1+k);
        *(ptr1+k)=j;
    }
    for(i=0,j=0,k=0;i<m&&j<n;)
    {
        if (*(ptr1+i) > *(ptr2+j))
        {
            *(p+k)=*(ptr1+i);
            i++;k++;
        }
        else
        {
            *(p+k)=*(ptr2+j);
            j++;k++;
        }
    }
    if(i==m)
        while(j<n)
        {
            *(p+k)=*(ptr2+j);
            j++;k++;
        }
    else if(j==n)
        while(i<m)
        {
            *(p+k)=*(ptr1+i);
            i++;k++;
        }
    connected=p;
    return connected;
}
