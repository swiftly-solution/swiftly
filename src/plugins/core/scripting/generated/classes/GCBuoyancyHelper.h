class GCBuoyancyHelper;

#ifndef _gccbuoyancyhelper_h
#define _gccbuoyancyhelper_h

#include "../../../scripting.h"




class GCBuoyancyHelper
{
private:
    void *m_ptr;

public:
    GCBuoyancyHelper() {}
    GCBuoyancyHelper(void *ptr) : m_ptr(ptr) {}

    float GetFluidDensity() const { return GetSchemaValue<float>(m_ptr, "CBuoyancyHelper", "m_flFluidDensity"); }
    void SetFluidDensity(float value) { SetSchemaValue(m_ptr, "CBuoyancyHelper", "m_flFluidDensity", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif