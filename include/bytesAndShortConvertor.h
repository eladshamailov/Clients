//
// Created by elad on 1/20/17.
//

#ifndef CLIENTS_BYTESANDSHORTCONVERTOR_H
#define CLIENTS_BYTESANDSHORTCONVERTOR_H


class bytesAndShortConvertor {
public:
    short bytesToShort(char* bytesArr);
    void shortToBytes(short num, char* bytesArr);

    virtual ~bytesAndShortConvertor();
};


#endif //CLIENTS_BYTESANDSHORTCONVERTOR_H
