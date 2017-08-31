//
// Created by elad on 1/16/17.
//

#include <packets/Packet.h>

#ifndef CLIENTS_ERROR_H
#define CLIENTS_ERROR_H


class ERROR : public Packet
{
private:
    short errorCode = 0;
    string errorMassage;
public:
    ERROR(short errorCode);

    virtual short getErrorCode();

    int getLength();

    virtual ~ERROR();
};

#endif //CLIENTS_ERROR_H