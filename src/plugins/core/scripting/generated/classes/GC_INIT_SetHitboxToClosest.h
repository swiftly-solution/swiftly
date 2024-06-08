class GC_INIT_SetHitboxToClosest;

#ifndef _gcc_init_sethitboxtoclosest_h
#define _gcc_init_sethitboxtoclosest_h

#include "../../../scripting.h"

#include "../types/GClosestPointTestType_t.h"
#include "GCParticleCollectionFloatInput.h"

class GC_INIT_SetHitboxToClosest
{
private:
    void *m_ptr;

public:
    GC_INIT_SetHitboxToClosest() {}
    GC_INIT_SetHitboxToClosest(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_SetHitboxToClosest", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_SetHitboxToClosest", "m_nControlPointNumber", false, value); }
    int32_t GetDesiredHitbox() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_SetHitboxToClosest", "m_nDesiredHitbox"); }
    void SetDesiredHitbox(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_SetHitboxToClosest", "m_nDesiredHitbox", false, value); }
    std::string GetHitboxSetName() const { return GetSchemaValue<char*>(m_ptr, "C_INIT_SetHitboxToClosest", "m_HitboxSetName"); }
    void SetHitboxSetName(std::string value) { SetSchemaValue(m_ptr, "C_INIT_SetHitboxToClosest", "m_HitboxSetName", false, value); }
    bool GetUseBones() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_SetHitboxToClosest", "m_bUseBones"); }
    void SetUseBones(bool value) { SetSchemaValue(m_ptr, "C_INIT_SetHitboxToClosest", "m_bUseBones", false, value); }
    bool GetUseClosestPointOnHitbox() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_SetHitboxToClosest", "m_bUseClosestPointOnHitbox"); }
    void SetUseClosestPointOnHitbox(bool value) { SetSchemaValue(m_ptr, "C_INIT_SetHitboxToClosest", "m_bUseClosestPointOnHitbox", false, value); }
    ClosestPointTestType_t GetTestType() const { return GetSchemaValue<ClosestPointTestType_t>(m_ptr, "C_INIT_SetHitboxToClosest", "m_nTestType"); }
    void SetTestType(ClosestPointTestType_t value) { SetSchemaValue(m_ptr, "C_INIT_SetHitboxToClosest", "m_nTestType", false, value); }
    GCParticleCollectionFloatInput GetHybridRatio() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_INIT_SetHitboxToClosest", "m_flHybridRatio"); }
    void SetHybridRatio(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_SetHitboxToClosest", "m_flHybridRatio", false, value); }
    bool GetUpdatePosition() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_SetHitboxToClosest", "m_bUpdatePosition"); }
    void SetUpdatePosition(bool value) { SetSchemaValue(m_ptr, "C_INIT_SetHitboxToClosest", "m_bUpdatePosition", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif