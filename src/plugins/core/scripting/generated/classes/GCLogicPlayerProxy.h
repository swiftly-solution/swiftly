class GCLogicPlayerProxy;

#ifndef _gcclogicplayerproxy_h
#define _gcclogicplayerproxy_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"
#include "GCEntityIOOutput.h"

class GCLogicPlayerProxy
{
private:
    void *m_ptr;

public:
    GCLogicPlayerProxy() {}
    GCLogicPlayerProxy(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetPlayer() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CLogicPlayerProxy", "m_hPlayer"); }
    void SetPlayer(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Player' is not possible.\n"); }
    GCEntityIOOutput GetPlayerHasAmmo() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicPlayerProxy", "m_PlayerHasAmmo"); }
    void SetPlayerHasAmmo(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicPlayerProxy", "m_PlayerHasAmmo", false, value); }
    GCEntityIOOutput GetPlayerHasNoAmmo() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicPlayerProxy", "m_PlayerHasNoAmmo"); }
    void SetPlayerHasNoAmmo(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicPlayerProxy", "m_PlayerHasNoAmmo", false, value); }
    GCEntityIOOutput GetPlayerDied() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicPlayerProxy", "m_PlayerDied"); }
    void SetPlayerDied(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicPlayerProxy", "m_PlayerDied", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif