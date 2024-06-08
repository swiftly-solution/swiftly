class GCCycleBase;

#ifndef _gcccyclebase_h
#define _gcccyclebase_h

#include "../../../scripting.h"




class GCCycleBase
{
private:
    void *m_ptr;

public:
    GCCycleBase() {}
    GCCycleBase(void *ptr) : m_ptr(ptr) {}

    float GetCycle() const { return GetSchemaValue<float>(m_ptr, "CCycleBase", "m_flCycle"); }
    void SetCycle(float value) { SetSchemaValue(m_ptr, "CCycleBase", "m_flCycle", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif