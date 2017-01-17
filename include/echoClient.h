
#include <packets/Packet.h>
#include "connectionHandler.h"

using std::string;

class echoClient {
private:
    static string trim(const string& str);
public:
    static string checkFunction(string &line);
     Packet* convertStringToPacket(string &line); //TODO:check if need to be static
};
