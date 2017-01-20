cmake_minimum_required(VERSION 3.6)
project(Clients)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package (Boost 1.53 COMPONENTS system filesystem REQUIRED)
if (Boost_FOUND)
    include_directories (${Boost_INCLUDE_DIR})
endif ()
include_directories(include src)
set(SOURCE_FILES
        include/connectionHandler.h
        src/connectionHandler.cpp
        src/echoClient.cpp
        makefile include/packets/Packet.h src/packets/Packet.cpp include/packets/ACK.h src/packets/ACK.cpp include/packets/DATA.h src/packets/DATA.cpp include/packets/DELRQ.h src/packets/DELRQ.cpp include/packets/BCAST.h src/packets/BCAST.cpp include/packets/DIRQ.h src/packets/DIRQ.cpp include/packets/DISC.h src/packets/DISC.cpp include/packets/ERROR.h src/packets/ERROR.cpp include/packets/LOGRQ.h src/packets/LOGRQ.cpp include/packets/RRQ.h src/packets/RRQ.cpp include/packets/WRQ.h src/packets/WRQ.cpp include/echoClient.h src/messageEncoderDecoder.cpp include/messageEncoderDecoder.h src/bytesAndShortConvertor.cpp include/bytesAndShortConvertor.h)

add_executable(Clients ${SOURCE_FILES})
TARGET_LINK_LIBRARIES( Clients ${Boost_LIBRARIES} )






