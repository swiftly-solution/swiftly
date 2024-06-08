class GCDynamicPropAlias_dynamic_prop;

#ifndef _gccdynamicpropalias_dynamic_prop_h
#define _gccdynamicpropalias_dynamic_prop_h

#include "../../../scripting.h"




class GCDynamicPropAlias_dynamic_prop
{
private:
    void *m_ptr;

public:
    GCDynamicPropAlias_dynamic_prop() {}
    GCDynamicPropAlias_dynamic_prop(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif