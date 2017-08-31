//
// Created by elad on 1/16/17.
//

#include <packets/Packet.h>

#ifndef CLIENTS_ACK_H
#define CLIENTS_ACK_H


class ACK : public Packet
{
private:
    short block = 0;
public:
    ACK(short block);
    virtual short getBlock();
    int getLength();

    virtual ~ACK();
};

#endif //CLIENTS_ACK_H