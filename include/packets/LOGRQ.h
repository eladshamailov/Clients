//
// Created by elad on 1/16/17.
//

#include "Packet.h"

#ifndef CLIENTS_LOGRQ_H
#define CLIENTS_LOGRQ_H

#endif //CLIENTS_LOGRQ_H
class LOGRQ : public Packet
{
private:
    std::wstring userName;
public:
    LOGRQ(const std::wstring &userName);
    virtual std::wstring getUserName();
};