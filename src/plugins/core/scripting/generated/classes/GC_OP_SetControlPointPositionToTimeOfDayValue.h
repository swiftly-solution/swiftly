class GC_OP_SetControlPointPositionToTimeOfDayValue;

#ifndef _gcc_op_setcontrolpointpositiontotimeofdayvalue_h
#define _gcc_op_setcontrolpointpositiontotimeofdayvalue_h

#include "../../../scripting.h"




class GC_OP_SetControlPointPositionToTimeOfDayValue
{
private:
    void *m_ptr;

public:
    GC_OP_SetControlPointPositionToTimeOfDayValue() {}
    GC_OP_SetControlPointPositionToTimeOfDayValue(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointPositionToTimeOfDayValue", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointPositionToTimeOfDayValue", "m_nControlPointNumber", false, value); }
    std::string GetTimeOfDayParameter() const { return GetSchemaValue<char*>(m_ptr, "C_OP_SetControlPointPositionToTimeOfDayValue", "m_pszTimeOfDayParameter"); }
    void SetTimeOfDayParameter(std::string value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointPositionToTimeOfDayValue", "m_pszTimeOfDayParameter", false, value); }
    Vector GetDefaultValue() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_SetControlPointPositionToTimeOfDayValue", "m_vecDefaultValue"); }
    void SetDefaultValue(Vector value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointPositionToTimeOfDayValue", "m_vecDefaultValue", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif