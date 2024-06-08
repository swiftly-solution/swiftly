class GCFilterAttributeInt;

#ifndef _gccfilterattributeint_h
#define _gccfilterattributeint_h

#include "../../../scripting.h"




class GCFilterAttributeInt
{
private:
    void *m_ptr;

public:
    GCFilterAttributeInt() {}
    GCFilterAttributeInt(void *ptr) : m_ptr(ptr) {}

    CUtlStringToken GetAttributeName() const { return GetSchemaValue<CUtlStringToken>(m_ptr, "CFilterAttributeInt", "m_sAttributeName"); }
    void SetAttributeName(CUtlStringToken value) { SetSchemaValue(m_ptr, "CFilterAttributeInt", "m_sAttributeName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif