class GC_OP_RemapBoundingVolumetoCP;

#ifndef _gcc_op_remapboundingvolumetocp_h
#define _gcc_op_remapboundingvolumetocp_h

#include "../../../scripting.h"




class GC_OP_RemapBoundingVolumetoCP
{
private:
    void *m_ptr;

public:
    GC_OP_RemapBoundingVolumetoCP() {}
    GC_OP_RemapBoundingVolumetoCP(void *ptr) : m_ptr(ptr) {}

    int32_t GetOutControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapBoundingVolumetoCP", "m_nOutControlPointNumber"); }
    void SetOutControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapBoundingVolumetoCP", "m_nOutControlPointNumber", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapBoundingVolumetoCP", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapBoundingVolumetoCP", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapBoundingVolumetoCP", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapBoundingVolumetoCP", "m_flInputMax", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapBoundingVolumetoCP", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapBoundingVolumetoCP", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapBoundingVolumetoCP", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapBoundingVolumetoCP", "m_flOutputMax", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif