#include <stdlib.h>
#include <connectionHandler.h>
#include <packets/Packet.h>
#include <packets/DISC.h>
#include <packets/DIRQ.h>
#include <packets/WRQ.h>
#include <packets/ACK.h>
#include <packets/LOGRQ.h>
#include <packets/DELRQ.h>
#include <packets/RRQ.h>
#include <boost/thread.hpp>
using namespace std;


Packet* convertStringToPacket(string &st){
    string opCode;
    string name;
    int i = 0;
    for (i; (i < st.length()) && (st.at(i) != ' '); i++){
        opCode.push_back(st.at(i));
    }
    for (i++; (i < st.length()) && (st.at(i) != '/0'); i++) {
        name.push_back(st.at(i));
    }
    if(opCode.compare("DIRQ")==0){
        return new DIRQ();
    }
    if(opCode.compare("DISC")==0){
        return new DISC();
    }
    if (opCode.compare("RRQ") == 0) {
        return new RRQ(name);
    }
    else if (opCode.compare("WRQ") == 0) {
        return new WRQ(name);
    }
    else if (opCode.compare("LOGRQ") == 0) {
        return new LOGRQ(name);
    }
    else if (opCode.compare("DELRQ") == 0) {
        return new DELRQ(name);
    }
    else {
        cout << "there is a problem in the string" << endl;
        return nullptr;
    }
}

/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*/
int main (int argc, char *argv[]) {
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

    //create thread keyBoard;
    boost::thread thread2(boost::bind(&ConnectionHandler::run, &connectionHandler));

    //From here we will see the rest of the ehco client implementation:
    while (true) {
        const short bufsize = 1024;
        char buf[bufsize];
        cin.getline(buf, bufsize);
        string line(buf);
        Packet* comment = convertStringToPacket(line);
        if(comment != nullptr){
            if (!connectionHandler.sendPacket(comment)) {
                std::cout << "Disconnected. Exiting...\n" << std::endl;
                break;
            }
            delete comment;
            if(comment->getOpCode() == 10)
                break;
        } else
            std::cout << comment <<endl;
//        int len=line.length();
//        // connectionHandler.sendLine(line) appends '\n' to the message. Therefor we send len+1 bytes.
//        std::cout << "Sent " << len+1 << " bytes to server" << std::endl;
//
//
//        // We can use one of three options to read data from the server:
//        // 1. Read a fixed number of characters
//        // 2. Read a line (up to the newline character using the getline() buffered reader
//        // 3. Read up to the null character
//        std::string answer;
//        // Get back an answer: by using the expected number of bytes (len bytes + newline delimiter)
//        // We could also use: connectionHandler.getline(answer) and then get the answer without the newline char at the end
//        if (!connectionHandler.getLine(answer)) {
//            std::cout << "Disconnected. Exiting...\n" << std::endl;
//            break;
//        }
//
//        len=answer.length();
//        // A C string must end with a 0 char delimiter.  When we filled the answer buffer from the socket
//        // we filled up to the \n char - we must make sure now that a 0 char is also present. So we truncate last character.
//        answer.resize(len-1);
//        std::cout << "Reply: " << answer << " " << len << " bytes " << std::endl << std::endl;
//        if (answer == "bye") {
//            std::cout << "Exiting...\n" << std::endl;
//            break;
//        }
    }

    thread2.join();

    return 0;
}



