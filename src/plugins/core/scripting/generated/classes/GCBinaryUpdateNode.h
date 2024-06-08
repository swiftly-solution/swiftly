class GCBinaryUpdateNode;

#ifndef _gccbinaryupdatenode_h
#define _gccbinaryupdatenode_h

#include "../../../scripting.h"

#include "../types/GBinaryNodeTiming.h"
#include "GCAnimUpdateNodeRef.h"

class GCBinaryUpdateNode
{
private:
    void *m_ptr;

public:
    GCBinaryUpdateNode() {}
    GCBinaryUpdateNode(void *ptr) : m_ptr(ptr) {}

    GCAnimUpdateNodeRef GetChild1() const { return GetSchemaValue<GCAnimUpdateNodeRef>(m_ptr, "CBinaryUpdateNode", "m_pChild1"); }
    void SetChild1(GCAnimUpdateNodeRef value) { SetSchemaValue(m_ptr, "CBinaryUpdateNode", "m_pChild1", false, value); }
    GCAnimUpdateNodeRef GetChild2() const { return GetSchemaValue<GCAnimUpdateNodeRef>(m_ptr, "CBinaryUpdateNode", "m_pChild2"); }
    void SetChild2(GCAnimUpdateNodeRef value) { SetSchemaValue(m_ptr, "CBinaryUpdateNode", "m_pChild2", false, value); }
    BinaryNodeTiming GetTimingBehavior() const { return GetSchemaValue<BinaryNodeTiming>(m_ptr, "CBinaryUpdateNode", "m_timingBehavior"); }
    void SetTimingBehavior(BinaryNodeTiming value) { SetSchemaValue(m_ptr, "CBinaryUpdateNode", "m_timingBehavior", false, value); }
    float GetTimingBlend() const { return GetSchemaValue<float>(m_ptr, "CBinaryUpdateNode", "m_flTimingBlend"); }
    void SetTimingBlend(float value) { SetSchemaValue(m_ptr, "CBinaryUpdateNode", "m_flTimingBlend", false, value); }
    bool GetResetChild1() const { return GetSchemaValue<bool>(m_ptr, "CBinaryUpdateNode", "m_bResetChild1"); }
    void SetResetChild1(bool value) { SetSchemaValue(m_ptr, "CBinaryUpdateNode", "m_bResetChild1", false, value); }
    bool GetResetChild2() const { return GetSchemaValue<bool>(m_ptr, "CBinaryUpdateNode", "m_bResetChild2"); }
    void SetResetChild2(bool value) { SetSchemaValue(m_ptr, "CBinaryUpdateNode", "m_bResetChild2", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif