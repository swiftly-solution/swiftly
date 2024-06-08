class GEventClientPreOutput_t;

#ifndef _gceventclientpreoutput_t_h
#define _gceventclientpreoutput_t_h

#include "../../../scripting.h"


#include "GEngineLoopState_t.h"

class GEventClientPreOutput_t
{
private:
    void *m_ptr;

public:
    GEventClientPreOutput_t() {}
    GEventClientPreOutput_t(void *ptr) : m_ptr(ptr) {}

    GEngineLoopState_t GetLoopState() const { return GetSchemaValue<GEngineLoopState_t>(m_ptr, "EventClientPreOutput_t", "m_LoopState"); }
    void SetLoopState(GEngineLoopState_t value) { SetSchemaValue(m_ptr, "EventClientPreOutput_t", "m_LoopState", true, value); }
    double GetRenderTime() const { return GetSchemaValue<double>(m_ptr, "EventClientPreOutput_t", "m_flRenderTime"); }
    void SetRenderTime(double value) { SetSchemaValue(m_ptr, "EventClientPreOutput_t", "m_flRenderTime", true, value); }
    double GetRenderFrameTime() const { return GetSchemaValue<double>(m_ptr, "EventClientPreOutput_t", "m_flRenderFrameTime"); }
    void SetRenderFrameTime(double value) { SetSchemaValue(m_ptr, "EventClientPreOutput_t", "m_flRenderFrameTime", true, value); }
    double GetRenderFrameTimeUnbounded() const { return GetSchemaValue<double>(m_ptr, "EventClientPreOutput_t", "m_flRenderFrameTimeUnbounded"); }
    void SetRenderFrameTimeUnbounded(double value) { SetSchemaValue(m_ptr, "EventClientPreOutput_t", "m_flRenderFrameTimeUnbounded", true, value); }
    float GetRealTime() const { return GetSchemaValue<float>(m_ptr, "EventClientPreOutput_t", "m_flRealTime"); }
    void SetRealTime(float value) { SetSchemaValue(m_ptr, "EventClientPreOutput_t", "m_flRealTime", true, value); }
    bool GetRenderOnly() const { return GetSchemaValue<bool>(m_ptr, "EventClientPreOutput_t", "m_bRenderOnly"); }
    void SetRenderOnly(bool value) { SetSchemaValue(m_ptr, "EventClientPreOutput_t", "m_bRenderOnly", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif