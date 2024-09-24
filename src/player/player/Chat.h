#ifndef _player_chat_h
#define _player_chat_h

#include "../../plugins/core/scripting.h"
#include "public/icvar.h"
#include "../../utils/utils.h"

bool OnClientChat(int playerid, std::string text, bool teamonly);

class PlayerChat
{
public:
    void Initialize();
    void Destroy();

    void PostEvent(CSplitScreenSlot nSlot, bool bLocalOnly, int nClientCount, const uint64 *clients, INetworkMessageInternal* pEvent, const CNetMessage* pData, unsigned long nSize, NetChannelBufType_t bufType);
    void DispatchConCommand(ConCommandHandle cmd, const CCommandContext& ctx, const CCommand& args);
};

#endif