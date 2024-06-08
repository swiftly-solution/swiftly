class GC_INIT_RemapInitialVisibilityScalar;

#ifndef _gcc_init_remapinitialvisibilityscalar_h
#define _gcc_init_remapinitialvisibilityscalar_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_INIT_RemapInitialVisibilityScalar
{
private:
    void *m_ptr;

public:
    GC_INIT_RemapInitialVisibilityScalar() {}
    GC_INIT_RemapInitialVisibilityScalar(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_RemapInitialVisibilityScalar", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapInitialVisibilityScalar", "m_nFieldOutput", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapInitialVisibilityScalar", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapInitialVisibilityScalar", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapInitialVisibilityScalar", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapInitialVisibilityScalar", "m_flInputMax", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapInitialVisibilityScalar", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapInitialVisibilityScalar", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapInitialVisibilityScalar", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapInitialVisibilityScalar", "m_flOutputMax", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif