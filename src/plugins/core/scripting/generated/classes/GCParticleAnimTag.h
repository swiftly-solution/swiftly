class GCParticleAnimTag;

#ifndef _gccparticleanimtag_h
#define _gccparticleanimtag_h

#include "../../../scripting.h"

#include "../types/GParticleAttachment_t.h"


class GCParticleAnimTag
{
private:
    void *m_ptr;

public:
    GCParticleAnimTag() {}
    GCParticleAnimTag(void *ptr) : m_ptr(ptr) {}

    CUtlString GetParticleSystemName() const { return GetSchemaValue<CUtlString>(m_ptr, "CParticleAnimTag", "m_particleSystemName"); }
    void SetParticleSystemName(CUtlString value) { SetSchemaValue(m_ptr, "CParticleAnimTag", "m_particleSystemName", false, value); }
    CUtlString GetConfigName() const { return GetSchemaValue<CUtlString>(m_ptr, "CParticleAnimTag", "m_configName"); }
    void SetConfigName(CUtlString value) { SetSchemaValue(m_ptr, "CParticleAnimTag", "m_configName", false, value); }
    bool GetDetachFromOwner() const { return GetSchemaValue<bool>(m_ptr, "CParticleAnimTag", "m_bDetachFromOwner"); }
    void SetDetachFromOwner(bool value) { SetSchemaValue(m_ptr, "CParticleAnimTag", "m_bDetachFromOwner", false, value); }
    bool GetStopWhenTagEnds() const { return GetSchemaValue<bool>(m_ptr, "CParticleAnimTag", "m_bStopWhenTagEnds"); }
    void SetStopWhenTagEnds(bool value) { SetSchemaValue(m_ptr, "CParticleAnimTag", "m_bStopWhenTagEnds", false, value); }
    bool GetTagEndStopIsInstant() const { return GetSchemaValue<bool>(m_ptr, "CParticleAnimTag", "m_bTagEndStopIsInstant"); }
    void SetTagEndStopIsInstant(bool value) { SetSchemaValue(m_ptr, "CParticleAnimTag", "m_bTagEndStopIsInstant", false, value); }
    CUtlString GetAttachmentName() const { return GetSchemaValue<CUtlString>(m_ptr, "CParticleAnimTag", "m_attachmentName"); }
    void SetAttachmentName(CUtlString value) { SetSchemaValue(m_ptr, "CParticleAnimTag", "m_attachmentName", false, value); }
    ParticleAttachment_t GetAttachmentType() const { return GetSchemaValue<ParticleAttachment_t>(m_ptr, "CParticleAnimTag", "m_attachmentType"); }
    void SetAttachmentType(ParticleAttachment_t value) { SetSchemaValue(m_ptr, "CParticleAnimTag", "m_attachmentType", false, value); }
    CUtlString GetAttachmentCP1Name() const { return GetSchemaValue<CUtlString>(m_ptr, "CParticleAnimTag", "m_attachmentCP1Name"); }
    void SetAttachmentCP1Name(CUtlString value) { SetSchemaValue(m_ptr, "CParticleAnimTag", "m_attachmentCP1Name", false, value); }
    ParticleAttachment_t GetAttachmentCP1Type() const { return GetSchemaValue<ParticleAttachment_t>(m_ptr, "CParticleAnimTag", "m_attachmentCP1Type"); }
    void SetAttachmentCP1Type(ParticleAttachment_t value) { SetSchemaValue(m_ptr, "CParticleAnimTag", "m_attachmentCP1Type", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif