class GCSoundOpvarSetPointEntity;

#ifndef _gccsoundopvarsetpointentity_h
#define _gccsoundopvarsetpointentity_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"
#include "GCEntityInstance.h"

class GCSoundOpvarSetPointEntity
{
private:
    void *m_ptr;

public:
    GCSoundOpvarSetPointEntity() {}
    GCSoundOpvarSetPointEntity(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnEnter() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CSoundOpvarSetPointEntity", "m_OnEnter"); }
    void SetOnEnter(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_OnEnter", false, value); }
    GCEntityIOOutput GetOnExit() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CSoundOpvarSetPointEntity", "m_OnExit"); }
    void SetOnExit(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_OnExit", false, value); }
    bool GetAutoDisable() const { return GetSchemaValue<bool>(m_ptr, "CSoundOpvarSetPointEntity", "m_bAutoDisable"); }
    void SetAutoDisable(bool value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_bAutoDisable", false, value); }
    float GetDistanceMin() const { return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPointEntity", "m_flDistanceMin"); }
    void SetDistanceMin(float value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_flDistanceMin", false, value); }
    float GetDistanceMax() const { return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPointEntity", "m_flDistanceMax"); }
    void SetDistanceMax(float value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_flDistanceMax", false, value); }
    float GetDistanceMapMin() const { return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPointEntity", "m_flDistanceMapMin"); }
    void SetDistanceMapMin(float value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_flDistanceMapMin", false, value); }
    float GetDistanceMapMax() const { return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPointEntity", "m_flDistanceMapMax"); }
    void SetDistanceMapMax(float value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_flDistanceMapMax", false, value); }
    float GetOcclusionRadius() const { return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPointEntity", "m_flOcclusionRadius"); }
    void SetOcclusionRadius(float value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_flOcclusionRadius", false, value); }
    float GetOcclusionMin() const { return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPointEntity", "m_flOcclusionMin"); }
    void SetOcclusionMin(float value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_flOcclusionMin", false, value); }
    float GetOcclusionMax() const { return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPointEntity", "m_flOcclusionMax"); }
    void SetOcclusionMax(float value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_flOcclusionMax", false, value); }
    float GetValSetOnDisable() const { return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPointEntity", "m_flValSetOnDisable"); }
    void SetValSetOnDisable(float value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_flValSetOnDisable", false, value); }
    bool GetSetValueOnDisable() const { return GetSchemaValue<bool>(m_ptr, "CSoundOpvarSetPointEntity", "m_bSetValueOnDisable"); }
    void SetSetValueOnDisable(bool value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_bSetValueOnDisable", false, value); }
    int32_t GetSimulationMode() const { return GetSchemaValue<int32_t>(m_ptr, "CSoundOpvarSetPointEntity", "m_nSimulationMode"); }
    void SetSimulationMode(int32_t value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_nSimulationMode", false, value); }
    int32_t GetVisibilitySamples() const { return GetSchemaValue<int32_t>(m_ptr, "CSoundOpvarSetPointEntity", "m_nVisibilitySamples"); }
    void SetVisibilitySamples(int32_t value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_nVisibilitySamples", false, value); }
    Vector GetDynamicProxyPoint() const { return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetPointEntity", "m_vDynamicProxyPoint"); }
    void SetDynamicProxyPoint(Vector value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_vDynamicProxyPoint", false, value); }
    float GetDynamicMaximumOcclusion() const { return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPointEntity", "m_flDynamicMaximumOcclusion"); }
    void SetDynamicMaximumOcclusion(float value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_flDynamicMaximumOcclusion", false, value); }
    GCEntityInstance* GetDynamicEntity() const { return GetSchemaValue<GCEntityInstance*>(m_ptr, "CSoundOpvarSetPointEntity", "m_hDynamicEntity"); }
    void SetDynamicEntity(GCEntityInstance* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'DynamicEntity' is not possible.\n"); }
    CUtlSymbolLarge GetDynamicEntityName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundOpvarSetPointEntity", "m_iszDynamicEntityName"); }
    void SetDynamicEntityName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_iszDynamicEntityName", false, value); }
    float GetPathingDistanceNormFactor() const { return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPointEntity", "m_flPathingDistanceNormFactor"); }
    void SetPathingDistanceNormFactor(float value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_flPathingDistanceNormFactor", false, value); }
    Vector GetPathingSourcePos() const { return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetPointEntity", "m_vPathingSourcePos"); }
    void SetPathingSourcePos(Vector value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_vPathingSourcePos", false, value); }
    Vector GetPathingListenerPos() const { return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetPointEntity", "m_vPathingListenerPos"); }
    void SetPathingListenerPos(Vector value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_vPathingListenerPos", false, value); }
    Vector GetPathingDirection() const { return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetPointEntity", "m_vPathingDirection"); }
    void SetPathingDirection(Vector value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_vPathingDirection", false, value); }
    int32_t GetPathingSourceIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CSoundOpvarSetPointEntity", "m_nPathingSourceIndex"); }
    void SetPathingSourceIndex(int32_t value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointEntity", "m_nPathingSourceIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif