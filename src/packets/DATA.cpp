//
// Created by elad on 1/16/17.
//

#include <packets/Packet.h>
#include <vector>
#include <packets/DATA.h>

DATA::DATA(short packetSize, short block, std::vector<char> data) : Packet((short)3),packetSize(packetSize),block(block),data(data){}

short DATA::getBlock()
{
    return block;
}

std::vector <char> DATA::getData()
{
    //TODO:check if the return is good
    return data;
}

short DATA::getPacketSize()
{
    return packetSize;
}
