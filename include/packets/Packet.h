//
// Created by elad on 1/16/17.
//

#ifndef CLIENTS_PACKET_H
#define CLIENTS_PACKET_H

#include <string>

using namespace std;

class Packet{
private:
    short opCode = 0;

public:
    Packet(short opCode);

    virtual short getOpCode();

   virtual ~Packet();
};

#endif //CLIENTS_PACKET_H