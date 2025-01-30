#ifndef _usermessages_manager_h
#define _usermessages_manager_h

#include "../../plugins/core/scripting.h"

class UserMessages {
public:
    void Initialize();
    void Destroy();

    void PostEvent(CSplitScreenSlot nSlot, bool bLocalOnly, int nClientCount, const uint64 *clients, INetworkMessageInternal* pEvent, const CNetMessage* pData, unsigned long nSize, NetChannelBufType_t bufType);
    bool FilterMessage(const CNetMessage* cMsg, INetChannel* netchan);
};

#endif