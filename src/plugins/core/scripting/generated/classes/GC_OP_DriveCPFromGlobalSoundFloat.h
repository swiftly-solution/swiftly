class GC_OP_DriveCPFromGlobalSoundFloat;

#ifndef _gcc_op_drivecpfromglobalsoundfloat_h
#define _gcc_op_drivecpfromglobalsoundfloat_h

#include "../../../scripting.h"




class GC_OP_DriveCPFromGlobalSoundFloat
{
private:
    void *m_ptr;

public:
    GC_OP_DriveCPFromGlobalSoundFloat() {}
    GC_OP_DriveCPFromGlobalSoundFloat(void *ptr) : m_ptr(ptr) {}

    int32_t GetOutputControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_DriveCPFromGlobalSoundFloat", "m_nOutputControlPoint"); }
    void SetOutputControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_DriveCPFromGlobalSoundFloat", "m_nOutputControlPoint", false, value); }
    int32_t GetOutputField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_DriveCPFromGlobalSoundFloat", "m_nOutputField"); }
    void SetOutputField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_DriveCPFromGlobalSoundFloat", "m_nOutputField", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_DriveCPFromGlobalSoundFloat", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_OP_DriveCPFromGlobalSoundFloat", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_DriveCPFromGlobalSoundFloat", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_OP_DriveCPFromGlobalSoundFloat", "m_flInputMax", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_DriveCPFromGlobalSoundFloat", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_OP_DriveCPFromGlobalSoundFloat", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_DriveCPFromGlobalSoundFloat", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_OP_DriveCPFromGlobalSoundFloat", "m_flOutputMax", false, value); }
    CUtlString GetStackName() const { return GetSchemaValue<CUtlString>(m_ptr, "C_OP_DriveCPFromGlobalSoundFloat", "m_StackName"); }
    void SetStackName(CUtlString value) { SetSchemaValue(m_ptr, "C_OP_DriveCPFromGlobalSoundFloat", "m_StackName", false, value); }
    CUtlString GetOperatorName() const { return GetSchemaValue<CUtlString>(m_ptr, "C_OP_DriveCPFromGlobalSoundFloat", "m_OperatorName"); }
    void SetOperatorName(CUtlString value) { SetSchemaValue(m_ptr, "C_OP_DriveCPFromGlobalSoundFloat", "m_OperatorName", false, value); }
    CUtlString GetFieldName() const { return GetSchemaValue<CUtlString>(m_ptr, "C_OP_DriveCPFromGlobalSoundFloat", "m_FieldName"); }
    void SetFieldName(CUtlString value) { SetSchemaValue(m_ptr, "C_OP_DriveCPFromGlobalSoundFloat", "m_FieldName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif