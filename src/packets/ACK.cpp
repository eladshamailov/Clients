//
// Created by elad on 1/16/17.
//

#include <packets/ACK.h>
#include "packets/Packet.h"

ACK::ACK(short block) : Packet((short)4)
{
    this->block = block;
}

short ACK::getBlock()
{
    return block;
}

//////