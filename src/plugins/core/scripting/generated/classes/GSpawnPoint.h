class GSpawnPoint;

#ifndef _gcspawnpoint_h
#define _gcspawnpoint_h

#include "../../../scripting.h"




class GSpawnPoint
{
private:
    void *m_ptr;

public:
    GSpawnPoint() {}
    GSpawnPoint(void *ptr) : m_ptr(ptr) {}

    int32_t GetPriority() const { return GetSchemaValue<int32_t>(m_ptr, "SpawnPoint", "m_iPriority"); }
    void SetPriority(int32_t value) { SetSchemaValue(m_ptr, "SpawnPoint", "m_iPriority", false, value); }
    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "SpawnPoint", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "SpawnPoint", "m_bEnabled", false, value); }
    int32_t GetType() const { return GetSchemaValue<int32_t>(m_ptr, "SpawnPoint", "m_nType"); }
    void SetType(int32_t value) { SetSchemaValue(m_ptr, "SpawnPoint", "m_nType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif