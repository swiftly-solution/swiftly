class GParticleControlPointDriver_t;

#ifndef _gcparticlecontrolpointdriver_t_h
#define _gcparticlecontrolpointdriver_t_h

#include "../../../scripting.h"

#include "../types/GParticleAttachment_t.h"


class GParticleControlPointDriver_t
{
private:
    void *m_ptr;

public:
    GParticleControlPointDriver_t() {}
    GParticleControlPointDriver_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "ParticleControlPointDriver_t", "m_iControlPoint"); }
    void SetControlPoint(int32_t value) { SetSchemaValue(m_ptr, "ParticleControlPointDriver_t", "m_iControlPoint", true, value); }
    ParticleAttachment_t GetAttachType() const { return GetSchemaValue<ParticleAttachment_t>(m_ptr, "ParticleControlPointDriver_t", "m_iAttachType"); }
    void SetAttachType(ParticleAttachment_t value) { SetSchemaValue(m_ptr, "ParticleControlPointDriver_t", "m_iAttachType", true, value); }
    CUtlString GetAttachmentName() const { return GetSchemaValue<CUtlString>(m_ptr, "ParticleControlPointDriver_t", "m_attachmentName"); }
    void SetAttachmentName(CUtlString value) { SetSchemaValue(m_ptr, "ParticleControlPointDriver_t", "m_attachmentName", true, value); }
    Vector GetOffset() const { return GetSchemaValue<Vector>(m_ptr, "ParticleControlPointDriver_t", "m_vecOffset"); }
    void SetOffset(Vector value) { SetSchemaValue(m_ptr, "ParticleControlPointDriver_t", "m_vecOffset", true, value); }
    QAngle GetOffset1() const { return GetSchemaValue<QAngle>(m_ptr, "ParticleControlPointDriver_t", "m_angOffset"); }
    void SetOffset1(QAngle value) { SetSchemaValue(m_ptr, "ParticleControlPointDriver_t", "m_angOffset", true, value); }
    CUtlString GetEntityName() const { return GetSchemaValue<CUtlString>(m_ptr, "ParticleControlPointDriver_t", "m_entityName"); }
    void SetEntityName(CUtlString value) { SetSchemaValue(m_ptr, "ParticleControlPointDriver_t", "m_entityName", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif