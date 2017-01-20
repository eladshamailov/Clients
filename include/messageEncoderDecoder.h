//
// Created by elad on 1/20/17.
//

#ifndef CLIENTS_MESSAGEENCODERDECODER_H
#define CLIENTS_MESSAGEENCODERDECODER_H

#include <vector>
#include <string>
#include <packets/Packet.h>

using namespace std;

class messageEncoderDecoder {
public:
    char* mergeArrays(char *ptr1, int m, char *ptr2, int n,char *connected);
    void encode(Packet *pack, char *answerArr);

    };


#endif //CLIENTS_MESSAGEENCODERDECODER_H
