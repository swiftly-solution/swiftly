class GCDynamicLight;

#ifndef _gccdynamiclight_h
#define _gccdynamiclight_h

#include "../../../scripting.h"




class GCDynamicLight
{
private:
    void *m_ptr;

public:
    GCDynamicLight() {}
    GCDynamicLight(void *ptr) : m_ptr(ptr) {}

    uint8_t GetActualFlags() const { return GetSchemaValue<uint8_t>(m_ptr, "CDynamicLight", "m_ActualFlags"); }
    void SetActualFlags(uint8_t value) { SetSchemaValue(m_ptr, "CDynamicLight", "m_ActualFlags", false, value); }
    uint8_t GetFlags() const { return GetSchemaValue<uint8_t>(m_ptr, "CDynamicLight", "m_Flags"); }
    void SetFlags(uint8_t value) { SetSchemaValue(m_ptr, "CDynamicLight", "m_Flags", false, value); }
    uint8_t GetLightStyle() const { return GetSchemaValue<uint8_t>(m_ptr, "CDynamicLight", "m_LightStyle"); }
    void SetLightStyle(uint8_t value) { SetSchemaValue(m_ptr, "CDynamicLight", "m_LightStyle", false, value); }
    bool GetOn() const { return GetSchemaValue<bool>(m_ptr, "CDynamicLight", "m_On"); }
    void SetOn(bool value) { SetSchemaValue(m_ptr, "CDynamicLight", "m_On", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CDynamicLight", "m_Radius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CDynamicLight", "m_Radius", false, value); }
    int32_t GetExponent() const { return GetSchemaValue<int32_t>(m_ptr, "CDynamicLight", "m_Exponent"); }
    void SetExponent(int32_t value) { SetSchemaValue(m_ptr, "CDynamicLight", "m_Exponent", false, value); }
    float GetInnerAngle() const { return GetSchemaValue<float>(m_ptr, "CDynamicLight", "m_InnerAngle"); }
    void SetInnerAngle(float value) { SetSchemaValue(m_ptr, "CDynamicLight", "m_InnerAngle", false, value); }
    float GetOuterAngle() const { return GetSchemaValue<float>(m_ptr, "CDynamicLight", "m_OuterAngle"); }
    void SetOuterAngle(float value) { SetSchemaValue(m_ptr, "CDynamicLight", "m_OuterAngle", false, value); }
    float GetSpotRadius() const { return GetSchemaValue<float>(m_ptr, "CDynamicLight", "m_SpotRadius"); }
    void SetSpotRadius(float value) { SetSchemaValue(m_ptr, "CDynamicLight", "m_SpotRadius", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif