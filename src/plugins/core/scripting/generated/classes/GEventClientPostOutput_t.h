class GEventClientPostOutput_t;

#ifndef _gceventclientpostoutput_t_h
#define _gceventclientpostoutput_t_h

#include "../../../scripting.h"


#include "GEngineLoopState_t.h"

class GEventClientPostOutput_t
{
private:
    void *m_ptr;

public:
    GEventClientPostOutput_t() {}
    GEventClientPostOutput_t(void *ptr) : m_ptr(ptr) {}

    GEngineLoopState_t GetLoopState() const { return GetSchemaValue<GEngineLoopState_t>(m_ptr, "EventClientPostOutput_t", "m_LoopState"); }
    void SetLoopState(GEngineLoopState_t value) { SetSchemaValue(m_ptr, "EventClientPostOutput_t", "m_LoopState", true, value); }
    double GetRenderTime() const { return GetSchemaValue<double>(m_ptr, "EventClientPostOutput_t", "m_flRenderTime"); }
    void SetRenderTime(double value) { SetSchemaValue(m_ptr, "EventClientPostOutput_t", "m_flRenderTime", true, value); }
    float GetRenderFrameTime() const { return GetSchemaValue<float>(m_ptr, "EventClientPostOutput_t", "m_flRenderFrameTime"); }
    void SetRenderFrameTime(float value) { SetSchemaValue(m_ptr, "EventClientPostOutput_t", "m_flRenderFrameTime", true, value); }
    float GetRenderFrameTimeUnbounded() const { return GetSchemaValue<float>(m_ptr, "EventClientPostOutput_t", "m_flRenderFrameTimeUnbounded"); }
    void SetRenderFrameTimeUnbounded(float value) { SetSchemaValue(m_ptr, "EventClientPostOutput_t", "m_flRenderFrameTimeUnbounded", true, value); }
    bool GetRenderOnly() const { return GetSchemaValue<bool>(m_ptr, "EventClientPostOutput_t", "m_bRenderOnly"); }
    void SetRenderOnly(bool value) { SetSchemaValue(m_ptr, "EventClientPostOutput_t", "m_bRenderOnly", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif