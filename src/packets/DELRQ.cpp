//
// Created by elad on 1/16/17.
//

#include <packets/Packet.h>
#include <packets/DELRQ.h>

DELRQ::DELRQ(const std::wstring &name) : Packet((short)8)
{
    this->fileName = name;
}

std::wstring DELRQ::getFileName()
{
    return fileName;
}