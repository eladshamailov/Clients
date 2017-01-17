#ifndef CLIENT_CLIENT_H
#define CLIENT_CLIENT_H

#include <packets/Packet.h>
#include "connectionHandler.h"

using std::string;

class echoClient {
private:
    static string trim(const string& str);
public:
    static string checkFunction(string &line);
    static Packet* stringToPacket(string &line);
    void SendOutput();
    void ListenInput();
};

#endif //CLIENT_CLIENT_H