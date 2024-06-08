class GEventClientPollInput_t;

#ifndef _gceventclientpollinput_t_h
#define _gceventclientpollinput_t_h

#include "../../../scripting.h"


#include "GEngineLoopState_t.h"

class GEventClientPollInput_t
{
private:
    void *m_ptr;

public:
    GEventClientPollInput_t() {}
    GEventClientPollInput_t(void *ptr) : m_ptr(ptr) {}

    GEngineLoopState_t GetLoopState() const { return GetSchemaValue<GEngineLoopState_t>(m_ptr, "EventClientPollInput_t", "m_LoopState"); }
    void SetLoopState(GEngineLoopState_t value) { SetSchemaValue(m_ptr, "EventClientPollInput_t", "m_LoopState", true, value); }
    float GetRealTime() const { return GetSchemaValue<float>(m_ptr, "EventClientPollInput_t", "m_flRealTime"); }
    void SetRealTime(float value) { SetSchemaValue(m_ptr, "EventClientPollInput_t", "m_flRealTime", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif