class GParticleNamedValueConfiguration_t;

#ifndef _gcparticlenamedvalueconfiguration_t_h
#define _gcparticlenamedvalueconfiguration_t_h

#include "../../../scripting.h"

#include "../types/GParticleAttachment_t.h"


class GParticleNamedValueConfiguration_t
{
private:
    void *m_ptr;

public:
    GParticleNamedValueConfiguration_t() {}
    GParticleNamedValueConfiguration_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetConfigName() const { return GetSchemaValue<CUtlString>(m_ptr, "ParticleNamedValueConfiguration_t", "m_ConfigName"); }
    void SetConfigName(CUtlString value) { SetSchemaValue(m_ptr, "ParticleNamedValueConfiguration_t", "m_ConfigName", true, value); }
    ParticleAttachment_t GetAttachType() const { return GetSchemaValue<ParticleAttachment_t>(m_ptr, "ParticleNamedValueConfiguration_t", "m_iAttachType"); }
    void SetAttachType(ParticleAttachment_t value) { SetSchemaValue(m_ptr, "ParticleNamedValueConfiguration_t", "m_iAttachType", true, value); }
    CUtlString GetBoundEntityPath() const { return GetSchemaValue<CUtlString>(m_ptr, "ParticleNamedValueConfiguration_t", "m_BoundEntityPath"); }
    void SetBoundEntityPath(CUtlString value) { SetSchemaValue(m_ptr, "ParticleNamedValueConfiguration_t", "m_BoundEntityPath", true, value); }
    CUtlString GetStrEntityScope() const { return GetSchemaValue<CUtlString>(m_ptr, "ParticleNamedValueConfiguration_t", "m_strEntityScope"); }
    void SetStrEntityScope(CUtlString value) { SetSchemaValue(m_ptr, "ParticleNamedValueConfiguration_t", "m_strEntityScope", true, value); }
    CUtlString GetStrAttachmentName() const { return GetSchemaValue<CUtlString>(m_ptr, "ParticleNamedValueConfiguration_t", "m_strAttachmentName"); }
    void SetStrAttachmentName(CUtlString value) { SetSchemaValue(m_ptr, "ParticleNamedValueConfiguration_t", "m_strAttachmentName", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif