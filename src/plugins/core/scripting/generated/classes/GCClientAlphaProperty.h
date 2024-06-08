class GCClientAlphaProperty;

#ifndef _gccclientalphaproperty_h
#define _gccclientalphaproperty_h

#include "../../../scripting.h"




class GCClientAlphaProperty
{
private:
    void *m_ptr;

public:
    GCClientAlphaProperty() {}
    GCClientAlphaProperty(void *ptr) : m_ptr(ptr) {}

    uint8_t GetRenderFX() const { return GetSchemaValue<uint8_t>(m_ptr, "CClientAlphaProperty", "m_nRenderFX"); }
    void SetRenderFX(uint8_t value) { SetSchemaValue(m_ptr, "CClientAlphaProperty", "m_nRenderFX", false, value); }
    uint8_t GetRenderMode() const { return GetSchemaValue<uint8_t>(m_ptr, "CClientAlphaProperty", "m_nRenderMode"); }
    void SetRenderMode(uint8_t value) { SetSchemaValue(m_ptr, "CClientAlphaProperty", "m_nRenderMode", false, value); }
    uint8_t GetAlpha() const { return GetSchemaValue<uint8_t>(m_ptr, "CClientAlphaProperty", "m_nAlpha"); }
    void SetAlpha(uint8_t value) { SetSchemaValue(m_ptr, "CClientAlphaProperty", "m_nAlpha", false, value); }
    uint16_t GetDesyncOffset() const { return GetSchemaValue<uint16_t>(m_ptr, "CClientAlphaProperty", "m_nDesyncOffset"); }
    void SetDesyncOffset(uint16_t value) { SetSchemaValue(m_ptr, "CClientAlphaProperty", "m_nDesyncOffset", false, value); }
    uint16_t GetReserved2() const { return GetSchemaValue<uint16_t>(m_ptr, "CClientAlphaProperty", "m_nReserved2"); }
    void SetReserved2(uint16_t value) { SetSchemaValue(m_ptr, "CClientAlphaProperty", "m_nReserved2", false, value); }
    uint16_t GetDistFadeStart() const { return GetSchemaValue<uint16_t>(m_ptr, "CClientAlphaProperty", "m_nDistFadeStart"); }
    void SetDistFadeStart(uint16_t value) { SetSchemaValue(m_ptr, "CClientAlphaProperty", "m_nDistFadeStart", false, value); }
    uint16_t GetDistFadeEnd() const { return GetSchemaValue<uint16_t>(m_ptr, "CClientAlphaProperty", "m_nDistFadeEnd"); }
    void SetDistFadeEnd(uint16_t value) { SetSchemaValue(m_ptr, "CClientAlphaProperty", "m_nDistFadeEnd", false, value); }
    float GetFadeScale() const { return GetSchemaValue<float>(m_ptr, "CClientAlphaProperty", "m_flFadeScale"); }
    void SetFadeScale(float value) { SetSchemaValue(m_ptr, "CClientAlphaProperty", "m_flFadeScale", false, value); }
    float GetRenderFxDuration() const { return GetSchemaValue<float>(m_ptr, "CClientAlphaProperty", "m_flRenderFxDuration"); }
    void SetRenderFxDuration(float value) { SetSchemaValue(m_ptr, "CClientAlphaProperty", "m_flRenderFxDuration", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif