//
// Created by elad on 1/16/17.
//
#include "packets/Packet.h"
Packet::Packet(short opCode)
{
    this->opCode = opCode;
}

short Packet::getOpCode()
{
    return opCode;
}

Packet::~Packet() {

}
