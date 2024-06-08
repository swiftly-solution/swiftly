class GCFlexDesc;

#ifndef _gccflexdesc_h
#define _gccflexdesc_h

#include "../../../scripting.h"




class GCFlexDesc
{
private:
    void *m_ptr;

public:
    GCFlexDesc() {}
    GCFlexDesc(void *ptr) : m_ptr(ptr) {}

    CUtlString GetFacs() const { return GetSchemaValue<CUtlString>(m_ptr, "CFlexDesc", "m_szFacs"); }
    void SetFacs(CUtlString value) { SetSchemaValue(m_ptr, "CFlexDesc", "m_szFacs", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif