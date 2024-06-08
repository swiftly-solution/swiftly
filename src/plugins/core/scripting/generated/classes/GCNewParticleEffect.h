class GCNewParticleEffect;

#ifndef _gccnewparticleeffect_h
#define _gccnewparticleeffect_h

#include "../../../scripting.h"


#include "GCNewParticleEffect.h"
#include "GIParticleCollection.h"
#include "GPARTICLE_EHANDLE__.h"
#include "GCParticleProperty.h"

class GCNewParticleEffect
{
private:
    void *m_ptr;

public:
    GCNewParticleEffect() {}
    GCNewParticleEffect(void *ptr) : m_ptr(ptr) {}

    GCNewParticleEffect* GetNext() const { return GetSchemaValue<GCNewParticleEffect*>(m_ptr, "CNewParticleEffect", "m_pNext"); }
    void SetNext(GCNewParticleEffect* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Next' is not possible.\n"); }
    GCNewParticleEffect* GetPrev() const { return GetSchemaValue<GCNewParticleEffect*>(m_ptr, "CNewParticleEffect", "m_pPrev"); }
    void SetPrev(GCNewParticleEffect* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Prev' is not possible.\n"); }
    GIParticleCollection* GetParticles() const { return GetSchemaValue<GIParticleCollection*>(m_ptr, "CNewParticleEffect", "m_pParticles"); }
    void SetParticles(GIParticleCollection* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Particles' is not possible.\n"); }
    std::string GetDebugName() const { return GetSchemaValue<char*>(m_ptr, "CNewParticleEffect", "m_pDebugName"); }
    void SetDebugName(std::string value) { WriteSchemaPtrValue(m_ptr, "CNewParticleEffect", "m_pDebugName", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size()); }
    Vector GetSortOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CNewParticleEffect", "m_vSortOrigin"); }
    void SetSortOrigin(Vector value) { SetSchemaValue(m_ptr, "CNewParticleEffect", "m_vSortOrigin", false, value); }
    float GetScale() const { return GetSchemaValue<float>(m_ptr, "CNewParticleEffect", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "CNewParticleEffect", "m_flScale", false, value); }
    GPARTICLE_EHANDLE__* GetOwner() const { return GetSchemaValue<GPARTICLE_EHANDLE__*>(m_ptr, "CNewParticleEffect", "m_hOwner"); }
    void SetOwner(GPARTICLE_EHANDLE__* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Owner' is not possible.\n"); }
    GCParticleProperty* GetOwningParticleProperty() const { return GetSchemaValue<GCParticleProperty*>(m_ptr, "CNewParticleEffect", "m_pOwningParticleProperty"); }
    void SetOwningParticleProperty(GCParticleProperty* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'OwningParticleProperty' is not possible.\n"); }
    float GetFreezeTransitionStart() const { return GetSchemaValue<float>(m_ptr, "CNewParticleEffect", "m_flFreezeTransitionStart"); }
    void SetFreezeTransitionStart(float value) { SetSchemaValue(m_ptr, "CNewParticleEffect", "m_flFreezeTransitionStart", false, value); }
    float GetFreezeTransitionDuration() const { return GetSchemaValue<float>(m_ptr, "CNewParticleEffect", "m_flFreezeTransitionDuration"); }
    void SetFreezeTransitionDuration(float value) { SetSchemaValue(m_ptr, "CNewParticleEffect", "m_flFreezeTransitionDuration", false, value); }
    float GetFreezeTransitionOverride() const { return GetSchemaValue<float>(m_ptr, "CNewParticleEffect", "m_flFreezeTransitionOverride"); }
    void SetFreezeTransitionOverride(float value) { SetSchemaValue(m_ptr, "CNewParticleEffect", "m_flFreezeTransitionOverride", false, value); }
    bool GetFreezeTransitionActive() const { return GetSchemaValue<bool>(m_ptr, "CNewParticleEffect", "m_bFreezeTransitionActive"); }
    void SetFreezeTransitionActive(bool value) { SetSchemaValue(m_ptr, "CNewParticleEffect", "m_bFreezeTransitionActive", false, value); }
    bool GetFreezeTargetState() const { return GetSchemaValue<bool>(m_ptr, "CNewParticleEffect", "m_bFreezeTargetState"); }
    void SetFreezeTargetState(bool value) { SetSchemaValue(m_ptr, "CNewParticleEffect", "m_bFreezeTargetState", false, value); }
    bool GetCanFreeze() const { return GetSchemaValue<bool>(m_ptr, "CNewParticleEffect", "m_bCanFreeze"); }
    void SetCanFreeze(bool value) { SetSchemaValue(m_ptr, "CNewParticleEffect", "m_bCanFreeze", false, value); }
    Vector GetLastMin() const { return GetSchemaValue<Vector>(m_ptr, "CNewParticleEffect", "m_LastMin"); }
    void SetLastMin(Vector value) { SetSchemaValue(m_ptr, "CNewParticleEffect", "m_LastMin", false, value); }
    Vector GetLastMax() const { return GetSchemaValue<Vector>(m_ptr, "CNewParticleEffect", "m_LastMax"); }
    void SetLastMax(Vector value) { SetSchemaValue(m_ptr, "CNewParticleEffect", "m_LastMax", false, value); }
    int32_t GetSplitScreenUser() const { return GetSchemaValue<int32_t>(m_ptr, "CNewParticleEffect", "m_nSplitScreenUser"); }
    void SetSplitScreenUser(int32_t value) { SetSchemaValue(m_ptr, "CNewParticleEffect", "m_nSplitScreenUser", false, value); }
    Vector GetAggregationCenter() const { return GetSchemaValue<Vector>(m_ptr, "CNewParticleEffect", "m_vecAggregationCenter"); }
    void SetAggregationCenter(Vector value) { SetSchemaValue(m_ptr, "CNewParticleEffect", "m_vecAggregationCenter", false, value); }
    int32_t GetRefCount() const { return GetSchemaValue<int32_t>(m_ptr, "CNewParticleEffect", "m_RefCount"); }
    void SetRefCount(int32_t value) { SetSchemaValue(m_ptr, "CNewParticleEffect", "m_RefCount", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif