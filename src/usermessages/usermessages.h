#ifndef _usermessages_manager_h
#define _usermessages_manager_h

#include "../plugins/core/scripting.h"

int FindClientByNetChannel(INetChannel* pNetChan);
bool UserMessages_SendNetMessage(INetChannel* pNetChan, CNetMessage* pData, int a4);

#endif