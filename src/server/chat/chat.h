#ifndef _chat_processor_h
#define _chat_processor_h

#include <core/entrypoint.h>
#include <utils/utils.h>
#include <map>
#include <string>

class ChatProcessor
{
private:
    std::map<std::string, std::string> placeholders;
public:
    void Initialize();
    void Shutdown();
    void LoadMessages();

    void PostEvent(CSplitScreenSlot nSlot, bool bLocalOnly, int nClientCount, const uint64* clients, INetworkMessageInternal* pEvent, const CNetMessage* pData, unsigned long nSize, NetChannelBufType_t bufType);
};

extern ChatProcessor g_chatProcessor;

#endif