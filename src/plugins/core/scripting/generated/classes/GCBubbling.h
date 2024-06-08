class GCBubbling;

#ifndef _gccbubbling_h
#define _gccbubbling_h

#include "../../../scripting.h"




class GCBubbling
{
private:
    void *m_ptr;

public:
    GCBubbling() {}
    GCBubbling(void *ptr) : m_ptr(ptr) {}

    int32_t GetDensity() const { return GetSchemaValue<int32_t>(m_ptr, "CBubbling", "m_density"); }
    void SetDensity(int32_t value) { SetSchemaValue(m_ptr, "CBubbling", "m_density", false, value); }
    int32_t GetFrequency() const { return GetSchemaValue<int32_t>(m_ptr, "CBubbling", "m_frequency"); }
    void SetFrequency(int32_t value) { SetSchemaValue(m_ptr, "CBubbling", "m_frequency", false, value); }
    int32_t GetState() const { return GetSchemaValue<int32_t>(m_ptr, "CBubbling", "m_state"); }
    void SetState(int32_t value) { SetSchemaValue(m_ptr, "CBubbling", "m_state", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif