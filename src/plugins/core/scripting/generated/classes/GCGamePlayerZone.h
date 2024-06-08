class GCGamePlayerZone;

#ifndef _gccgameplayerzone_h
#define _gccgameplayerzone_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCGamePlayerZone
{
private:
    void *m_ptr;

public:
    GCGamePlayerZone() {}
    GCGamePlayerZone(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnPlayerInZone() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CGamePlayerZone", "m_OnPlayerInZone"); }
    void SetOnPlayerInZone(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CGamePlayerZone", "m_OnPlayerInZone", false, value); }
    GCEntityIOOutput GetOnPlayerOutZone() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CGamePlayerZone", "m_OnPlayerOutZone"); }
    void SetOnPlayerOutZone(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CGamePlayerZone", "m_OnPlayerOutZone", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif