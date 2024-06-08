class GFeRigidColliderIndices_t;

#ifndef _gcferigidcolliderindices_t_h
#define _gcferigidcolliderindices_t_h

#include "../../../scripting.h"




class GFeRigidColliderIndices_t
{
private:
    void *m_ptr;

public:
    GFeRigidColliderIndices_t() {}
    GFeRigidColliderIndices_t(void *ptr) : m_ptr(ptr) {}

    uint16_t GetTaperedCapsuleRigidIndex() const { return GetSchemaValue<uint16_t>(m_ptr, "FeRigidColliderIndices_t", "m_nTaperedCapsuleRigidIndex"); }
    void SetTaperedCapsuleRigidIndex(uint16_t value) { SetSchemaValue(m_ptr, "FeRigidColliderIndices_t", "m_nTaperedCapsuleRigidIndex", true, value); }
    uint16_t GetSphereRigidIndex() const { return GetSchemaValue<uint16_t>(m_ptr, "FeRigidColliderIndices_t", "m_nSphereRigidIndex"); }
    void SetSphereRigidIndex(uint16_t value) { SetSchemaValue(m_ptr, "FeRigidColliderIndices_t", "m_nSphereRigidIndex", true, value); }
    uint16_t GetBoxRigidIndex() const { return GetSchemaValue<uint16_t>(m_ptr, "FeRigidColliderIndices_t", "m_nBoxRigidIndex"); }
    void SetBoxRigidIndex(uint16_t value) { SetSchemaValue(m_ptr, "FeRigidColliderIndices_t", "m_nBoxRigidIndex", true, value); }
    uint16_t GetCollisionPlaneIndex() const { return GetSchemaValue<uint16_t>(m_ptr, "FeRigidColliderIndices_t", "m_nCollisionPlaneIndex"); }
    void SetCollisionPlaneIndex(uint16_t value) { SetSchemaValue(m_ptr, "FeRigidColliderIndices_t", "m_nCollisionPlaneIndex", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif