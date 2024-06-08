class GCPhysicsSpring;

#ifndef _gccphysicsspring_h
#define _gccphysicsspring_h

#include "../../../scripting.h"




class GCPhysicsSpring
{
private:
    void *m_ptr;

public:
    GCPhysicsSpring() {}
    GCPhysicsSpring(void *ptr) : m_ptr(ptr) {}

    float GetFrequency() const { return GetSchemaValue<float>(m_ptr, "CPhysicsSpring", "m_flFrequency"); }
    void SetFrequency(float value) { SetSchemaValue(m_ptr, "CPhysicsSpring", "m_flFrequency", false, value); }
    float GetDampingRatio() const { return GetSchemaValue<float>(m_ptr, "CPhysicsSpring", "m_flDampingRatio"); }
    void SetDampingRatio(float value) { SetSchemaValue(m_ptr, "CPhysicsSpring", "m_flDampingRatio", false, value); }
    float GetRestLength() const { return GetSchemaValue<float>(m_ptr, "CPhysicsSpring", "m_flRestLength"); }
    void SetRestLength(float value) { SetSchemaValue(m_ptr, "CPhysicsSpring", "m_flRestLength", false, value); }
    CUtlSymbolLarge GetNameAttachStart() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysicsSpring", "m_nameAttachStart"); }
    void SetNameAttachStart(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPhysicsSpring", "m_nameAttachStart", false, value); }
    CUtlSymbolLarge GetNameAttachEnd() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysicsSpring", "m_nameAttachEnd"); }
    void SetNameAttachEnd(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPhysicsSpring", "m_nameAttachEnd", false, value); }
    Vector GetStart() const { return GetSchemaValue<Vector>(m_ptr, "CPhysicsSpring", "m_start"); }
    void SetStart(Vector value) { SetSchemaValue(m_ptr, "CPhysicsSpring", "m_start", false, value); }
    Vector GetEnd() const { return GetSchemaValue<Vector>(m_ptr, "CPhysicsSpring", "m_end"); }
    void SetEnd(Vector value) { SetSchemaValue(m_ptr, "CPhysicsSpring", "m_end", false, value); }
    uint32_t GetTeleportTick() const { return GetSchemaValue<uint32_t>(m_ptr, "CPhysicsSpring", "m_teleportTick"); }
    void SetTeleportTick(uint32_t value) { SetSchemaValue(m_ptr, "CPhysicsSpring", "m_teleportTick", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif