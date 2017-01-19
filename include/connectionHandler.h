#ifndef CONNECTION_HANDLER__
#define CONNECTION_HANDLER__

#include <string>
#include <boost/asio.hpp>
#include <iostream>
#include "../include/connectionHandler.h"
#include <packets/LOGRQ.h>
#include <packets/RRQ.h>
#include <packets/ACK.h>
#include <packets/BCAST.h>
#include <packets/ERROR.h>
#include <packets/DATA.h>
#include <packets/DELRQ.h>
#include <packets/DIRQ.h>
#include <packets/DISC.h>
#include <packets/WRQ.h>
#include "MessageEncoderDecoder.h"


using boost::asio::ip::tcp;

class ConnectionHandler {
private:
    const std::string host_;
    const short port_;
    boost::asio::io_service io_service_;   // Provides core I/O functionality
    tcp::socket socket_;

    MessageEncoderDecoder encDec_;

public:
    ConnectionHandler(std::string host, short port, MessageEncoderDecoder encDec);
    virtual ~ConnectionHandler();

    // Connect to the remote machine
    bool connect();

    // Read a fixed number of bytes from the server - blocking.
    // Returns false in case the connection is closed before bytesToRead bytes can be read.
    bool getBytes(char bytes[], unsigned int bytesToRead);

    // Send a fixed number of bytes from the client - blocking.
    // Returns false in case the connection is closed before all the data is sent.
    bool sendBytes(const char bytes[], int bytesToWrite);

    // Read an ascii line from the server
    // Returns false in case connection closed before a newline can be read.
    bool getLine(std::string& line);

    // Send an ascii line from the server
    // Returns false in case connection closed before all the data is sent.
    bool sendLine(std::string& line);

    // Get Ascii data from the server until the delimiter character
    // Returns false in case connection closed before null can be read.
    bool getFrameAscii(std::string& frame, char delimiter);

    // Send a message to the remote host.
    // Returns false in case connection is closed before all the data is sent.
    bool sendFrameAscii(const std::string& frame, char delimiter);

    // Close down the connection properly.
    void close();

    bool send(Packet *pPacket);

    bool getPacket(Packet packet);
}; //class ConnectionHandler

#endif