class GCNavLinkAnimgraphVar;

#ifndef _gccnavlinkanimgraphvar_h
#define _gccnavlinkanimgraphvar_h

#include "../../../scripting.h"




class GCNavLinkAnimgraphVar
{
private:
    void *m_ptr;

public:
    GCNavLinkAnimgraphVar() {}
    GCNavLinkAnimgraphVar(void *ptr) : m_ptr(ptr) {}

    uint32_t GetAlignmentDegrees() const { return GetSchemaValue<uint32_t>(m_ptr, "CNavLinkAnimgraphVar", "m_unAlignmentDegrees"); }
    void SetAlignmentDegrees(uint32_t value) { SetSchemaValue(m_ptr, "CNavLinkAnimgraphVar", "m_unAlignmentDegrees", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif