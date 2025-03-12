#ifndef _chat_processor_h
#define _chat_processor_h

#include "../../plugins/core/scripting.h"
#include "public/icvar.h"
#include "../../utils/utils.h"
#include <map>
#include <string>

bool OnClientChat(int playerid, std::string text, bool teamonly);

class ChatProcessor
{
private:
    std::map<std::string, std::string> placeholders;
public:
    ChatProcessor() {}
    void Initialize();
    void Destroy();
    void LoadMessages();

    void PostEvent(CSplitScreenSlot nSlot, bool bLocalOnly, int nClientCount, const uint64 *clients, INetworkMessageInternal* pEvent, const CNetMessage* pData, unsigned long nSize, NetChannelBufType_t bufType);
    void DispatchConCommand(ConCommandRef cmd, const CCommandContext& ctx, const CCommand& args);
};

extern ChatProcessor *g_chatProcessor;

#endif