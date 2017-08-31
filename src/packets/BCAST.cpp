//
// Created by elad on 1/16/17.
//

#include <packets/Packet.h>
#include <packets/BCAST.h>

BCAST::BCAST(string fileName, char deletedOrAdded) : Packet((short)9),fileName(fileName),deletedOrAdded(deletedOrAdded){}



BCAST::~BCAST() {

}
