class GCDynamicPropAlias_cable_dynamic;

#ifndef _gccdynamicpropalias_cable_dynamic_h
#define _gccdynamicpropalias_cable_dynamic_h

#include "../../../scripting.h"




class GCDynamicPropAlias_cable_dynamic
{
private:
    void *m_ptr;

public:
    GCDynamicPropAlias_cable_dynamic() {}
    GCDynamicPropAlias_cable_dynamic(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif