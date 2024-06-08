class GMaterialVariable_t;

#ifndef _gcmaterialvariable_t_h
#define _gcmaterialvariable_t_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GMaterialVariable_t
{
private:
    void *m_ptr;

public:
    GMaterialVariable_t() {}
    GMaterialVariable_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetStrVariable() const { return GetSchemaValue<CUtlString>(m_ptr, "MaterialVariable_t", "m_strVariable"); }
    void SetStrVariable(CUtlString value) { SetSchemaValue(m_ptr, "MaterialVariable_t", "m_strVariable", true, value); }
    GParticleAttributeIndex_t GetVariableField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "MaterialVariable_t", "m_nVariableField"); }
    void SetVariableField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "MaterialVariable_t", "m_nVariableField", true, value); }
    float GetScale() const { return GetSchemaValue<float>(m_ptr, "MaterialVariable_t", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "MaterialVariable_t", "m_flScale", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif