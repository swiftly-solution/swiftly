#ifndef _usermessages_h
#define _usermessages_h

#include "UserMessage.h"
#include <map>
#include <string>

class UserMessages
{
private:
    std::map<uint64_t, UserMessage *> messages;
    uint64_t tracker = 0;

public:
    UserMessages() {}

    uint64_t CreateUserMessage(std::string msgname)
    {
        ++tracker;
        UserMessage *msg = new UserMessage(msgname);
        messages.insert({tracker, msg});
        return tracker;
    }

    UserMessage *GetUserMessage(uint64_t id)
    {
        if (messages.find(id) == messages.end())
            return nullptr;

        return messages.at(id);
    }

    void DeleteUserMessage(uint64_t id)
    {
        if (messages.find(id) == messages.end())
            return;

        UserMessage *msg = messages.at(id);
        delete msg;
        messages.erase(id);
    }
};

extern UserMessages *g_userMessages;

#endif