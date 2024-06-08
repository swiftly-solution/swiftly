class GParticlePreviewBodyGroup_t;

#ifndef _gcparticlepreviewbodygroup_t_h
#define _gcparticlepreviewbodygroup_t_h

#include "../../../scripting.h"




class GParticlePreviewBodyGroup_t
{
private:
    void *m_ptr;

public:
    GParticlePreviewBodyGroup_t() {}
    GParticlePreviewBodyGroup_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetBodyGroupName() const { return GetSchemaValue<CUtlString>(m_ptr, "ParticlePreviewBodyGroup_t", "m_bodyGroupName"); }
    void SetBodyGroupName(CUtlString value) { SetSchemaValue(m_ptr, "ParticlePreviewBodyGroup_t", "m_bodyGroupName", true, value); }
    int32_t GetValue() const { return GetSchemaValue<int32_t>(m_ptr, "ParticlePreviewBodyGroup_t", "m_nValue"); }
    void SetValue(int32_t value) { SetSchemaValue(m_ptr, "ParticlePreviewBodyGroup_t", "m_nValue", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif