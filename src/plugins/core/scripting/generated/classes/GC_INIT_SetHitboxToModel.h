class GC_INIT_SetHitboxToModel;

#ifndef _gcc_init_sethitboxtomodel_h
#define _gcc_init_sethitboxtomodel_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_INIT_SetHitboxToModel
{
private:
    void *m_ptr;

public:
    GC_INIT_SetHitboxToModel() {}
    GC_INIT_SetHitboxToModel(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_SetHitboxToModel", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_SetHitboxToModel", "m_nControlPointNumber", false, value); }
    int32_t GetForceInModel() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_SetHitboxToModel", "m_nForceInModel"); }
    void SetForceInModel(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_SetHitboxToModel", "m_nForceInModel", false, value); }
    bool GetEvenDistribution() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_SetHitboxToModel", "m_bEvenDistribution"); }
    void SetEvenDistribution(bool value) { SetSchemaValue(m_ptr, "C_INIT_SetHitboxToModel", "m_bEvenDistribution", false, value); }
    int32_t GetDesiredHitbox() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_SetHitboxToModel", "m_nDesiredHitbox"); }
    void SetDesiredHitbox(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_SetHitboxToModel", "m_nDesiredHitbox", false, value); }
    Vector GetDirectionBias() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_SetHitboxToModel", "m_vecDirectionBias"); }
    void SetDirectionBias(Vector value) { SetSchemaValue(m_ptr, "C_INIT_SetHitboxToModel", "m_vecDirectionBias", false, value); }
    bool GetMaintainHitbox() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_SetHitboxToModel", "m_bMaintainHitbox"); }
    void SetMaintainHitbox(bool value) { SetSchemaValue(m_ptr, "C_INIT_SetHitboxToModel", "m_bMaintainHitbox", false, value); }
    bool GetUseBones() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_SetHitboxToModel", "m_bUseBones"); }
    void SetUseBones(bool value) { SetSchemaValue(m_ptr, "C_INIT_SetHitboxToModel", "m_bUseBones", false, value); }
    std::string GetHitboxSetName() const { return GetSchemaValue<char*>(m_ptr, "C_INIT_SetHitboxToModel", "m_HitboxSetName"); }
    void SetHitboxSetName(std::string value) { SetSchemaValue(m_ptr, "C_INIT_SetHitboxToModel", "m_HitboxSetName", false, value); }
    GCParticleCollectionFloatInput GetShellSize() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_INIT_SetHitboxToModel", "m_flShellSize"); }
    void SetShellSize(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_SetHitboxToModel", "m_flShellSize", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif