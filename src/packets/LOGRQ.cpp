//
// Created by elad on 1/16/17.
//

#include <packets/Packet.h>
#include <packets/LOGRQ.h>

LOGRQ::LOGRQ(string userName) : Packet((short)7),userName(userName){}

string LOGRQ::getUserName()
{
    return userName;
}

int LOGRQ::getLength() {
    return userName.length();
}



