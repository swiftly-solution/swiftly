class GEventAdvanceTick_t;

#ifndef _gceventadvancetick_t_h
#define _gceventadvancetick_t_h

#include "../../../scripting.h"




class GEventAdvanceTick_t
{
private:
    void *m_ptr;

public:
    GEventAdvanceTick_t() {}
    GEventAdvanceTick_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetCurrentTick() const { return GetSchemaValue<int32_t>(m_ptr, "EventAdvanceTick_t", "m_nCurrentTick"); }
    void SetCurrentTick(int32_t value) { SetSchemaValue(m_ptr, "EventAdvanceTick_t", "m_nCurrentTick", true, value); }
    int32_t GetCurrentTickThisFrame() const { return GetSchemaValue<int32_t>(m_ptr, "EventAdvanceTick_t", "m_nCurrentTickThisFrame"); }
    void SetCurrentTickThisFrame(int32_t value) { SetSchemaValue(m_ptr, "EventAdvanceTick_t", "m_nCurrentTickThisFrame", true, value); }
    int32_t GetTotalTicksThisFrame() const { return GetSchemaValue<int32_t>(m_ptr, "EventAdvanceTick_t", "m_nTotalTicksThisFrame"); }
    void SetTotalTicksThisFrame(int32_t value) { SetSchemaValue(m_ptr, "EventAdvanceTick_t", "m_nTotalTicksThisFrame", true, value); }
    int32_t GetTotalTicks() const { return GetSchemaValue<int32_t>(m_ptr, "EventAdvanceTick_t", "m_nTotalTicks"); }
    void SetTotalTicks(int32_t value) { SetSchemaValue(m_ptr, "EventAdvanceTick_t", "m_nTotalTicks", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif