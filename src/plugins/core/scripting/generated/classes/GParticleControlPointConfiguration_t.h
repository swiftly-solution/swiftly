class GParticleControlPointConfiguration_t;

#ifndef _gcparticlecontrolpointconfiguration_t_h
#define _gcparticlecontrolpointconfiguration_t_h

#include "../../../scripting.h"


#include "GParticleControlPointDriver_t.h"
#include "GParticlePreviewState_t.h"

class GParticleControlPointConfiguration_t
{
private:
    void *m_ptr;

public:
    GParticleControlPointConfiguration_t() {}
    GParticleControlPointConfiguration_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "ParticleControlPointConfiguration_t", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "ParticleControlPointConfiguration_t", "m_name", true, value); }
    std::vector<GParticleControlPointDriver_t> GetDrivers() const { CUtlVector<GParticleControlPointDriver_t>* vec = GetSchemaValue<CUtlVector<GParticleControlPointDriver_t>*>(m_ptr, "ParticleControlPointConfiguration_t", "m_drivers"); std::vector<GParticleControlPointDriver_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetDrivers(std::vector<GParticleControlPointDriver_t> value) { SetSchemaValueCUtlVector<GParticleControlPointDriver_t>(m_ptr, "ParticleControlPointConfiguration_t", "m_drivers", true, value); }
    GParticlePreviewState_t GetPreviewState() const { return GetSchemaValue<GParticlePreviewState_t>(m_ptr, "ParticleControlPointConfiguration_t", "m_previewState"); }
    void SetPreviewState(GParticlePreviewState_t value) { SetSchemaValue(m_ptr, "ParticleControlPointConfiguration_t", "m_previewState", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif