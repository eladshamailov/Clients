//
// Created by elad on 1/16/17.
//

#include "Packet.h"

#ifndef CLIENTS_WRQ_H
#define CLIENTS_WRQ_H

#endif //CLIENTS_WRQ_H
class WRQ : public Packet
{
private:
    std::wstring fileName;
public:
    virtual std::wstring getFileName();
    WRQ(const std::wstring &name);

};