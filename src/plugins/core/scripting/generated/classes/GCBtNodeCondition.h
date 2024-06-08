class GCBtNodeCondition;

#ifndef _gccbtnodecondition_h
#define _gccbtnodecondition_h

#include "../../../scripting.h"




class GCBtNodeCondition
{
private:
    void *m_ptr;

public:
    GCBtNodeCondition() {}
    GCBtNodeCondition(void *ptr) : m_ptr(ptr) {}

    bool GetNegated() const { return GetSchemaValue<bool>(m_ptr, "CBtNodeCondition", "m_bNegated"); }
    void SetNegated(bool value) { SetSchemaValue(m_ptr, "CBtNodeCondition", "m_bNegated", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif