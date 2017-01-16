//
// Created by elad on 1/16/17.
//

#include <packets/Packet.h>
#include <vector>
#include <packets/DATA.h>

DATA::DATA(short packetSize, short block, char* data) : Packet((short)3),packetSize(packetSize),block(block),data(data){}

short DATA::getBlock()
{
    return block;
}

char* DATA::getData()
{
    char ans[sizeof(data)];
    std::copy(data, data+sizeof(data), ans);
    return ans;}

short DATA::getPacketSize()
{
    return packetSize;
}
