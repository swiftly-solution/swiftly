class GCFuncTimescale;

#ifndef _gccfunctimescale_h
#define _gccfunctimescale_h

#include "../../../scripting.h"




class GCFuncTimescale
{
private:
    void *m_ptr;

public:
    GCFuncTimescale() {}
    GCFuncTimescale(void *ptr) : m_ptr(ptr) {}

    float GetDesiredTimescale() const { return GetSchemaValue<float>(m_ptr, "CFuncTimescale", "m_flDesiredTimescale"); }
    void SetDesiredTimescale(float value) { SetSchemaValue(m_ptr, "CFuncTimescale", "m_flDesiredTimescale", false, value); }
    float GetAcceleration() const { return GetSchemaValue<float>(m_ptr, "CFuncTimescale", "m_flAcceleration"); }
    void SetAcceleration(float value) { SetSchemaValue(m_ptr, "CFuncTimescale", "m_flAcceleration", false, value); }
    float GetMinBlendRate() const { return GetSchemaValue<float>(m_ptr, "CFuncTimescale", "m_flMinBlendRate"); }
    void SetMinBlendRate(float value) { SetSchemaValue(m_ptr, "CFuncTimescale", "m_flMinBlendRate", false, value); }
    float GetBlendDeltaMultiplier() const { return GetSchemaValue<float>(m_ptr, "CFuncTimescale", "m_flBlendDeltaMultiplier"); }
    void SetBlendDeltaMultiplier(float value) { SetSchemaValue(m_ptr, "CFuncTimescale", "m_flBlendDeltaMultiplier", false, value); }
    bool GetIsStarted() const { return GetSchemaValue<bool>(m_ptr, "CFuncTimescale", "m_isStarted"); }
    void SetIsStarted(bool value) { SetSchemaValue(m_ptr, "CFuncTimescale", "m_isStarted", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif