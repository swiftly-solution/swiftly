class GC_INIT_CreateWithinBox;

#ifndef _gcc_init_createwithinbox_h
#define _gcc_init_createwithinbox_h

#include "../../../scripting.h"


#include "GCPerParticleVecInput.h"
#include "GCRandomNumberGeneratorParameters.h"

class GC_INIT_CreateWithinBox
{
private:
    void *m_ptr;

public:
    GC_INIT_CreateWithinBox() {}
    GC_INIT_CreateWithinBox(void *ptr) : m_ptr(ptr) {}

    GCPerParticleVecInput GetMin() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_INIT_CreateWithinBox", "m_vecMin"); }
    void SetMin(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateWithinBox", "m_vecMin", false, value); }
    GCPerParticleVecInput GetMax() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_INIT_CreateWithinBox", "m_vecMax"); }
    void SetMax(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateWithinBox", "m_vecMax", false, value); }
    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_CreateWithinBox", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_CreateWithinBox", "m_nControlPointNumber", false, value); }
    bool GetLocalSpace() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateWithinBox", "m_bLocalSpace"); }
    void SetLocalSpace(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateWithinBox", "m_bLocalSpace", false, value); }
    GCRandomNumberGeneratorParameters GetRandomnessParameters() const { return GetSchemaValue<GCRandomNumberGeneratorParameters>(m_ptr, "C_INIT_CreateWithinBox", "m_randomnessParameters"); }
    void SetRandomnessParameters(GCRandomNumberGeneratorParameters value) { SetSchemaValue(m_ptr, "C_INIT_CreateWithinBox", "m_randomnessParameters", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif