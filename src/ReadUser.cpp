//
// Created by nir on 17/01/17.
//

#include <iostream>
#include "ReadUser.h"
#include "../packet/Packet.h"
#include "../packet/ERRORPacket.h"
#include "ListenToServer.h"



ReadUser::ReadUser(const ConnectionHandler &connectionHandler) : connectionHandler(connectionHandler) {
}





void ListenToKeyboard::run(Packet) {

    Packet* packetToSend = createNewPacketFromKeyboard();
    bool success = connectionHandler.send(packetToSend);

}

Packet * ReadUser::createNewPacketFromKeyboard() const {
    const short bufsize = 518;
    char buf[bufsize];
    std::cin.getline(buf, bufsize);
    std::__cxx11::string line(buf);
    std::__cxx11::string comand(line.substr(0, line.find(" ", 0)));
    std::__cxx11::string name(line.substr(line.find("<", 0), line.find(">", 0)));
    int len=line.length();

    Packet *packetToSend = nullptr;

    if(comand.compare("LOGRQ")){
        packetToSend = new LOGRQPacket(name);
    }
    else if(comand.compare("DELRQ")){
        packetToSend = new DELRQPacket(name);
    }
    else if(comand.compare("WRQ")){
        packetToSend = new WRQPacket(name);
    }
    else if(comand.compare("RRQ")){
        packetToSend = new RRQPacket(name);
    }
    else if(comand.compare("DIRQ")){
        packetToSend = new DIRQPacket();
    }
    else if(comand.compare("DISC")){
        packetToSend = new DISCPacket();
    }
    return packetToSend;
}


void ReadUser::setStatus(const std::string &status) {
    ReadUser::status = status;
}

const std::string &ReadUser::getStatus() const {
    return (const std::string &) status;
}

void sendError(ERRORPacket::Errors *errorCode, const std::string &extraMsg)
{
    ERRORPacket tempVar(static_cast<short>(errorCode->ordinal()), errorCode->getErrorMsg() + extraMsg);
    conec send(connectionId, &tempVar);
}