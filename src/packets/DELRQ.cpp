//
// Created by elad on 1/16/17.
//

#include <packets/Packet.h>
#include <packets/DELRQ.h>

DELRQ::DELRQ(string fileName) : Packet((short)8),fileName(fileName){}

string DELRQ::getFileName()
{
    return fileName;
}

DELRQ::~DELRQ() {

}
