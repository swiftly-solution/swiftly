class GEventClientProcessGameInput_t;

#ifndef _gceventclientprocessgameinput_t_h
#define _gceventclientprocessgameinput_t_h

#include "../../../scripting.h"


#include "GEngineLoopState_t.h"

class GEventClientProcessGameInput_t
{
private:
    void *m_ptr;

public:
    GEventClientProcessGameInput_t() {}
    GEventClientProcessGameInput_t(void *ptr) : m_ptr(ptr) {}

    GEngineLoopState_t GetLoopState() const { return GetSchemaValue<GEngineLoopState_t>(m_ptr, "EventClientProcessGameInput_t", "m_LoopState"); }
    void SetLoopState(GEngineLoopState_t value) { SetSchemaValue(m_ptr, "EventClientProcessGameInput_t", "m_LoopState", true, value); }
    float GetRealTime() const { return GetSchemaValue<float>(m_ptr, "EventClientProcessGameInput_t", "m_flRealTime"); }
    void SetRealTime(float value) { SetSchemaValue(m_ptr, "EventClientProcessGameInput_t", "m_flRealTime", true, value); }
    float GetFrameTime() const { return GetSchemaValue<float>(m_ptr, "EventClientProcessGameInput_t", "m_flFrameTime"); }
    void SetFrameTime(float value) { SetSchemaValue(m_ptr, "EventClientProcessGameInput_t", "m_flFrameTime", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif