//
// Created by elad on 1/16/17.
//

#include "Packet.h"

#ifndef CLIENTS_DELRQ_H
#define CLIENTS_DELRQ_H

#endif //CLIENTS_DELRQ_H
class DELRQ : public Packet
{
private:
    std::wstring fileName;
public:
    DELRQ(const std::wstring &name);
    virtual std::wstring getFileName();
};