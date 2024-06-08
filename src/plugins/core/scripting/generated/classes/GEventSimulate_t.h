class GEventSimulate_t;

#ifndef _gceventsimulate_t_h
#define _gceventsimulate_t_h

#include "../../../scripting.h"


#include "GEngineLoopState_t.h"

class GEventSimulate_t
{
private:
    void *m_ptr;

public:
    GEventSimulate_t() {}
    GEventSimulate_t(void *ptr) : m_ptr(ptr) {}

    GEngineLoopState_t GetLoopState() const { return GetSchemaValue<GEngineLoopState_t>(m_ptr, "EventSimulate_t", "m_LoopState"); }
    void SetLoopState(GEngineLoopState_t value) { SetSchemaValue(m_ptr, "EventSimulate_t", "m_LoopState", true, value); }
    bool GetFirstTick() const { return GetSchemaValue<bool>(m_ptr, "EventSimulate_t", "m_bFirstTick"); }
    void SetFirstTick(bool value) { SetSchemaValue(m_ptr, "EventSimulate_t", "m_bFirstTick", true, value); }
    bool GetLastTick() const { return GetSchemaValue<bool>(m_ptr, "EventSimulate_t", "m_bLastTick"); }
    void SetLastTick(bool value) { SetSchemaValue(m_ptr, "EventSimulate_t", "m_bLastTick", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif