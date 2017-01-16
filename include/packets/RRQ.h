//
// Created by elad on 1/16/17.
//

#include "Packet.h"

#ifndef CLIENTS_RRQ_H
#define CLIENTS_RRQ_H

#endif //CLIENTS_RRQ_H
class RRQ : public Packet
{
private:
    std::wstring fileName;
public:
    virtual std::wstring getName();
    RRQ(const std::wstring &name);
};