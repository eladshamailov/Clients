//
// Created by elad on 1/16/17.
//

#include <packets/Packet.h>
#include <packets/BCAST.h>

BCAST::BCAST(string fileName, char deletedOrAdded) : Packet((short)9)
{
    this->fileName = fileName;
    this->deletedOrAdded = deletedOrAdded;
}

string BCAST::getFileName() {
    this->fileName;
}

char BCAST::isDeletedOrAdded()
{
    return deletedOrAdded;
}