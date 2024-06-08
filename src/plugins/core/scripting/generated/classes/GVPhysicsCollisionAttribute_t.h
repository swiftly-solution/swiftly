class GVPhysicsCollisionAttribute_t;

#ifndef _gcvphysicscollisionattribute_t_h
#define _gcvphysicscollisionattribute_t_h

#include "../../../scripting.h"




class GVPhysicsCollisionAttribute_t
{
private:
    void *m_ptr;

public:
    GVPhysicsCollisionAttribute_t() {}
    GVPhysicsCollisionAttribute_t(void *ptr) : m_ptr(ptr) {}

    uint64_t GetInteractsAs() const { return GetSchemaValue<uint64_t>(m_ptr, "VPhysicsCollisionAttribute_t", "m_nInteractsAs"); }
    void SetInteractsAs(uint64_t value) { SetSchemaValue(m_ptr, "VPhysicsCollisionAttribute_t", "m_nInteractsAs", true, value); }
    uint64_t GetInteractsWith() const { return GetSchemaValue<uint64_t>(m_ptr, "VPhysicsCollisionAttribute_t", "m_nInteractsWith"); }
    void SetInteractsWith(uint64_t value) { SetSchemaValue(m_ptr, "VPhysicsCollisionAttribute_t", "m_nInteractsWith", true, value); }
    uint64_t GetInteractsExclude() const { return GetSchemaValue<uint64_t>(m_ptr, "VPhysicsCollisionAttribute_t", "m_nInteractsExclude"); }
    void SetInteractsExclude(uint64_t value) { SetSchemaValue(m_ptr, "VPhysicsCollisionAttribute_t", "m_nInteractsExclude", true, value); }
    uint32_t GetEntityId() const { return GetSchemaValue<uint32_t>(m_ptr, "VPhysicsCollisionAttribute_t", "m_nEntityId"); }
    void SetEntityId(uint32_t value) { SetSchemaValue(m_ptr, "VPhysicsCollisionAttribute_t", "m_nEntityId", true, value); }
    uint32_t GetOwnerId() const { return GetSchemaValue<uint32_t>(m_ptr, "VPhysicsCollisionAttribute_t", "m_nOwnerId"); }
    void SetOwnerId(uint32_t value) { SetSchemaValue(m_ptr, "VPhysicsCollisionAttribute_t", "m_nOwnerId", true, value); }
    uint16_t GetHierarchyId() const { return GetSchemaValue<uint16_t>(m_ptr, "VPhysicsCollisionAttribute_t", "m_nHierarchyId"); }
    void SetHierarchyId(uint16_t value) { SetSchemaValue(m_ptr, "VPhysicsCollisionAttribute_t", "m_nHierarchyId", true, value); }
    uint8_t GetCollisionGroup() const { return GetSchemaValue<uint8_t>(m_ptr, "VPhysicsCollisionAttribute_t", "m_nCollisionGroup"); }
    void SetCollisionGroup(uint8_t value) { SetSchemaValue(m_ptr, "VPhysicsCollisionAttribute_t", "m_nCollisionGroup", true, value); }
    uint8_t GetCollisionFunctionMask() const { return GetSchemaValue<uint8_t>(m_ptr, "VPhysicsCollisionAttribute_t", "m_nCollisionFunctionMask"); }
    void SetCollisionFunctionMask(uint8_t value) { SetSchemaValue(m_ptr, "VPhysicsCollisionAttribute_t", "m_nCollisionFunctionMask", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif