class GC_OP_CPOffsetToPercentageBetweenCPs;

#ifndef _gcc_op_cpoffsettopercentagebetweencps_h
#define _gcc_op_cpoffsettopercentagebetweencps_h

#include "../../../scripting.h"




class GC_OP_CPOffsetToPercentageBetweenCPs
{
private:
    void *m_ptr;

public:
    GC_OP_CPOffsetToPercentageBetweenCPs() {}
    GC_OP_CPOffsetToPercentageBetweenCPs(void *ptr) : m_ptr(ptr) {}

    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_flInputMax", false, value); }
    float GetInputBias() const { return GetSchemaValue<float>(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_flInputBias"); }
    void SetInputBias(float value) { SetSchemaValue(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_flInputBias", false, value); }
    int32_t GetStartCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_nStartCP"); }
    void SetStartCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_nStartCP", false, value); }
    int32_t GetEndCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_nEndCP"); }
    void SetEndCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_nEndCP", false, value); }
    int32_t GetOffsetCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_nOffsetCP"); }
    void SetOffsetCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_nOffsetCP", false, value); }
    int32_t GetOuputCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_nOuputCP"); }
    void SetOuputCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_nOuputCP", false, value); }
    int32_t GetInputCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_nInputCP"); }
    void SetInputCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_nInputCP", false, value); }
    bool GetRadialCheck() const { return GetSchemaValue<bool>(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_bRadialCheck"); }
    void SetRadialCheck(bool value) { SetSchemaValue(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_bRadialCheck", false, value); }
    bool GetScaleOffset() const { return GetSchemaValue<bool>(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_bScaleOffset"); }
    void SetScaleOffset(bool value) { SetSchemaValue(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_bScaleOffset", false, value); }
    Vector GetOffset() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_vecOffset"); }
    void SetOffset(Vector value) { SetSchemaValue(m_ptr, "C_OP_CPOffsetToPercentageBetweenCPs", "m_vecOffset", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif