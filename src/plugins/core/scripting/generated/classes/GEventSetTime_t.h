class GEventSetTime_t;

#ifndef _gceventsettime_t_h
#define _gceventsettime_t_h

#include "../../../scripting.h"


#include "GEngineLoopState_t.h"

class GEventSetTime_t
{
private:
    void *m_ptr;

public:
    GEventSetTime_t() {}
    GEventSetTime_t(void *ptr) : m_ptr(ptr) {}

    GEngineLoopState_t GetLoopState() const { return GetSchemaValue<GEngineLoopState_t>(m_ptr, "EventSetTime_t", "m_LoopState"); }
    void SetLoopState(GEngineLoopState_t value) { SetSchemaValue(m_ptr, "EventSetTime_t", "m_LoopState", true, value); }
    int32_t GetClientOutputFrames() const { return GetSchemaValue<int32_t>(m_ptr, "EventSetTime_t", "m_nClientOutputFrames"); }
    void SetClientOutputFrames(int32_t value) { SetSchemaValue(m_ptr, "EventSetTime_t", "m_nClientOutputFrames", true, value); }
    double GetRealTime() const { return GetSchemaValue<double>(m_ptr, "EventSetTime_t", "m_flRealTime"); }
    void SetRealTime(double value) { SetSchemaValue(m_ptr, "EventSetTime_t", "m_flRealTime", true, value); }
    double GetRenderTime() const { return GetSchemaValue<double>(m_ptr, "EventSetTime_t", "m_flRenderTime"); }
    void SetRenderTime(double value) { SetSchemaValue(m_ptr, "EventSetTime_t", "m_flRenderTime", true, value); }
    double GetRenderFrameTime() const { return GetSchemaValue<double>(m_ptr, "EventSetTime_t", "m_flRenderFrameTime"); }
    void SetRenderFrameTime(double value) { SetSchemaValue(m_ptr, "EventSetTime_t", "m_flRenderFrameTime", true, value); }
    double GetRenderFrameTimeUnbounded() const { return GetSchemaValue<double>(m_ptr, "EventSetTime_t", "m_flRenderFrameTimeUnbounded"); }
    void SetRenderFrameTimeUnbounded(double value) { SetSchemaValue(m_ptr, "EventSetTime_t", "m_flRenderFrameTimeUnbounded", true, value); }
    double GetRenderFrameTimeUnscaled() const { return GetSchemaValue<double>(m_ptr, "EventSetTime_t", "m_flRenderFrameTimeUnscaled"); }
    void SetRenderFrameTimeUnscaled(double value) { SetSchemaValue(m_ptr, "EventSetTime_t", "m_flRenderFrameTimeUnscaled", true, value); }
    double GetTickRemainder() const { return GetSchemaValue<double>(m_ptr, "EventSetTime_t", "m_flTickRemainder"); }
    void SetTickRemainder(double value) { SetSchemaValue(m_ptr, "EventSetTime_t", "m_flTickRemainder", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif