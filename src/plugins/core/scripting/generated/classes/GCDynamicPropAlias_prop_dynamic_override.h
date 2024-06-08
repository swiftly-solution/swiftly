class GCDynamicPropAlias_prop_dynamic_override;

#ifndef _gccdynamicpropalias_prop_dynamic_override_h
#define _gccdynamicpropalias_prop_dynamic_override_h

#include "../../../scripting.h"




class GCDynamicPropAlias_prop_dynamic_override
{
private:
    void *m_ptr;

public:
    GCDynamicPropAlias_prop_dynamic_override() {}
    GCDynamicPropAlias_prop_dynamic_override(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif