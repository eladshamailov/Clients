#include <stdlib.h>
#include <connectionHandler.h>
#include "echoClient.h"
#include <boost/locale.hpp>
#include <thread>
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



void echoClient:: SendOutput()
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
}

void echoClient:: ListenInput()
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
}





