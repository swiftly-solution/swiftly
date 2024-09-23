#ifndef _entity_listener_h
#define _entity_listener_h

#include "../entrypoint.h"
#include "entitysystem.h"
#include "../plugins/core/scripting.h"
#include "../sdk/entity/CGameRules.h"

SH_DECL_EXTERN3_void(INetworkServerService, StartupServer, SH_NOATTRIB, 0, const GameSessionConfiguration_t&, ISource2WorldSession*, const char*);

class EntityListener
{
public:
    void Initialize();
    void Destroy();

    void StartupServer(const GameSessionConfiguration_t& config, ISource2WorldSession*, const char*);
};

#endif