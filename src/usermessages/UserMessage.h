#ifndef _usermessage_h
#define _usermessage_h

#include <google/protobuf/message.h>
#include <string>
#include "../common.h"
#include "cstrike15_usermessages.pb.h"
#include "netmessages.pb.h"
#include "usermessages.pb.h"
#include "networkbasetypes.pb.h"
#include "gameevents.pb.h"
#include "clientmessages.pb.h"
#include "te.pb.h"
#include "cs_gameevents.pb.h"
#include "cs_usercmd.pb.h"

#define INVALID_MESSAGE_ID -1

class UserMessage
{
private:
    int msgid = INVALID_MESSAGE_ID;
    google::protobuf::Message *msgBuffer = nullptr;
    INetworkSerializable *msgSerializable = nullptr;

public:
    UserMessage(std::string msgname);
    ~UserMessage()
    {
        this->msgid = INVALID_MESSAGE_ID;
        delete this->msgBuffer;
    }

    bool IsValidMessage() { return (this->msgid == INVALID_MESSAGE_ID); }
    std::string GetMessageName();
    int GetMessageID();
    bool HasField(std::string fieldName);
};

#endif