//
// Created by elad on 1/16/17.
//

#include <vector>
#include "Packet.h"

#ifndef CLIENTS_DATA_H
#define CLIENTS_DATA_H

#endif //CLIENTS_DATA_H

class DATA : public Packet
{
private:
    short packetSize = 0;
    short block = 0;
    char* data;

public:
    DATA(short packetSize, short block, char* data);

    virtual short getBlock();

    virtual char* getData();

    virtual short getPacketSize();

};