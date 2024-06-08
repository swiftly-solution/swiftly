class GCompMatMutatorCondition_t;

#ifndef _gccompmatmutatorcondition_t_h
#define _gccompmatmutatorcondition_t_h

#include "../../../scripting.h"

#include "../types/GCompMatPropertyMutatorConditionType_t.h"


class GCompMatMutatorCondition_t
{
private:
    void *m_ptr;

public:
    GCompMatMutatorCondition_t() {}
    GCompMatMutatorCondition_t(void *ptr) : m_ptr(ptr) {}

    CompMatPropertyMutatorConditionType_t GetMutatorCondition() const { return GetSchemaValue<CompMatPropertyMutatorConditionType_t>(m_ptr, "CompMatMutatorCondition_t", "m_nMutatorCondition"); }
    void SetMutatorCondition(CompMatPropertyMutatorConditionType_t value) { SetSchemaValue(m_ptr, "CompMatMutatorCondition_t", "m_nMutatorCondition", true, value); }
    CUtlString GetStrMutatorConditionContainerName() const { return GetSchemaValue<CUtlString>(m_ptr, "CompMatMutatorCondition_t", "m_strMutatorConditionContainerName"); }
    void SetStrMutatorConditionContainerName(CUtlString value) { SetSchemaValue(m_ptr, "CompMatMutatorCondition_t", "m_strMutatorConditionContainerName", true, value); }
    CUtlString GetStrMutatorConditionContainerVarName() const { return GetSchemaValue<CUtlString>(m_ptr, "CompMatMutatorCondition_t", "m_strMutatorConditionContainerVarName"); }
    void SetStrMutatorConditionContainerVarName(CUtlString value) { SetSchemaValue(m_ptr, "CompMatMutatorCondition_t", "m_strMutatorConditionContainerVarName", true, value); }
    CUtlString GetStrMutatorConditionContainerVarValue() const { return GetSchemaValue<CUtlString>(m_ptr, "CompMatMutatorCondition_t", "m_strMutatorConditionContainerVarValue"); }
    void SetStrMutatorConditionContainerVarValue(CUtlString value) { SetSchemaValue(m_ptr, "CompMatMutatorCondition_t", "m_strMutatorConditionContainerVarValue", true, value); }
    bool GetPassWhenTrue() const { return GetSchemaValue<bool>(m_ptr, "CompMatMutatorCondition_t", "m_bPassWhenTrue"); }
    void SetPassWhenTrue(bool value) { SetSchemaValue(m_ptr, "CompMatMutatorCondition_t", "m_bPassWhenTrue", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif