class GC_INIT_SetRigidAttachment;

#ifndef _gcc_init_setrigidattachment_h
#define _gcc_init_setrigidattachment_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_INIT_SetRigidAttachment
{
private:
    void *m_ptr;

public:
    GC_INIT_SetRigidAttachment() {}
    GC_INIT_SetRigidAttachment(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_SetRigidAttachment", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_SetRigidAttachment", "m_nControlPointNumber", false, value); }
    GParticleAttributeIndex_t GetFieldInput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_SetRigidAttachment", "m_nFieldInput"); }
    void SetFieldInput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_SetRigidAttachment", "m_nFieldInput", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_SetRigidAttachment", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_SetRigidAttachment", "m_nFieldOutput", false, value); }
    bool GetLocalSpace() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_SetRigidAttachment", "m_bLocalSpace"); }
    void SetLocalSpace(bool value) { SetSchemaValue(m_ptr, "C_INIT_SetRigidAttachment", "m_bLocalSpace", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif