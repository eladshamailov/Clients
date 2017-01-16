//
// Created by elad on 1/16/17.
//

#include <packets/WRQ.h>

string WRQ::getFileName()
{
    return fileName;
}

WRQ::WRQ(string fleName) : Packet((short)2),fileName(fileName){}