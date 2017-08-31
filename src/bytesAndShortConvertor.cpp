//
// Created by elad on 1/20/17.
//

#include "bytesAndShortConvertor.h"
short bytesAndShortConvertor::bytesToShort(char* bytesArr)
{
    short result = (short)((bytesArr[0] & 0xff) << 8);
    result += (short)(bytesArr[1] & 0xff);
    return result;
}

void bytesAndShortConvertor:: shortToBytes(short num, char* bytesArr)
{
    bytesArr[0] = ((num >> 8) & 0xFF);
    bytesArr[1] = (num & 0xFF);
}

bytesAndShortConvertor::~bytesAndShortConvertor() {

}
