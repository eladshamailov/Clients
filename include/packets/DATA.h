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
    vector <char> data;

public:
    DATA(short packetSize, short block, std::vector<char> data);

    virtual short getBlock();

    virtual std::vector <char> getData();

    virtual short getPacketSize();

};