class GCUnaryUpdateNode;

#ifndef _gccunaryupdatenode_h
#define _gccunaryupdatenode_h

#include "../../../scripting.h"


#include "GCAnimUpdateNodeRef.h"

class GCUnaryUpdateNode
{
private:
    void *m_ptr;

public:
    GCUnaryUpdateNode() {}
    GCUnaryUpdateNode(void *ptr) : m_ptr(ptr) {}

    GCAnimUpdateNodeRef GetChildNode() const { return GetSchemaValue<GCAnimUpdateNodeRef>(m_ptr, "CUnaryUpdateNode", "m_pChildNode"); }
    void SetChildNode(GCAnimUpdateNodeRef value) { SetSchemaValue(m_ptr, "CUnaryUpdateNode", "m_pChildNode", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif