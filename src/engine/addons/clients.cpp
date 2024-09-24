/**************************************************
 * This feature was taken from https://github.com/Source2ZE/CS2Fixes/commit/98cc65a8a10f03ef8a96003f2e23f74be48284bb
 * Thanks to CS2Fixes for providing this method.
 ***************************************************/

#include "clients.h"

CUtlVector<ClientJoinInfo_t> g_ClientsPendingAddon;

void AddPendingClient(uint64 steamid)
{
    ClientJoinInfo_t PendingClient{ steamid, 0.f, 0 };
    g_ClientsPendingAddon.AddToTail(PendingClient);
}

ClientJoinInfo_t* GetPendingClient(uint64 steamid, int& index)
{
    index = 0;

    FOR_EACH_VEC(g_ClientsPendingAddon, i)
    {
        if (g_ClientsPendingAddon[i].steamid == steamid)
        {
            index = i;
            return &g_ClientsPendingAddon[i];
        }
    }

    return nullptr;
}