//
// Created by elad on 1/16/17.
//

#include <packets/Packet.h>

#ifndef CLIENTS_RRQ_H
#define CLIENTS_RRQ_H

#endif //CLIENTS_RRQ_H
class RRQ : public Packet
{
private:
    string fileName;
public:
    virtual string getName();
    RRQ(string fileName);

    virtual ~RRQ();
};