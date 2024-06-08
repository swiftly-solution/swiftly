class GCAddUpdateNode;

#ifndef _gccaddupdatenode_h
#define _gccaddupdatenode_h

#include "../../../scripting.h"

#include "../types/GBinaryNodeChildOption.h"


class GCAddUpdateNode
{
private:
    void *m_ptr;

public:
    GCAddUpdateNode() {}
    GCAddUpdateNode(void *ptr) : m_ptr(ptr) {}

    BinaryNodeChildOption GetFootMotionTiming() const { return GetSchemaValue<BinaryNodeChildOption>(m_ptr, "CAddUpdateNode", "m_footMotionTiming"); }
    void SetFootMotionTiming(BinaryNodeChildOption value) { SetSchemaValue(m_ptr, "CAddUpdateNode", "m_footMotionTiming", false, value); }
    bool GetApplyToFootMotion() const { return GetSchemaValue<bool>(m_ptr, "CAddUpdateNode", "m_bApplyToFootMotion"); }
    void SetApplyToFootMotion(bool value) { SetSchemaValue(m_ptr, "CAddUpdateNode", "m_bApplyToFootMotion", false, value); }
    bool GetApplyChannelsSeparately() const { return GetSchemaValue<bool>(m_ptr, "CAddUpdateNode", "m_bApplyChannelsSeparately"); }
    void SetApplyChannelsSeparately(bool value) { SetSchemaValue(m_ptr, "CAddUpdateNode", "m_bApplyChannelsSeparately", false, value); }
    bool GetUseModelSpace() const { return GetSchemaValue<bool>(m_ptr, "CAddUpdateNode", "m_bUseModelSpace"); }
    void SetUseModelSpace(bool value) { SetSchemaValue(m_ptr, "CAddUpdateNode", "m_bUseModelSpace", false, value); }
    bool GetApplyScale() const { return GetSchemaValue<bool>(m_ptr, "CAddUpdateNode", "m_bApplyScale"); }
    void SetApplyScale(bool value) { SetSchemaValue(m_ptr, "CAddUpdateNode", "m_bApplyScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif