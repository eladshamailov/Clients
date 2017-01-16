//
// Created by elad on 1/16/17.
//

#include <packets/Packet.h>
#include <packets/LOGRQ.h>

LOGRQ::LOGRQ(const std::wstring &userName) : Packet((short)7)
{
    this->userName = userName;
}

std::wstring LOGRQ::getUserName()
{
    return userName;
}