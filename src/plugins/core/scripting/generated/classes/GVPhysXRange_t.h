class GVPhysXRange_t;

#ifndef _gcvphysxrange_t_h
#define _gcvphysxrange_t_h

#include "../../../scripting.h"




class GVPhysXRange_t
{
private:
    void *m_ptr;

public:
    GVPhysXRange_t() {}
    GVPhysXRange_t(void *ptr) : m_ptr(ptr) {}

    float GetMin() const { return GetSchemaValue<float>(m_ptr, "VPhysXRange_t", "m_flMin"); }
    void SetMin(float value) { SetSchemaValue(m_ptr, "VPhysXRange_t", "m_flMin", true, value); }
    float GetMax() const { return GetSchemaValue<float>(m_ptr, "VPhysXRange_t", "m_flMax"); }
    void SetMax(float value) { SetSchemaValue(m_ptr, "VPhysXRange_t", "m_flMax", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif