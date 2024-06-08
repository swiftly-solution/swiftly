class GCPathSimple;

#ifndef _gccpathsimple_h
#define _gccpathsimple_h

#include "../../../scripting.h"




class GCPathSimple
{
private:
    void *m_ptr;

public:
    GCPathSimple() {}
    GCPathSimple(void *ptr) : m_ptr(ptr) {}

    CUtlString GetPathString() const { return GetSchemaValue<CUtlString>(m_ptr, "CPathSimple", "m_pathString"); }
    void SetPathString(CUtlString value) { SetSchemaValue(m_ptr, "CPathSimple", "m_pathString", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif