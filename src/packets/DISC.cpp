//
// Created by elad on 1/16/17.
//

#include <packets/Packet.h>
#include <packets/DISC.h>

DISC::DISC() : Packet((short)10)
{
}

int DISC::getLength(){
    return 2;
}

DISC::~DISC() {

}
