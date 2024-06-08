class GCEnvBeam;

#ifndef _gccenvbeam_h
#define _gccenvbeam_h

#include "../../../scripting.h"

#include "../types/GTouch_t.h"
#include "GCBaseEntity.h"
#include "GCEntityIOOutput.h"

class GCEnvBeam
{
private:
    void *m_ptr;

public:
    GCEnvBeam() {}
    GCEnvBeam(void *ptr) : m_ptr(ptr) {}

    int32_t GetActive() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvBeam", "m_active"); }
    void SetActive(int32_t value) { SetSchemaValue(m_ptr, "CEnvBeam", "m_active", false, value); }
    CUtlSymbolLarge GetStartEntity() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvBeam", "m_iszStartEntity"); }
    void SetStartEntity(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvBeam", "m_iszStartEntity", false, value); }
    CUtlSymbolLarge GetEndEntity() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvBeam", "m_iszEndEntity"); }
    void SetEndEntity(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvBeam", "m_iszEndEntity", false, value); }
    float GetLife() const { return GetSchemaValue<float>(m_ptr, "CEnvBeam", "m_life"); }
    void SetLife(float value) { SetSchemaValue(m_ptr, "CEnvBeam", "m_life", false, value); }
    float GetBoltWidth() const { return GetSchemaValue<float>(m_ptr, "CEnvBeam", "m_boltWidth"); }
    void SetBoltWidth(float value) { SetSchemaValue(m_ptr, "CEnvBeam", "m_boltWidth", false, value); }
    float GetNoiseAmplitude() const { return GetSchemaValue<float>(m_ptr, "CEnvBeam", "m_noiseAmplitude"); }
    void SetNoiseAmplitude(float value) { SetSchemaValue(m_ptr, "CEnvBeam", "m_noiseAmplitude", false, value); }
    int32_t GetSpeed() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvBeam", "m_speed"); }
    void SetSpeed(int32_t value) { SetSchemaValue(m_ptr, "CEnvBeam", "m_speed", false, value); }
    float GetRestrike() const { return GetSchemaValue<float>(m_ptr, "CEnvBeam", "m_restrike"); }
    void SetRestrike(float value) { SetSchemaValue(m_ptr, "CEnvBeam", "m_restrike", false, value); }
    CUtlSymbolLarge GetSpriteName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvBeam", "m_iszSpriteName"); }
    void SetSpriteName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvBeam", "m_iszSpriteName", false, value); }
    int32_t GetFrameStart() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvBeam", "m_frameStart"); }
    void SetFrameStart(int32_t value) { SetSchemaValue(m_ptr, "CEnvBeam", "m_frameStart", false, value); }
    Vector GetEndPointWorld() const { return GetSchemaValue<Vector>(m_ptr, "CEnvBeam", "m_vEndPointWorld"); }
    void SetEndPointWorld(Vector value) { SetSchemaValue(m_ptr, "CEnvBeam", "m_vEndPointWorld", false, value); }
    Vector GetEndPointRelative() const { return GetSchemaValue<Vector>(m_ptr, "CEnvBeam", "m_vEndPointRelative"); }
    void SetEndPointRelative(Vector value) { SetSchemaValue(m_ptr, "CEnvBeam", "m_vEndPointRelative", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CEnvBeam", "m_radius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CEnvBeam", "m_radius", false, value); }
    Touch_t GetTouchType() const { return GetSchemaValue<Touch_t>(m_ptr, "CEnvBeam", "m_TouchType"); }
    void SetTouchType(Touch_t value) { SetSchemaValue(m_ptr, "CEnvBeam", "m_TouchType", false, value); }
    CUtlSymbolLarge GetFilterName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvBeam", "m_iFilterName"); }
    void SetFilterName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvBeam", "m_iFilterName", false, value); }
    GCBaseEntity* GetFilter() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CEnvBeam", "m_hFilter"); }
    void SetFilter(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Filter' is not possible.\n"); }
    CUtlSymbolLarge GetDecal() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvBeam", "m_iszDecal"); }
    void SetDecal(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvBeam", "m_iszDecal", false, value); }
    GCEntityIOOutput GetOnTouchedByEntity() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CEnvBeam", "m_OnTouchedByEntity"); }
    void SetOnTouchedByEntity(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CEnvBeam", "m_OnTouchedByEntity", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif