class GCRagdollPropAttached;

#ifndef _gccragdollpropattached_h
#define _gccragdollpropattached_h

#include "../../../scripting.h"




class GCRagdollPropAttached
{
private:
    void *m_ptr;

public:
    GCRagdollPropAttached() {}
    GCRagdollPropAttached(void *ptr) : m_ptr(ptr) {}

    uint32_t GetBoneIndexAttached() const { return GetSchemaValue<uint32_t>(m_ptr, "CRagdollPropAttached", "m_boneIndexAttached"); }
    void SetBoneIndexAttached(uint32_t value) { SetSchemaValue(m_ptr, "CRagdollPropAttached", "m_boneIndexAttached", false, value); }
    uint32_t GetRagdollAttachedObjectIndex() const { return GetSchemaValue<uint32_t>(m_ptr, "CRagdollPropAttached", "m_ragdollAttachedObjectIndex"); }
    void SetRagdollAttachedObjectIndex(uint32_t value) { SetSchemaValue(m_ptr, "CRagdollPropAttached", "m_ragdollAttachedObjectIndex", false, value); }
    Vector GetAttachmentPointBoneSpace() const { return GetSchemaValue<Vector>(m_ptr, "CRagdollPropAttached", "m_attachmentPointBoneSpace"); }
    void SetAttachmentPointBoneSpace(Vector value) { SetSchemaValue(m_ptr, "CRagdollPropAttached", "m_attachmentPointBoneSpace", false, value); }
    Vector GetAttachmentPointRagdollSpace() const { return GetSchemaValue<Vector>(m_ptr, "CRagdollPropAttached", "m_attachmentPointRagdollSpace"); }
    void SetAttachmentPointRagdollSpace(Vector value) { SetSchemaValue(m_ptr, "CRagdollPropAttached", "m_attachmentPointRagdollSpace", false, value); }
    bool GetShouldDetach() const { return GetSchemaValue<bool>(m_ptr, "CRagdollPropAttached", "m_bShouldDetach"); }
    void SetShouldDetach(bool value) { SetSchemaValue(m_ptr, "CRagdollPropAttached", "m_bShouldDetach", false, value); }
    bool GetShouldDeleteAttachedActivationRecord() const { return GetSchemaValue<bool>(m_ptr, "CRagdollPropAttached", "m_bShouldDeleteAttachedActivationRecord"); }
    void SetShouldDeleteAttachedActivationRecord(bool value) { SetSchemaValue(m_ptr, "CRagdollPropAttached", "m_bShouldDeleteAttachedActivationRecord", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif