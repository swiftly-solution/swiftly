class GCCollisionProperty;

#ifndef _gcccollisionproperty_h
#define _gcccollisionproperty_h

#include "../../../scripting.h"

#include "../types/GSurroundingBoundsType_t.h"
#include "GVPhysicsCollisionAttribute_t.h"

class GCCollisionProperty
{
private:
    void *m_ptr;

public:
    GCCollisionProperty() {}
    GCCollisionProperty(void *ptr) : m_ptr(ptr) {}

    GVPhysicsCollisionAttribute_t GetCollisionAttribute() const { return GetSchemaValue<GVPhysicsCollisionAttribute_t>(m_ptr, "CCollisionProperty", "m_collisionAttribute"); }
    void SetCollisionAttribute(GVPhysicsCollisionAttribute_t value) { SetSchemaValue(m_ptr, "CCollisionProperty", "m_collisionAttribute", false, value); }
    Vector GetMins() const { return GetSchemaValue<Vector>(m_ptr, "CCollisionProperty", "m_vecMins"); }
    void SetMins(Vector value) { SetSchemaValue(m_ptr, "CCollisionProperty", "m_vecMins", false, value); }
    Vector GetMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CCollisionProperty", "m_vecMaxs"); }
    void SetMaxs(Vector value) { SetSchemaValue(m_ptr, "CCollisionProperty", "m_vecMaxs", false, value); }
    uint8_t GetSolidFlags() const { return GetSchemaValue<uint8_t>(m_ptr, "CCollisionProperty", "m_usSolidFlags"); }
    void SetSolidFlags(uint8_t value) { SetSchemaValue(m_ptr, "CCollisionProperty", "m_usSolidFlags", false, value); }
    SolidType_t GetSolidType() const { return GetSchemaValue<SolidType_t>(m_ptr, "CCollisionProperty", "m_nSolidType"); }
    void SetSolidType(SolidType_t value) { SetSchemaValue(m_ptr, "CCollisionProperty", "m_nSolidType", false, value); }
    uint8_t GetTriggerBloat() const { return GetSchemaValue<uint8_t>(m_ptr, "CCollisionProperty", "m_triggerBloat"); }
    void SetTriggerBloat(uint8_t value) { SetSchemaValue(m_ptr, "CCollisionProperty", "m_triggerBloat", false, value); }
    SurroundingBoundsType_t GetSurroundType() const { return GetSchemaValue<SurroundingBoundsType_t>(m_ptr, "CCollisionProperty", "m_nSurroundType"); }
    void SetSurroundType(SurroundingBoundsType_t value) { SetSchemaValue(m_ptr, "CCollisionProperty", "m_nSurroundType", false, value); }
    uint8_t GetCollisionGroup() const { return GetSchemaValue<uint8_t>(m_ptr, "CCollisionProperty", "m_CollisionGroup"); }
    void SetCollisionGroup(uint8_t value) { SetSchemaValue(m_ptr, "CCollisionProperty", "m_CollisionGroup", false, value); }
    uint8_t GetEnablePhysics() const { return GetSchemaValue<uint8_t>(m_ptr, "CCollisionProperty", "m_nEnablePhysics"); }
    void SetEnablePhysics(uint8_t value) { SetSchemaValue(m_ptr, "CCollisionProperty", "m_nEnablePhysics", false, value); }
    float GetBoundingRadius() const { return GetSchemaValue<float>(m_ptr, "CCollisionProperty", "m_flBoundingRadius"); }
    void SetBoundingRadius(float value) { SetSchemaValue(m_ptr, "CCollisionProperty", "m_flBoundingRadius", false, value); }
    Vector GetSpecifiedSurroundingMins() const { return GetSchemaValue<Vector>(m_ptr, "CCollisionProperty", "m_vecSpecifiedSurroundingMins"); }
    void SetSpecifiedSurroundingMins(Vector value) { SetSchemaValue(m_ptr, "CCollisionProperty", "m_vecSpecifiedSurroundingMins", false, value); }
    Vector GetSpecifiedSurroundingMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CCollisionProperty", "m_vecSpecifiedSurroundingMaxs"); }
    void SetSpecifiedSurroundingMaxs(Vector value) { SetSchemaValue(m_ptr, "CCollisionProperty", "m_vecSpecifiedSurroundingMaxs", false, value); }
    Vector GetSurroundingMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CCollisionProperty", "m_vecSurroundingMaxs"); }
    void SetSurroundingMaxs(Vector value) { SetSchemaValue(m_ptr, "CCollisionProperty", "m_vecSurroundingMaxs", false, value); }
    Vector GetSurroundingMins() const { return GetSchemaValue<Vector>(m_ptr, "CCollisionProperty", "m_vecSurroundingMins"); }
    void SetSurroundingMins(Vector value) { SetSchemaValue(m_ptr, "CCollisionProperty", "m_vecSurroundingMins", false, value); }
    Vector GetCapsuleCenter1() const { return GetSchemaValue<Vector>(m_ptr, "CCollisionProperty", "m_vCapsuleCenter1"); }
    void SetCapsuleCenter1(Vector value) { SetSchemaValue(m_ptr, "CCollisionProperty", "m_vCapsuleCenter1", false, value); }
    Vector GetCapsuleCenter2() const { return GetSchemaValue<Vector>(m_ptr, "CCollisionProperty", "m_vCapsuleCenter2"); }
    void SetCapsuleCenter2(Vector value) { SetSchemaValue(m_ptr, "CCollisionProperty", "m_vCapsuleCenter2", false, value); }
    float GetCapsuleRadius() const { return GetSchemaValue<float>(m_ptr, "CCollisionProperty", "m_flCapsuleRadius"); }
    void SetCapsuleRadius(float value) { SetSchemaValue(m_ptr, "CCollisionProperty", "m_flCapsuleRadius", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif