#include <stdlib.h>
#include <connectionHandler.h>
#include "echoClient.h"
#include <boost/locale.hpp>
#include <thread>
#include <boost/core/ref.hpp>
/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*/

echoClient::echoClient(const ConnectionHandler &connection) : connection(connection) {}
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
    cout << "I'm Connected" << endl;
    boost::mutex mutex;
    KeyboardTask task1(connectionHandler, &mutex);
    SocketTask task2(connectionHandler, &mutex);

    boost::thread th1(boost::bind(&KeyboardTask::run, &task1));
    boost::thread th2(boost::bind(&SocketTask::run, &task2));
    th1.join();
    th2.join();

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
        // put the packet to outgoing messages (using lock)
        if (!connection->sendLine(line)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }
        // connectionHandler.sendLine(line) appends '\n' to the message. Therefor we send len+1 bytes.
        std::cout << "Sent " << length+1 << " bytes to server" << std::endl;
    }

    boost::this_thread::yield(); //Gives up the remainder of the current thread's time slice, to allow other threads to run.
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

Packet* echoClient::convertStringToPacket(string &line) {


}





