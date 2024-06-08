class GCEnvFade;

#ifndef _gccenvfade_h
#define _gccenvfade_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCEnvFade
{
private:
    void *m_ptr;

public:
    GCEnvFade() {}
    GCEnvFade(void *ptr) : m_ptr(ptr) {}

    Color GetFadeColor() const { return GetSchemaValue<Color>(m_ptr, "CEnvFade", "m_fadeColor"); }
    void SetFadeColor(Color value) { SetSchemaValue(m_ptr, "CEnvFade", "m_fadeColor", false, value); }
    float GetDuration() const { return GetSchemaValue<float>(m_ptr, "CEnvFade", "m_Duration"); }
    void SetDuration(float value) { SetSchemaValue(m_ptr, "CEnvFade", "m_Duration", false, value); }
    float GetHoldDuration() const { return GetSchemaValue<float>(m_ptr, "CEnvFade", "m_HoldDuration"); }
    void SetHoldDuration(float value) { SetSchemaValue(m_ptr, "CEnvFade", "m_HoldDuration", false, value); }
    GCEntityIOOutput GetOnBeginFade() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CEnvFade", "m_OnBeginFade"); }
    void SetOnBeginFade(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CEnvFade", "m_OnBeginFade", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif