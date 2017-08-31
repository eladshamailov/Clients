//
// Created by elad on 1/16/17.
//

#include <packets/Packet.h>

#ifndef CLIENTS_LOGRQ_H
#define CLIENTS_LOGRQ_H

class LOGRQ : public Packet
{
private:
    string userName;
    public:
    LOGRQ(string userName);
    virtual string getUserName();
    int getLength();
public:
    virtual ~LOGRQ();
};


#endif //CLIENTS_LOGRQ_H