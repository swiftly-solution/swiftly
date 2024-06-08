class GCNetworkVarChainer;

#ifndef _gccnetworkvarchainer_h
#define _gccnetworkvarchainer_h

#include "../../../scripting.h"


#include "GChangeAccessorFieldPathIndex_t.h"

class GCNetworkVarChainer
{
private:
    void *m_ptr;

public:
    GCNetworkVarChainer() {}
    GCNetworkVarChainer(void *ptr) : m_ptr(ptr) {}

    GChangeAccessorFieldPathIndex_t GetPathIndex() const { return GetSchemaValue<GChangeAccessorFieldPathIndex_t>(m_ptr, "CNetworkVarChainer", "m_PathIndex"); }
    void SetPathIndex(GChangeAccessorFieldPathIndex_t value) { SetSchemaValue(m_ptr, "CNetworkVarChainer", "m_PathIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif