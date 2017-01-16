//
// Created by elad on 1/16/17.
//

#include <packets/RRQ.h>

string RRQ::getName()
{
    return fileName;
}

RRQ::RRQ(string fileName) : Packet((short)1),fileName(fileName){}