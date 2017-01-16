//
// Created by elad on 1/16/17.
//

#include <packets/Packet.h>
#include <packets/ERROR.h>

ERROR::ERROR(short errorCode) : Packet((short)5)
{
    this->errorCode = errorCode;
    switch (errorCode)
    {
        case 0:
        {
            this->errorMassage = L"Not defined, see error message (if any).";
            break;
        }
        case 1:
        {
            this->errorMassage = L"File not found–RRQ\\DELRQ of non-existing file";
            break;
        }
        case 2:
        {
            this->errorMassage = L"Access violation–File cannot be written, read or deleted.";
            break;
        }
        case 3:
        {
            this->errorMassage = L"Access violation–File cannot be written, read or deleted.Disk full or allocation exceeded–No room in disk.";
            break;
        }
        case 4:
        {
            this->errorMassage = L"Illegal TFTP operation–Unknown Opcode.";
            break;
        }
        case 5:
        {
            this->errorMassage = L"File already exists–File name exists on WRQ.";
            break;
        }
        case 6:
        {
            this->errorMassage = L"User not logged in–Any opcode received before Login completes.";
            break;
        }
        case 7:
        {
            this->errorMassage = L"User already logged in–Login usernamealready connected.";
            break;
        }
        default:
        {
            this->errorMassage = L"Not defined, see error message (if any).";
            break;
        }
    }
}

short ERROR::getErrorCode()
{
    return errorCode;
}

std::wstring ERROR::getErrorMessage()
{
    return errorMassage;
}
}