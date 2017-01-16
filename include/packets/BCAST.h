//
// Created by elad on 1/16/17.
//

#include "Packet.h"

#ifndef CLIENTS_BCAST_H
#define CLIENTS_BCAST_H

#endif //CLIENTS_BCAST_H
class BCAST : public Packet
{
private:
    string fileName;
    char deletedOrAdded = 0;
public:
    BCAST(string fileName, char deletedOrAdded);
    virtual string getFileName();

    virtual char isDeletedOrAdded();
};