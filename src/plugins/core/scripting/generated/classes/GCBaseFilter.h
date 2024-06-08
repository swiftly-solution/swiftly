class GCBaseFilter;

#ifndef _gccbasefilter_h
#define _gccbasefilter_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCBaseFilter
{
private:
    void *m_ptr;

public:
    GCBaseFilter() {}
    GCBaseFilter(void *ptr) : m_ptr(ptr) {}

    bool GetNegated() const { return GetSchemaValue<bool>(m_ptr, "CBaseFilter", "m_bNegated"); }
    void SetNegated(bool value) { SetSchemaValue(m_ptr, "CBaseFilter", "m_bNegated", false, value); }
    GCEntityIOOutput GetOnPass() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseFilter", "m_OnPass"); }
    void SetOnPass(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseFilter", "m_OnPass", false, value); }
    GCEntityIOOutput GetOnFail() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseFilter", "m_OnFail"); }
    void SetOnFail(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseFilter", "m_OnFail", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif