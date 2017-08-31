//
// Created by elad on 1/16/17.
//

#include <packets/Packet.h>

#ifndef CLIENTS_DELRQ_H
#define CLIENTS_DELRQ_H

#endif //CLIENTS_DELRQ_H
class DELRQ : public Packet
{
private:
    string fileName;
public:
    DELRQ(string fileName);
    virtual string getFileName();

    virtual ~DELRQ();
};