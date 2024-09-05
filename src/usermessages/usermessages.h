#ifndef _usermessages_manager_h
#define _usermessages_manager_h

#include "../plugins/core/scripting.h"

class UserMessages {
public:
    void Initialize();
    void Destroy();

    void PostEvent(CSplitScreenSlot nSlot, bool bLocalOnly, IRecipientFilter* filter, INetworkMessageInternal* pEvent, const CNetMessage* pData, unsigned long nSize);
};

#endif