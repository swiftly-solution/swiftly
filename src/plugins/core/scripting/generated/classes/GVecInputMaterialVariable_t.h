class GVecInputMaterialVariable_t;

#ifndef _gcvecinputmaterialvariable_t_h
#define _gcvecinputmaterialvariable_t_h

#include "../../../scripting.h"




class GVecInputMaterialVariable_t
{
private:
    void *m_ptr;

public:
    GVecInputMaterialVariable_t() {}
    GVecInputMaterialVariable_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetStrVariable() const { return GetSchemaValue<CUtlString>(m_ptr, "VecInputMaterialVariable_t", "m_strVariable"); }
    void SetStrVariable(CUtlString value) { SetSchemaValue(m_ptr, "VecInputMaterialVariable_t", "m_strVariable", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif