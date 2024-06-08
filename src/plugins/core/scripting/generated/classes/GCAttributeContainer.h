class GCAttributeContainer;

#ifndef _gccattributecontainer_h
#define _gccattributecontainer_h

#include "../../../scripting.h"


#include "GCEconItemView.h"

class GCAttributeContainer
{
private:
    void *m_ptr;

public:
    GCAttributeContainer() {}
    GCAttributeContainer(void *ptr) : m_ptr(ptr) {}

    GCEconItemView GetItem() const { return GetSchemaValue<GCEconItemView>(m_ptr, "CAttributeContainer", "m_Item"); }
    void SetItem(GCEconItemView value) { SetSchemaValue(m_ptr, "CAttributeContainer", "m_Item", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif