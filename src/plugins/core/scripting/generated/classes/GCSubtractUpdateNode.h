class GCSubtractUpdateNode;

#ifndef _gccsubtractupdatenode_h
#define _gccsubtractupdatenode_h

#include "../../../scripting.h"

#include "../types/GBinaryNodeChildOption.h"


class GCSubtractUpdateNode
{
private:
    void *m_ptr;

public:
    GCSubtractUpdateNode() {}
    GCSubtractUpdateNode(void *ptr) : m_ptr(ptr) {}

    BinaryNodeChildOption GetFootMotionTiming() const { return GetSchemaValue<BinaryNodeChildOption>(m_ptr, "CSubtractUpdateNode", "m_footMotionTiming"); }
    void SetFootMotionTiming(BinaryNodeChildOption value) { SetSchemaValue(m_ptr, "CSubtractUpdateNode", "m_footMotionTiming", false, value); }
    bool GetApplyToFootMotion() const { return GetSchemaValue<bool>(m_ptr, "CSubtractUpdateNode", "m_bApplyToFootMotion"); }
    void SetApplyToFootMotion(bool value) { SetSchemaValue(m_ptr, "CSubtractUpdateNode", "m_bApplyToFootMotion", false, value); }
    bool GetApplyChannelsSeparately() const { return GetSchemaValue<bool>(m_ptr, "CSubtractUpdateNode", "m_bApplyChannelsSeparately"); }
    void SetApplyChannelsSeparately(bool value) { SetSchemaValue(m_ptr, "CSubtractUpdateNode", "m_bApplyChannelsSeparately", false, value); }
    bool GetUseModelSpace() const { return GetSchemaValue<bool>(m_ptr, "CSubtractUpdateNode", "m_bUseModelSpace"); }
    void SetUseModelSpace(bool value) { SetSchemaValue(m_ptr, "CSubtractUpdateNode", "m_bUseModelSpace", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif