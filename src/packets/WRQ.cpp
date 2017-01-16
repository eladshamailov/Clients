//
// Created by elad on 1/16/17.
//

#include <packets/WRQ.h>

std::wstring WRQ::getFileName()
{
    return fileName;
}

WRQ::WRQ(const std::wstring &name) : Packet((short)2)
{
    this->fileName = name;
}