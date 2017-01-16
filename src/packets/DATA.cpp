//
// Created by elad on 1/16/17.
//

#include <packets/Packet.h>
#include <vector>
#include <packets/DATA.h>

DATA::DATA(short packetSize, short block, std::vector<char> &data) : Packet((short)3)
{
    this->packetSize = packetSize;
    this->block = block;
    this->data = std::vector<char>(data.size());
    for (int i = 0;i < data.size();i++)
    {
        this->data[i] = data[i];
    }
}

short DATA::getBlock()
{
    return block;
}

std::vector<char> DATA::getData()
{
    return data;
}

short DATA::getPacketSize()
{
    return packetSize;
}
}