class GCPlayerPing;

#ifndef _gccplayerping_h
#define _gccplayerping_h

#include "../../../scripting.h"


#include "GCCSPlayerPawn.h"
#include "GCBaseEntity.h"

class GCPlayerPing
{
private:
    void *m_ptr;

public:
    GCPlayerPing() {}
    GCPlayerPing(void *ptr) : m_ptr(ptr) {}

    GCCSPlayerPawn* GetPlayer() const { return GetSchemaValue<GCCSPlayerPawn*>(m_ptr, "CPlayerPing", "m_hPlayer"); }
    void SetPlayer(GCCSPlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Player' is not possible.\n"); }
    GCBaseEntity* GetPingedEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPlayerPing", "m_hPingedEntity"); }
    void SetPingedEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PingedEntity' is not possible.\n"); }
    int32_t GetType() const { return GetSchemaValue<int32_t>(m_ptr, "CPlayerPing", "m_iType"); }
    void SetType(int32_t value) { SetSchemaValue(m_ptr, "CPlayerPing", "m_iType", false, value); }
    bool GetUrgent() const { return GetSchemaValue<bool>(m_ptr, "CPlayerPing", "m_bUrgent"); }
    void SetUrgent(bool value) { SetSchemaValue(m_ptr, "CPlayerPing", "m_bUrgent", false, value); }
    std::string GetPlaceName() const { return GetSchemaValue<char*>(m_ptr, "CPlayerPing", "m_szPlaceName"); }
    void SetPlaceName(std::string value) { SetSchemaValue(m_ptr, "CPlayerPing", "m_szPlaceName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif