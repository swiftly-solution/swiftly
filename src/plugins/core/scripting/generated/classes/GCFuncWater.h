class GCFuncWater;

#ifndef _gccfuncwater_h
#define _gccfuncwater_h

#include "../../../scripting.h"


#include "GCBuoyancyHelper.h"

class GCFuncWater
{
private:
    void *m_ptr;

public:
    GCFuncWater() {}
    GCFuncWater(void *ptr) : m_ptr(ptr) {}

    GCBuoyancyHelper GetBuoyancyHelper() const { return GetSchemaValue<GCBuoyancyHelper>(m_ptr, "CFuncWater", "m_BuoyancyHelper"); }
    void SetBuoyancyHelper(GCBuoyancyHelper value) { SetSchemaValue(m_ptr, "CFuncWater", "m_BuoyancyHelper", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif