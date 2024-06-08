class GParticleNamedValueSource_t;

#ifndef _gcparticlenamedvaluesource_t_h
#define _gcparticlenamedvaluesource_t_h

#include "../../../scripting.h"

#include "../types/GPulseValueType_t.h"
#include "GParticleNamedValueConfiguration_t.h"

class GParticleNamedValueSource_t
{
private:
    void *m_ptr;

public:
    GParticleNamedValueSource_t() {}
    GParticleNamedValueSource_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "ParticleNamedValueSource_t", "m_Name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "ParticleNamedValueSource_t", "m_Name", true, value); }
    bool GetIsPublic() const { return GetSchemaValue<bool>(m_ptr, "ParticleNamedValueSource_t", "m_IsPublic"); }
    void SetIsPublic(bool value) { SetSchemaValue(m_ptr, "ParticleNamedValueSource_t", "m_IsPublic", true, value); }
    PulseValueType_t GetValueType() const { return GetSchemaValue<PulseValueType_t>(m_ptr, "ParticleNamedValueSource_t", "m_ValueType"); }
    void SetValueType(PulseValueType_t value) { SetSchemaValue(m_ptr, "ParticleNamedValueSource_t", "m_ValueType", true, value); }
    GParticleNamedValueConfiguration_t GetDefaultConfig() const { return GetSchemaValue<GParticleNamedValueConfiguration_t>(m_ptr, "ParticleNamedValueSource_t", "m_DefaultConfig"); }
    void SetDefaultConfig(GParticleNamedValueConfiguration_t value) { SetSchemaValue(m_ptr, "ParticleNamedValueSource_t", "m_DefaultConfig", true, value); }
    std::vector<GParticleNamedValueConfiguration_t> GetNamedConfigs() const { CUtlVector<GParticleNamedValueConfiguration_t>* vec = GetSchemaValue<CUtlVector<GParticleNamedValueConfiguration_t>*>(m_ptr, "ParticleNamedValueSource_t", "m_NamedConfigs"); std::vector<GParticleNamedValueConfiguration_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetNamedConfigs(std::vector<GParticleNamedValueConfiguration_t> value) { SetSchemaValueCUtlVector<GParticleNamedValueConfiguration_t>(m_ptr, "ParticleNamedValueSource_t", "m_NamedConfigs", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif