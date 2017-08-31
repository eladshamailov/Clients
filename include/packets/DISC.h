//
// Created by elad on 1/16/17.
//

#include <packets/Packet.h>

#ifndef CLIENTS_DISC_H
#define CLIENTS_DISC_H

#endif //CLIENTS_DISC_H
class DISC : public Packet
{
public:
    DISC();
    int getLength();

    virtual ~DISC();
};