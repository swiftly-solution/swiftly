class GCOmniLight;

#ifndef _gccomnilight_h
#define _gccomnilight_h

#include "../../../scripting.h"




class GCOmniLight
{
private:
    void *m_ptr;

public:
    GCOmniLight() {}
    GCOmniLight(void *ptr) : m_ptr(ptr) {}

    float GetInnerAngle() const { return GetSchemaValue<float>(m_ptr, "COmniLight", "m_flInnerAngle"); }
    void SetInnerAngle(float value) { SetSchemaValue(m_ptr, "COmniLight", "m_flInnerAngle", false, value); }
    float GetOuterAngle() const { return GetSchemaValue<float>(m_ptr, "COmniLight", "m_flOuterAngle"); }
    void SetOuterAngle(float value) { SetSchemaValue(m_ptr, "COmniLight", "m_flOuterAngle", false, value); }
    bool GetShowLight() const { return GetSchemaValue<bool>(m_ptr, "COmniLight", "m_bShowLight"); }
    void SetShowLight(bool value) { SetSchemaValue(m_ptr, "COmniLight", "m_bShowLight", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif