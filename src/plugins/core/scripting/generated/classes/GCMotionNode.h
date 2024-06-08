class GCMotionNode;

#ifndef _gccmotionnode_h
#define _gccmotionnode_h

#include "../../../scripting.h"


#include "GAnimNodeID.h"

class GCMotionNode
{
private:
    void *m_ptr;

public:
    GCMotionNode() {}
    GCMotionNode(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CMotionNode", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "CMotionNode", "m_name", false, value); }
    GAnimNodeID GetId() const { return GetSchemaValue<GAnimNodeID>(m_ptr, "CMotionNode", "m_id"); }
    void SetId(GAnimNodeID value) { SetSchemaValue(m_ptr, "CMotionNode", "m_id", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif