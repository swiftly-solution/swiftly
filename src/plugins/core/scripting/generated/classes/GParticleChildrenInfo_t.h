class GParticleChildrenInfo_t;

#ifndef _gcparticlechildreninfo_t_h
#define _gcparticlechildreninfo_t_h

#include "../../../scripting.h"

#include "../types/GParticleDetailLevel_t.h"


class GParticleChildrenInfo_t
{
private:
    void *m_ptr;

public:
    GParticleChildrenInfo_t() {}
    GParticleChildrenInfo_t(void *ptr) : m_ptr(ptr) {}

    float GetDelay() const { return GetSchemaValue<float>(m_ptr, "ParticleChildrenInfo_t", "m_flDelay"); }
    void SetDelay(float value) { SetSchemaValue(m_ptr, "ParticleChildrenInfo_t", "m_flDelay", true, value); }
    bool GetEndCap() const { return GetSchemaValue<bool>(m_ptr, "ParticleChildrenInfo_t", "m_bEndCap"); }
    void SetEndCap(bool value) { SetSchemaValue(m_ptr, "ParticleChildrenInfo_t", "m_bEndCap", true, value); }
    bool GetDisableChild() const { return GetSchemaValue<bool>(m_ptr, "ParticleChildrenInfo_t", "m_bDisableChild"); }
    void SetDisableChild(bool value) { SetSchemaValue(m_ptr, "ParticleChildrenInfo_t", "m_bDisableChild", true, value); }
    ParticleDetailLevel_t GetDetailLevel() const { return GetSchemaValue<ParticleDetailLevel_t>(m_ptr, "ParticleChildrenInfo_t", "m_nDetailLevel"); }
    void SetDetailLevel(ParticleDetailLevel_t value) { SetSchemaValue(m_ptr, "ParticleChildrenInfo_t", "m_nDetailLevel", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif