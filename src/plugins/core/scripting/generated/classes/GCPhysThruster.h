class GCPhysThruster;

#ifndef _gccphysthruster_h
#define _gccphysthruster_h

#include "../../../scripting.h"




class GCPhysThruster
{
private:
    void *m_ptr;

public:
    GCPhysThruster() {}
    GCPhysThruster(void *ptr) : m_ptr(ptr) {}

    Vector GetLocalOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CPhysThruster", "m_localOrigin"); }
    void SetLocalOrigin(Vector value) { SetSchemaValue(m_ptr, "CPhysThruster", "m_localOrigin", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif