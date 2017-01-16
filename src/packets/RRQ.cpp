//
// Created by elad on 1/16/17.
//

#include <packets/RRQ.h>

std::wstring RRQ::getName()
{
    return fileName;
}

RRQ::RRQ(const std::wstring &name) : Packet((short)1)
{

    this->fileName = name;
}