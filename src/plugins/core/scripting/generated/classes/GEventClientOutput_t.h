class GEventClientOutput_t;

#ifndef _gceventclientoutput_t_h
#define _gceventclientoutput_t_h

#include "../../../scripting.h"


#include "GEngineLoopState_t.h"

class GEventClientOutput_t
{
private:
    void *m_ptr;

public:
    GEventClientOutput_t() {}
    GEventClientOutput_t(void *ptr) : m_ptr(ptr) {}

    GEngineLoopState_t GetLoopState() const { return GetSchemaValue<GEngineLoopState_t>(m_ptr, "EventClientOutput_t", "m_LoopState"); }
    void SetLoopState(GEngineLoopState_t value) { SetSchemaValue(m_ptr, "EventClientOutput_t", "m_LoopState", true, value); }
    float GetRenderTime() const { return GetSchemaValue<float>(m_ptr, "EventClientOutput_t", "m_flRenderTime"); }
    void SetRenderTime(float value) { SetSchemaValue(m_ptr, "EventClientOutput_t", "m_flRenderTime", true, value); }
    float GetRealTime() const { return GetSchemaValue<float>(m_ptr, "EventClientOutput_t", "m_flRealTime"); }
    void SetRealTime(float value) { SetSchemaValue(m_ptr, "EventClientOutput_t", "m_flRealTime", true, value); }
    float GetRenderFrameTimeUnbounded() const { return GetSchemaValue<float>(m_ptr, "EventClientOutput_t", "m_flRenderFrameTimeUnbounded"); }
    void SetRenderFrameTimeUnbounded(float value) { SetSchemaValue(m_ptr, "EventClientOutput_t", "m_flRenderFrameTimeUnbounded", true, value); }
    bool GetRenderOnly() const { return GetSchemaValue<bool>(m_ptr, "EventClientOutput_t", "m_bRenderOnly"); }
    void SetRenderOnly(bool value) { SetSchemaValue(m_ptr, "EventClientOutput_t", "m_bRenderOnly", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif