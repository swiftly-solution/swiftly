class GC_OP_RemapDistanceToLineSegmentBase;

#ifndef _gcc_op_remapdistancetolinesegmentbase_h
#define _gcc_op_remapdistancetolinesegmentbase_h

#include "../../../scripting.h"




class GC_OP_RemapDistanceToLineSegmentBase
{
private:
    void *m_ptr;

public:
    GC_OP_RemapDistanceToLineSegmentBase() {}
    GC_OP_RemapDistanceToLineSegmentBase(void *ptr) : m_ptr(ptr) {}

    int32_t GetCP0() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapDistanceToLineSegmentBase", "m_nCP0"); }
    void SetCP0(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapDistanceToLineSegmentBase", "m_nCP0", false, value); }
    int32_t GetCP1() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapDistanceToLineSegmentBase", "m_nCP1"); }
    void SetCP1(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapDistanceToLineSegmentBase", "m_nCP1", false, value); }
    float GetMinInputValue() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapDistanceToLineSegmentBase", "m_flMinInputValue"); }
    void SetMinInputValue(float value) { SetSchemaValue(m_ptr, "C_OP_RemapDistanceToLineSegmentBase", "m_flMinInputValue", false, value); }
    float GetMaxInputValue() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapDistanceToLineSegmentBase", "m_flMaxInputValue"); }
    void SetMaxInputValue(float value) { SetSchemaValue(m_ptr, "C_OP_RemapDistanceToLineSegmentBase", "m_flMaxInputValue", false, value); }
    bool GetInfiniteLine() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapDistanceToLineSegmentBase", "m_bInfiniteLine"); }
    void SetInfiniteLine(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapDistanceToLineSegmentBase", "m_bInfiniteLine", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif