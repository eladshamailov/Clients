#include <stdlib.h>
#include <connectionHandler.h>
#include "echoClient.h"
#include <boost/locale.hpp>
#include <thread>
#include <packets/ACK.h>
#include <packets/RRQ.h>
#include <packets/WRQ.h>
#include <packets/DIRQ.h>
#include <packets/LOGRQ.h>
#include <packets/DELRQ.h>
#include <packets/DISC.h>

/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*/

ConnectionHandler connection;
bool running = true;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " host port" << std::endl << std::endl;
        return -1;
    }
    std::string host = argv[1];
    short port = atoi(argv[2]);

    ConnectionHandler connectionHandler(host, port);
    if (!connectionHandler.connect()) {
        std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
        return 1;
    }


    std::thread t1(SendOutput);
    std::thread t2(ListenInput);
    t1.join();
    t2.join();

    return 0;
}



void *SendOutput()
{
    while (running) {
        const short bufferSize = 1<<10;
        char buffer[bufferSize];
        cin.getline(buffer, bufferSize);
        string line(buffer);
        int length=line.length();
        if (!connection.sendLine(line)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            running = false;
            break;
        }
        if (line == "QUIT") {
            std::cout << "Exiting...\n" << std::endl;
            running = false;
            break;
        }
    }
    return NULL;
}

void *ListenInput()
{
    while (running) {
        std::string answer;
        int len;
        if (!connection.getLine(answer)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            running = false;
            break;
        }

        len=answer.length();
        // A C string must end with a 0 char delimiter.  When we filled the answer buffer from the socket
        // we filled up to the \n char - we must make sure now that a 0 char is also present. So we truncate last character.
        answer.resize(len-1);
        std::cout <<  answer << " "  <<  std::endl << std::endl;

    }
    connection.close();
    return NULL;
}

int echoClient::stringToOpCode(string &line) {
    if(line.compare("RRQ")==0)
        return 1;
    else if(line.compare("WRQ")==0)
        return 2;
    else if (line.compare("DATA")==0)
        return 3;
    else if (line.compare("ACK")==0)
        return 4;
    else if(line.compare("ERROR")==0)
        return 5;
    else if(line.compare("DIRQ")==0)
        return 6;
    else if(line.compare("LOGRQ")==0)
        return 7;
    else if(line.compare("DELRQ")==0)
        return 8;
    else if(line.compare("BCAST")==0)
        return 9;
    else if(line.compare("DISC")==0)
        return 10;
    else
        return 0;
}

Packet echoClient::convertStringToPacket(string &line) {
    string type=line.substr(0,line.find(" "));
    int tmpOpCode=stringToOpCode(type);
    string toSend=line.substr(line.find(" "),line.length()-1);
    switch (tmpOpCode){
        case 1:{
            RRQ ans(toSend);
            return ans;
        }
        case 2:{
            WRQ ans(toSend);
            return ans;
        }
        case 4:{
            ACK ans((short)stoi(toSend));
            return ans;
        }
        case 6:{
            DIRQ ans;
            return ans;
        }
        case 7: {
            LOGRQ ans(toSend);
            return ans;
        }
        case 8:{
            DELRQ ans(toSend);
            return ans;
        }
        case 10:{
            DISC ans;
            return ans;
        }

    }
}