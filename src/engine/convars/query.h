#ifndef _engine_convars_query_h
#define _engine_convars_query_h

#include <core/entrypoint.h>
#include "netmessages.pb.h"


class CvarQuery
{
public:
    void Initialize();
    void Shutdown();

    bool OnConvarQuery(const CNetMessagePB<CCLCMsg_RespondCvarValue>& msg);

    void QueryCvarClient(CPlayerSlot slot, std::string cvarName);
};

extern CvarQuery g_convarQuery;

#endif