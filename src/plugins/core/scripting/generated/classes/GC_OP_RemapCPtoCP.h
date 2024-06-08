class GC_OP_RemapCPtoCP;

#ifndef _gcc_op_remapcptocp_h
#define _gcc_op_remapcptocp_h

#include "../../../scripting.h"




class GC_OP_RemapCPtoCP
{
private:
    void *m_ptr;

public:
    GC_OP_RemapCPtoCP() {}
    GC_OP_RemapCPtoCP(void *ptr) : m_ptr(ptr) {}

    int32_t GetInputControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapCPtoCP", "m_nInputControlPoint"); }
    void SetInputControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoCP", "m_nInputControlPoint", false, value); }
    int32_t GetOutputControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapCPtoCP", "m_nOutputControlPoint"); }
    void SetOutputControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoCP", "m_nOutputControlPoint", false, value); }
    int32_t GetInputField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapCPtoCP", "m_nInputField"); }
    void SetInputField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoCP", "m_nInputField", false, value); }
    int32_t GetOutputField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapCPtoCP", "m_nOutputField"); }
    void SetOutputField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoCP", "m_nOutputField", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapCPtoCP", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoCP", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapCPtoCP", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoCP", "m_flInputMax", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapCPtoCP", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoCP", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapCPtoCP", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoCP", "m_flOutputMax", false, value); }
    bool GetDerivative() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapCPtoCP", "m_bDerivative"); }
    void SetDerivative(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoCP", "m_bDerivative", false, value); }
    float GetInterpRate() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapCPtoCP", "m_flInterpRate"); }
    void SetInterpRate(float value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoCP", "m_flInterpRate", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif