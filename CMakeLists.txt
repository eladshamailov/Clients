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
        makefile)

add_executable(Clients ${SOURCE_FILES})
TARGET_LINK_LIBRARIES( Clients ${Boost_LIBRARIES} )