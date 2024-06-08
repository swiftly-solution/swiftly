class GCAnimUpdateNodeRef;

#ifndef _gccanimupdatenoderef_h
#define _gccanimupdatenoderef_h

#include "../../../scripting.h"




class GCAnimUpdateNodeRef
{
private:
    void *m_ptr;

public:
    GCAnimUpdateNodeRef() {}
    GCAnimUpdateNodeRef(void *ptr) : m_ptr(ptr) {}

    int32_t GetNodeIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimUpdateNodeRef", "m_nodeIndex"); }
    void SetNodeIndex(int32_t value) { SetSchemaValue(m_ptr, "CAnimUpdateNodeRef", "m_nodeIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif