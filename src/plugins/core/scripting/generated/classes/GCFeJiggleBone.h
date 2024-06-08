class GCFeJiggleBone;

#ifndef _gccfejigglebone_h
#define _gccfejigglebone_h

#include "../../../scripting.h"




class GCFeJiggleBone
{
private:
    void *m_ptr;

public:
    GCFeJiggleBone() {}
    GCFeJiggleBone(void *ptr) : m_ptr(ptr) {}

    uint32_t GetFlags() const { return GetSchemaValue<uint32_t>(m_ptr, "CFeJiggleBone", "m_nFlags"); }
    void SetFlags(uint32_t value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_nFlags", false, value); }
    float GetLength() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flLength"); }
    void SetLength(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flLength", false, value); }
    float GetTipMass() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flTipMass"); }
    void SetTipMass(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flTipMass", false, value); }
    float GetYawStiffness() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flYawStiffness"); }
    void SetYawStiffness(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flYawStiffness", false, value); }
    float GetYawDamping() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flYawDamping"); }
    void SetYawDamping(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flYawDamping", false, value); }
    float GetPitchStiffness() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flPitchStiffness"); }
    void SetPitchStiffness(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flPitchStiffness", false, value); }
    float GetPitchDamping() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flPitchDamping"); }
    void SetPitchDamping(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flPitchDamping", false, value); }
    float GetAlongStiffness() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flAlongStiffness"); }
    void SetAlongStiffness(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flAlongStiffness", false, value); }
    float GetAlongDamping() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flAlongDamping"); }
    void SetAlongDamping(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flAlongDamping", false, value); }
    float GetAngleLimit() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flAngleLimit"); }
    void SetAngleLimit(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flAngleLimit", false, value); }
    float GetMinYaw() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flMinYaw"); }
    void SetMinYaw(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flMinYaw", false, value); }
    float GetMaxYaw() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flMaxYaw"); }
    void SetMaxYaw(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flMaxYaw", false, value); }
    float GetYawFriction() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flYawFriction"); }
    void SetYawFriction(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flYawFriction", false, value); }
    float GetYawBounce() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flYawBounce"); }
    void SetYawBounce(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flYawBounce", false, value); }
    float GetMinPitch() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flMinPitch"); }
    void SetMinPitch(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flMinPitch", false, value); }
    float GetMaxPitch() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flMaxPitch"); }
    void SetMaxPitch(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flMaxPitch", false, value); }
    float GetPitchFriction() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flPitchFriction"); }
    void SetPitchFriction(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flPitchFriction", false, value); }
    float GetPitchBounce() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flPitchBounce"); }
    void SetPitchBounce(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flPitchBounce", false, value); }
    float GetBaseMass() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseMass"); }
    void SetBaseMass(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseMass", false, value); }
    float GetBaseStiffness() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseStiffness"); }
    void SetBaseStiffness(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseStiffness", false, value); }
    float GetBaseDamping() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseDamping"); }
    void SetBaseDamping(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseDamping", false, value); }
    float GetBaseMinLeft() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseMinLeft"); }
    void SetBaseMinLeft(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseMinLeft", false, value); }
    float GetBaseMaxLeft() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseMaxLeft"); }
    void SetBaseMaxLeft(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseMaxLeft", false, value); }
    float GetBaseLeftFriction() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseLeftFriction"); }
    void SetBaseLeftFriction(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseLeftFriction", false, value); }
    float GetBaseMinUp() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseMinUp"); }
    void SetBaseMinUp(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseMinUp", false, value); }
    float GetBaseMaxUp() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseMaxUp"); }
    void SetBaseMaxUp(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseMaxUp", false, value); }
    float GetBaseUpFriction() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseUpFriction"); }
    void SetBaseUpFriction(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseUpFriction", false, value); }
    float GetBaseMinForward() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseMinForward"); }
    void SetBaseMinForward(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseMinForward", false, value); }
    float GetBaseMaxForward() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseMaxForward"); }
    void SetBaseMaxForward(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseMaxForward", false, value); }
    float GetBaseForwardFriction() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseForwardFriction"); }
    void SetBaseForwardFriction(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseForwardFriction", false, value); }
    float GetRadius0() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flRadius0"); }
    void SetRadius0(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flRadius0", false, value); }
    float GetRadius1() const { return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flRadius1"); }
    void SetRadius1(float value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flRadius1", false, value); }
    Vector GetPoint0() const { return GetSchemaValue<Vector>(m_ptr, "CFeJiggleBone", "m_vPoint0"); }
    void SetPoint0(Vector value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_vPoint0", false, value); }
    Vector GetPoint1() const { return GetSchemaValue<Vector>(m_ptr, "CFeJiggleBone", "m_vPoint1"); }
    void SetPoint1(Vector value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_vPoint1", false, value); }
    uint16_t GetCollisionMask() const { return GetSchemaValue<uint16_t>(m_ptr, "CFeJiggleBone", "m_nCollisionMask"); }
    void SetCollisionMask(uint16_t value) { SetSchemaValue(m_ptr, "CFeJiggleBone", "m_nCollisionMask", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif