class GCFeIndexedJiggleBone;

#ifndef _gccfeindexedjigglebone_h
#define _gccfeindexedjigglebone_h

#include "../../../scripting.h"


#include "GCFeJiggleBone.h"

class GCFeIndexedJiggleBone
{
private:
    void *m_ptr;

public:
    GCFeIndexedJiggleBone() {}
    GCFeIndexedJiggleBone(void *ptr) : m_ptr(ptr) {}

    uint32_t GetNode() const { return GetSchemaValue<uint32_t>(m_ptr, "CFeIndexedJiggleBone", "m_nNode"); }
    void SetNode(uint32_t value) { SetSchemaValue(m_ptr, "CFeIndexedJiggleBone", "m_nNode", false, value); }
    uint32_t GetJiggleParent() const { return GetSchemaValue<uint32_t>(m_ptr, "CFeIndexedJiggleBone", "m_nJiggleParent"); }
    void SetJiggleParent(uint32_t value) { SetSchemaValue(m_ptr, "CFeIndexedJiggleBone", "m_nJiggleParent", false, value); }
    GCFeJiggleBone GetJiggleBone() const { return GetSchemaValue<GCFeJiggleBone>(m_ptr, "CFeIndexedJiggleBone", "m_jiggleBone"); }
    void SetJiggleBone(GCFeJiggleBone value) { SetSchemaValue(m_ptr, "CFeIndexedJiggleBone", "m_jiggleBone", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif