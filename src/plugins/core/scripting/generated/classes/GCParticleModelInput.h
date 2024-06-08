class GCParticleModelInput;

#ifndef _gccparticlemodelinput_h
#define _gccparticlemodelinput_h

#include "../../../scripting.h"

#include "../types/GParticleModelType_t.h"


class GCParticleModelInput
{
private:
    void *m_ptr;

public:
    GCParticleModelInput() {}
    GCParticleModelInput(void *ptr) : m_ptr(ptr) {}

    ParticleModelType_t GetType() const { return GetSchemaValue<ParticleModelType_t>(m_ptr, "CParticleModelInput", "m_nType"); }
    void SetType(ParticleModelType_t value) { SetSchemaValue(m_ptr, "CParticleModelInput", "m_nType", false, value); }
    int32_t GetControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleModelInput", "m_nControlPoint"); }
    void SetControlPoint(int32_t value) { SetSchemaValue(m_ptr, "CParticleModelInput", "m_nControlPoint", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif