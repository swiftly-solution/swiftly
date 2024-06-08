class GC_OP_RestartAfterDuration;

#ifndef _gcc_op_restartafterduration_h
#define _gcc_op_restartafterduration_h

#include "../../../scripting.h"




class GC_OP_RestartAfterDuration
{
private:
    void *m_ptr;

public:
    GC_OP_RestartAfterDuration() {}
    GC_OP_RestartAfterDuration(void *ptr) : m_ptr(ptr) {}

    float GetDurationMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RestartAfterDuration", "m_flDurationMin"); }
    void SetDurationMin(float value) { SetSchemaValue(m_ptr, "C_OP_RestartAfterDuration", "m_flDurationMin", false, value); }
    float GetDurationMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RestartAfterDuration", "m_flDurationMax"); }
    void SetDurationMax(float value) { SetSchemaValue(m_ptr, "C_OP_RestartAfterDuration", "m_flDurationMax", false, value); }
    int32_t GetCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RestartAfterDuration", "m_nCP"); }
    void SetCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RestartAfterDuration", "m_nCP", false, value); }
    int32_t GetCPField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RestartAfterDuration", "m_nCPField"); }
    void SetCPField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RestartAfterDuration", "m_nCPField", false, value); }
    int32_t GetChildGroupID() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RestartAfterDuration", "m_nChildGroupID"); }
    void SetChildGroupID(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RestartAfterDuration", "m_nChildGroupID", false, value); }
    bool GetOnlyChildren() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RestartAfterDuration", "m_bOnlyChildren"); }
    void SetOnlyChildren(bool value) { SetSchemaValue(m_ptr, "C_OP_RestartAfterDuration", "m_bOnlyChildren", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif