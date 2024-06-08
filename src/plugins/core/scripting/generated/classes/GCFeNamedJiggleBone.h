class GCFeNamedJiggleBone;

#ifndef _gccfenamedjigglebone_h
#define _gccfenamedjigglebone_h

#include "../../../scripting.h"


#include "GCFeJiggleBone.h"

class GCFeNamedJiggleBone
{
private:
    void *m_ptr;

public:
    GCFeNamedJiggleBone() {}
    GCFeNamedJiggleBone(void *ptr) : m_ptr(ptr) {}

    CUtlString GetStrParentBone() const { return GetSchemaValue<CUtlString>(m_ptr, "CFeNamedJiggleBone", "m_strParentBone"); }
    void SetStrParentBone(CUtlString value) { SetSchemaValue(m_ptr, "CFeNamedJiggleBone", "m_strParentBone", false, value); }
    uint32_t GetJiggleParent() const { return GetSchemaValue<uint32_t>(m_ptr, "CFeNamedJiggleBone", "m_nJiggleParent"); }
    void SetJiggleParent(uint32_t value) { SetSchemaValue(m_ptr, "CFeNamedJiggleBone", "m_nJiggleParent", false, value); }
    GCFeJiggleBone GetJiggleBone() const { return GetSchemaValue<GCFeJiggleBone>(m_ptr, "CFeNamedJiggleBone", "m_jiggleBone"); }
    void SetJiggleBone(GCFeJiggleBone value) { SetSchemaValue(m_ptr, "CFeNamedJiggleBone", "m_jiggleBone", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif