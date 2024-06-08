class GC_INIT_CreateOnModel;

#ifndef _gcc_init_createonmodel_h
#define _gcc_init_createonmodel_h

#include "../../../scripting.h"


#include "GCParticleModelInput.h"
#include "GCParticleTransformInput.h"
#include "GCParticleCollectionFloatInput.h"

class GC_INIT_CreateOnModel
{
private:
    void *m_ptr;

public:
    GC_INIT_CreateOnModel() {}
    GC_INIT_CreateOnModel(void *ptr) : m_ptr(ptr) {}

    GCParticleModelInput GetModelInput() const { return GetSchemaValue<GCParticleModelInput>(m_ptr, "C_INIT_CreateOnModel", "m_modelInput"); }
    void SetModelInput(GCParticleModelInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModel", "m_modelInput", false, value); }
    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_INIT_CreateOnModel", "m_transformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModel", "m_transformInput", false, value); }
    int32_t GetForceInModel() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_CreateOnModel", "m_nForceInModel"); }
    void SetForceInModel(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModel", "m_nForceInModel", false, value); }
    bool GetScaleToVolume() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateOnModel", "m_bScaleToVolume"); }
    void SetScaleToVolume(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModel", "m_bScaleToVolume", false, value); }
    bool GetEvenDistribution() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateOnModel", "m_bEvenDistribution"); }
    void SetEvenDistribution(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModel", "m_bEvenDistribution", false, value); }
    GCParticleCollectionFloatInput GetDesiredHitbox() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_INIT_CreateOnModel", "m_nDesiredHitbox"); }
    void SetDesiredHitbox(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModel", "m_nDesiredHitbox", false, value); }
    int32_t GetHitboxValueFromControlPointIndex() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_CreateOnModel", "m_nHitboxValueFromControlPointIndex"); }
    void SetHitboxValueFromControlPointIndex(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModel", "m_nHitboxValueFromControlPointIndex", false, value); }
    float GetBoneVelocity() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreateOnModel", "m_flBoneVelocity"); }
    void SetBoneVelocity(float value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModel", "m_flBoneVelocity", false, value); }
    float GetMaxBoneVelocity() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreateOnModel", "m_flMaxBoneVelocity"); }
    void SetMaxBoneVelocity(float value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModel", "m_flMaxBoneVelocity", false, value); }
    std::string GetHitboxSetName() const { return GetSchemaValue<char*>(m_ptr, "C_INIT_CreateOnModel", "m_HitboxSetName"); }
    void SetHitboxSetName(std::string value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModel", "m_HitboxSetName", false, value); }
    bool GetLocalCoords() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateOnModel", "m_bLocalCoords"); }
    void SetLocalCoords(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModel", "m_bLocalCoords", false, value); }
    bool GetUseBones() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateOnModel", "m_bUseBones"); }
    void SetUseBones(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModel", "m_bUseBones", false, value); }
    bool GetUseMesh() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateOnModel", "m_bUseMesh"); }
    void SetUseMesh(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModel", "m_bUseMesh", false, value); }
    GCParticleCollectionFloatInput GetShellSize() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_INIT_CreateOnModel", "m_flShellSize"); }
    void SetShellSize(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModel", "m_flShellSize", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif