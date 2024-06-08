class GC_INIT_RemapParticleCountToNamedModelElementScalar;

#ifndef _gcc_init_remapparticlecounttonamedmodelelementscalar_h
#define _gcc_init_remapparticlecounttonamedmodelelementscalar_h

#include "../../../scripting.h"




class GC_INIT_RemapParticleCountToNamedModelElementScalar
{
private:
    void *m_ptr;

public:
    GC_INIT_RemapParticleCountToNamedModelElementScalar() {}
    GC_INIT_RemapParticleCountToNamedModelElementScalar(void *ptr) : m_ptr(ptr) {}

    CUtlString GetOutputMinName() const { return GetSchemaValue<CUtlString>(m_ptr, "C_INIT_RemapParticleCountToNamedModelElementScalar", "m_outputMinName"); }
    void SetOutputMinName(CUtlString value) { SetSchemaValue(m_ptr, "C_INIT_RemapParticleCountToNamedModelElementScalar", "m_outputMinName", false, value); }
    CUtlString GetOutputMaxName() const { return GetSchemaValue<CUtlString>(m_ptr, "C_INIT_RemapParticleCountToNamedModelElementScalar", "m_outputMaxName"); }
    void SetOutputMaxName(CUtlString value) { SetSchemaValue(m_ptr, "C_INIT_RemapParticleCountToNamedModelElementScalar", "m_outputMaxName", false, value); }
    bool GetModelFromRenderer() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RemapParticleCountToNamedModelElementScalar", "m_bModelFromRenderer"); }
    void SetModelFromRenderer(bool value) { SetSchemaValue(m_ptr, "C_INIT_RemapParticleCountToNamedModelElementScalar", "m_bModelFromRenderer", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif