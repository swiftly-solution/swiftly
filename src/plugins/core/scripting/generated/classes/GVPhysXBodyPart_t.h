class GVPhysXBodyPart_t;

#ifndef _gcvphysxbodypart_t_h
#define _gcvphysxbodypart_t_h

#include "../../../scripting.h"


#include "GVPhysics2ShapeDef_t.h"

class GVPhysXBodyPart_t
{
private:
    void *m_ptr;

public:
    GVPhysXBodyPart_t() {}
    GVPhysXBodyPart_t(void *ptr) : m_ptr(ptr) {}

    uint32_t GetFlags() const { return GetSchemaValue<uint32_t>(m_ptr, "VPhysXBodyPart_t", "m_nFlags"); }
    void SetFlags(uint32_t value) { SetSchemaValue(m_ptr, "VPhysXBodyPart_t", "m_nFlags", true, value); }
    float GetMass() const { return GetSchemaValue<float>(m_ptr, "VPhysXBodyPart_t", "m_flMass"); }
    void SetMass(float value) { SetSchemaValue(m_ptr, "VPhysXBodyPart_t", "m_flMass", true, value); }
    GVPhysics2ShapeDef_t GetRnShape() const { return GetSchemaValue<GVPhysics2ShapeDef_t>(m_ptr, "VPhysXBodyPart_t", "m_rnShape"); }
    void SetRnShape(GVPhysics2ShapeDef_t value) { SetSchemaValue(m_ptr, "VPhysXBodyPart_t", "m_rnShape", true, value); }
    uint16_t GetCollisionAttributeIndex() const { return GetSchemaValue<uint16_t>(m_ptr, "VPhysXBodyPart_t", "m_nCollisionAttributeIndex"); }
    void SetCollisionAttributeIndex(uint16_t value) { SetSchemaValue(m_ptr, "VPhysXBodyPart_t", "m_nCollisionAttributeIndex", true, value); }
    uint16_t GetReserved() const { return GetSchemaValue<uint16_t>(m_ptr, "VPhysXBodyPart_t", "m_nReserved"); }
    void SetReserved(uint16_t value) { SetSchemaValue(m_ptr, "VPhysXBodyPart_t", "m_nReserved", true, value); }
    float GetInertiaScale() const { return GetSchemaValue<float>(m_ptr, "VPhysXBodyPart_t", "m_flInertiaScale"); }
    void SetInertiaScale(float value) { SetSchemaValue(m_ptr, "VPhysXBodyPart_t", "m_flInertiaScale", true, value); }
    float GetLinearDamping() const { return GetSchemaValue<float>(m_ptr, "VPhysXBodyPart_t", "m_flLinearDamping"); }
    void SetLinearDamping(float value) { SetSchemaValue(m_ptr, "VPhysXBodyPart_t", "m_flLinearDamping", true, value); }
    float GetAngularDamping() const { return GetSchemaValue<float>(m_ptr, "VPhysXBodyPart_t", "m_flAngularDamping"); }
    void SetAngularDamping(float value) { SetSchemaValue(m_ptr, "VPhysXBodyPart_t", "m_flAngularDamping", true, value); }
    bool GetOverrideMassCenter() const { return GetSchemaValue<bool>(m_ptr, "VPhysXBodyPart_t", "m_bOverrideMassCenter"); }
    void SetOverrideMassCenter(bool value) { SetSchemaValue(m_ptr, "VPhysXBodyPart_t", "m_bOverrideMassCenter", true, value); }
    Vector GetMassCenterOverride() const { return GetSchemaValue<Vector>(m_ptr, "VPhysXBodyPart_t", "m_vMassCenterOverride"); }
    void SetMassCenterOverride(Vector value) { SetSchemaValue(m_ptr, "VPhysXBodyPart_t", "m_vMassCenterOverride", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif