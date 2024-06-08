class GCPhysConstraint;

#ifndef _gccphysconstraint_h
#define _gccphysconstraint_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"
#include "GCEntityIOOutput.h"

class GCPhysConstraint
{
private:
    void *m_ptr;

public:
    GCPhysConstraint() {}
    GCPhysConstraint(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetNameAttach1() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysConstraint", "m_nameAttach1"); }
    void SetNameAttach1(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPhysConstraint", "m_nameAttach1", false, value); }
    CUtlSymbolLarge GetNameAttach2() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysConstraint", "m_nameAttach2"); }
    void SetNameAttach2(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPhysConstraint", "m_nameAttach2", false, value); }
    GCBaseEntity* GetAttach1() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPhysConstraint", "m_hAttach1"); }
    void SetAttach1(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Attach1' is not possible.\n"); }
    GCBaseEntity* GetAttach2() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPhysConstraint", "m_hAttach2"); }
    void SetAttach2(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Attach2' is not possible.\n"); }
    CUtlSymbolLarge GetNameAttachment1() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysConstraint", "m_nameAttachment1"); }
    void SetNameAttachment1(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPhysConstraint", "m_nameAttachment1", false, value); }
    CUtlSymbolLarge GetNameAttachment2() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysConstraint", "m_nameAttachment2"); }
    void SetNameAttachment2(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPhysConstraint", "m_nameAttachment2", false, value); }
    CUtlSymbolLarge GetBreakSound() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysConstraint", "m_breakSound"); }
    void SetBreakSound(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPhysConstraint", "m_breakSound", false, value); }
    float GetForceLimit() const { return GetSchemaValue<float>(m_ptr, "CPhysConstraint", "m_forceLimit"); }
    void SetForceLimit(float value) { SetSchemaValue(m_ptr, "CPhysConstraint", "m_forceLimit", false, value); }
    float GetTorqueLimit() const { return GetSchemaValue<float>(m_ptr, "CPhysConstraint", "m_torqueLimit"); }
    void SetTorqueLimit(float value) { SetSchemaValue(m_ptr, "CPhysConstraint", "m_torqueLimit", false, value); }
    uint32_t GetTeleportTick() const { return GetSchemaValue<uint32_t>(m_ptr, "CPhysConstraint", "m_teleportTick"); }
    void SetTeleportTick(uint32_t value) { SetSchemaValue(m_ptr, "CPhysConstraint", "m_teleportTick", false, value); }
    float GetMinTeleportDistance() const { return GetSchemaValue<float>(m_ptr, "CPhysConstraint", "m_minTeleportDistance"); }
    void SetMinTeleportDistance(float value) { SetSchemaValue(m_ptr, "CPhysConstraint", "m_minTeleportDistance", false, value); }
    bool GetSnapObjectPositions() const { return GetSchemaValue<bool>(m_ptr, "CPhysConstraint", "m_bSnapObjectPositions"); }
    void SetSnapObjectPositions(bool value) { SetSchemaValue(m_ptr, "CPhysConstraint", "m_bSnapObjectPositions", false, value); }
    GCEntityIOOutput GetOnBreak() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPhysConstraint", "m_OnBreak"); }
    void SetOnBreak(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPhysConstraint", "m_OnBreak", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif