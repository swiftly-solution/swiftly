class GEventClientProcessInput_t;

#ifndef _gceventclientprocessinput_t_h
#define _gceventclientprocessinput_t_h

#include "../../../scripting.h"


#include "GEngineLoopState_t.h"

class GEventClientProcessInput_t
{
private:
    void *m_ptr;

public:
    GEventClientProcessInput_t() {}
    GEventClientProcessInput_t(void *ptr) : m_ptr(ptr) {}

    GEngineLoopState_t GetLoopState() const { return GetSchemaValue<GEngineLoopState_t>(m_ptr, "EventClientProcessInput_t", "m_LoopState"); }
    void SetLoopState(GEngineLoopState_t value) { SetSchemaValue(m_ptr, "EventClientProcessInput_t", "m_LoopState", true, value); }
    float GetRealTime() const { return GetSchemaValue<float>(m_ptr, "EventClientProcessInput_t", "m_flRealTime"); }
    void SetRealTime(float value) { SetSchemaValue(m_ptr, "EventClientProcessInput_t", "m_flRealTime", true, value); }
    float GetTickInterval() const { return GetSchemaValue<float>(m_ptr, "EventClientProcessInput_t", "m_flTickInterval"); }
    void SetTickInterval(float value) { SetSchemaValue(m_ptr, "EventClientProcessInput_t", "m_flTickInterval", true, value); }
    double GetTickStartTime() const { return GetSchemaValue<double>(m_ptr, "EventClientProcessInput_t", "m_flTickStartTime"); }
    void SetTickStartTime(double value) { SetSchemaValue(m_ptr, "EventClientProcessInput_t", "m_flTickStartTime", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif