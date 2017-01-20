//
// Created by elad on 1/16/17.
//

#include "Packet.h"

#ifndef CLIENTS_WRQ_H
#define CLIENTS_WRQ_H


class WRQ : public Packet
{
private:
    string fileName;
public:
    virtual string getFileName();
    WRQ(string fileName);

};

#endif //CLIENTS_WRQ_H