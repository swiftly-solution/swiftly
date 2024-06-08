class GC_OP_RemapModelVolumetoCP;

#ifndef _gcc_op_remapmodelvolumetocp_h
#define _gcc_op_remapmodelvolumetocp_h

#include "../../../scripting.h"

#include "../types/GBBoxVolumeType_t.h"


class GC_OP_RemapModelVolumetoCP
{
private:
    void *m_ptr;

public:
    GC_OP_RemapModelVolumetoCP() {}
    GC_OP_RemapModelVolumetoCP(void *ptr) : m_ptr(ptr) {}

    BBoxVolumeType_t GetBBoxType() const { return GetSchemaValue<BBoxVolumeType_t>(m_ptr, "C_OP_RemapModelVolumetoCP", "m_nBBoxType"); }
    void SetBBoxType(BBoxVolumeType_t value) { SetSchemaValue(m_ptr, "C_OP_RemapModelVolumetoCP", "m_nBBoxType", false, value); }
    int32_t GetInControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapModelVolumetoCP", "m_nInControlPointNumber"); }
    void SetInControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapModelVolumetoCP", "m_nInControlPointNumber", false, value); }
    int32_t GetOutControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapModelVolumetoCP", "m_nOutControlPointNumber"); }
    void SetOutControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapModelVolumetoCP", "m_nOutControlPointNumber", false, value); }
    int32_t GetOutControlPointMaxNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapModelVolumetoCP", "m_nOutControlPointMaxNumber"); }
    void SetOutControlPointMaxNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapModelVolumetoCP", "m_nOutControlPointMaxNumber", false, value); }
    int32_t GetField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapModelVolumetoCP", "m_nField"); }
    void SetField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapModelVolumetoCP", "m_nField", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapModelVolumetoCP", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapModelVolumetoCP", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapModelVolumetoCP", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapModelVolumetoCP", "m_flInputMax", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapModelVolumetoCP", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapModelVolumetoCP", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapModelVolumetoCP", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapModelVolumetoCP", "m_flOutputMax", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif