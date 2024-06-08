class GEventClientFrameSimulate_t;

#ifndef _gceventclientframesimulate_t_h
#define _gceventclientframesimulate_t_h

#include "../../../scripting.h"


#include "GEngineLoopState_t.h"

class GEventClientFrameSimulate_t
{
private:
    void *m_ptr;

public:
    GEventClientFrameSimulate_t() {}
    GEventClientFrameSimulate_t(void *ptr) : m_ptr(ptr) {}

    GEngineLoopState_t GetLoopState() const { return GetSchemaValue<GEngineLoopState_t>(m_ptr, "EventClientFrameSimulate_t", "m_LoopState"); }
    void SetLoopState(GEngineLoopState_t value) { SetSchemaValue(m_ptr, "EventClientFrameSimulate_t", "m_LoopState", true, value); }
    float GetRealTime() const { return GetSchemaValue<float>(m_ptr, "EventClientFrameSimulate_t", "m_flRealTime"); }
    void SetRealTime(float value) { SetSchemaValue(m_ptr, "EventClientFrameSimulate_t", "m_flRealTime", true, value); }
    float GetFrameTime() const { return GetSchemaValue<float>(m_ptr, "EventClientFrameSimulate_t", "m_flFrameTime"); }
    void SetFrameTime(float value) { SetSchemaValue(m_ptr, "EventClientFrameSimulate_t", "m_flFrameTime", true, value); }
    double GetWhenScheduleSendTickPacket() const { return GetSchemaValue<double>(m_ptr, "EventClientFrameSimulate_t", "m_flWhenScheduleSendTickPacket"); }
    void SetWhenScheduleSendTickPacket(double value) { SetSchemaValue(m_ptr, "EventClientFrameSimulate_t", "m_flWhenScheduleSendTickPacket", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif