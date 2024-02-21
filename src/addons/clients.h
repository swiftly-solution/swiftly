#ifndef _clients_h
#define _clients_h

/**************************************************
 * This feature was taken from https://github.com/Source2ZE/CS2Fixes/commit/98cc65a8a10f03ef8a96003f2e23f74be48284bb
 * Thanks to CS2Fixes for providing this method.
 ***************************************************/

#include "../common.h"
#include "../sdk/entity/serversideclient.h"

struct ClientJoinInfo_t
{
    uint64 steamid;
    double signon_timestamp;
};

extern CUtlVector<ClientJoinInfo_t> g_ClientsPendingAddon;

void AddPendingClient(uint64 steamid);
ClientJoinInfo_t *GetPendingClient(uint64 steamid, int &index);
ClientJoinInfo_t *GetPendingClient(INetChannel *pNetChan);

#endif