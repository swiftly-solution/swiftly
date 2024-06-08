class GC_OP_RemapSpeedtoCP;

#ifndef _gcc_op_remapspeedtocp_h
#define _gcc_op_remapspeedtocp_h

#include "../../../scripting.h"




class GC_OP_RemapSpeedtoCP
{
private:
    void *m_ptr;

public:
    GC_OP_RemapSpeedtoCP() {}
    GC_OP_RemapSpeedtoCP(void *ptr) : m_ptr(ptr) {}

    int32_t GetInControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapSpeedtoCP", "m_nInControlPointNumber"); }
    void SetInControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapSpeedtoCP", "m_nInControlPointNumber", false, value); }
    int32_t GetOutControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapSpeedtoCP", "m_nOutControlPointNumber"); }
    void SetOutControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapSpeedtoCP", "m_nOutControlPointNumber", false, value); }
    int32_t GetField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapSpeedtoCP", "m_nField"); }
    void SetField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapSpeedtoCP", "m_nField", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapSpeedtoCP", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapSpeedtoCP", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapSpeedtoCP", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapSpeedtoCP", "m_flInputMax", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapSpeedtoCP", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapSpeedtoCP", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapSpeedtoCP", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapSpeedtoCP", "m_flOutputMax", false, value); }
    bool GetUseDeltaV() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapSpeedtoCP", "m_bUseDeltaV"); }
    void SetUseDeltaV(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapSpeedtoCP", "m_bUseDeltaV", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif