#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFeJiggleBone::GCFeJiggleBone(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFeJiggleBone::GCFeJiggleBone(void *ptr) {
    m_ptr = ptr;
}
uint32_t GCFeJiggleBone::GetFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CFeJiggleBone", "m_nFlags");
}
void GCFeJiggleBone::SetFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_nFlags", false, value);
}
float GCFeJiggleBone::GetLength() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flLength");
}
void GCFeJiggleBone::SetLength(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flLength", false, value);
}
float GCFeJiggleBone::GetTipMass() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flTipMass");
}
void GCFeJiggleBone::SetTipMass(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flTipMass", false, value);
}
float GCFeJiggleBone::GetYawStiffness() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flYawStiffness");
}
void GCFeJiggleBone::SetYawStiffness(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flYawStiffness", false, value);
}
float GCFeJiggleBone::GetYawDamping() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flYawDamping");
}
void GCFeJiggleBone::SetYawDamping(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flYawDamping", false, value);
}
float GCFeJiggleBone::GetPitchStiffness() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flPitchStiffness");
}
void GCFeJiggleBone::SetPitchStiffness(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flPitchStiffness", false, value);
}
float GCFeJiggleBone::GetPitchDamping() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flPitchDamping");
}
void GCFeJiggleBone::SetPitchDamping(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flPitchDamping", false, value);
}
float GCFeJiggleBone::GetAlongStiffness() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flAlongStiffness");
}
void GCFeJiggleBone::SetAlongStiffness(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flAlongStiffness", false, value);
}
float GCFeJiggleBone::GetAlongDamping() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flAlongDamping");
}
void GCFeJiggleBone::SetAlongDamping(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flAlongDamping", false, value);
}
float GCFeJiggleBone::GetAngleLimit() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flAngleLimit");
}
void GCFeJiggleBone::SetAngleLimit(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flAngleLimit", false, value);
}
float GCFeJiggleBone::GetMinYaw() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flMinYaw");
}
void GCFeJiggleBone::SetMinYaw(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flMinYaw", false, value);
}
float GCFeJiggleBone::GetMaxYaw() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flMaxYaw");
}
void GCFeJiggleBone::SetMaxYaw(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flMaxYaw", false, value);
}
float GCFeJiggleBone::GetYawFriction() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flYawFriction");
}
void GCFeJiggleBone::SetYawFriction(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flYawFriction", false, value);
}
float GCFeJiggleBone::GetYawBounce() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flYawBounce");
}
void GCFeJiggleBone::SetYawBounce(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flYawBounce", false, value);
}
float GCFeJiggleBone::GetMinPitch() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flMinPitch");
}
void GCFeJiggleBone::SetMinPitch(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flMinPitch", false, value);
}
float GCFeJiggleBone::GetMaxPitch() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flMaxPitch");
}
void GCFeJiggleBone::SetMaxPitch(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flMaxPitch", false, value);
}
float GCFeJiggleBone::GetPitchFriction() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flPitchFriction");
}
void GCFeJiggleBone::SetPitchFriction(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flPitchFriction", false, value);
}
float GCFeJiggleBone::GetPitchBounce() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flPitchBounce");
}
void GCFeJiggleBone::SetPitchBounce(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flPitchBounce", false, value);
}
float GCFeJiggleBone::GetBaseMass() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseMass");
}
void GCFeJiggleBone::SetBaseMass(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseMass", false, value);
}
float GCFeJiggleBone::GetBaseStiffness() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseStiffness");
}
void GCFeJiggleBone::SetBaseStiffness(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseStiffness", false, value);
}
float GCFeJiggleBone::GetBaseDamping() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseDamping");
}
void GCFeJiggleBone::SetBaseDamping(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseDamping", false, value);
}
float GCFeJiggleBone::GetBaseMinLeft() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseMinLeft");
}
void GCFeJiggleBone::SetBaseMinLeft(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseMinLeft", false, value);
}
float GCFeJiggleBone::GetBaseMaxLeft() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseMaxLeft");
}
void GCFeJiggleBone::SetBaseMaxLeft(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseMaxLeft", false, value);
}
float GCFeJiggleBone::GetBaseLeftFriction() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseLeftFriction");
}
void GCFeJiggleBone::SetBaseLeftFriction(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseLeftFriction", false, value);
}
float GCFeJiggleBone::GetBaseMinUp() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseMinUp");
}
void GCFeJiggleBone::SetBaseMinUp(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseMinUp", false, value);
}
float GCFeJiggleBone::GetBaseMaxUp() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseMaxUp");
}
void GCFeJiggleBone::SetBaseMaxUp(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseMaxUp", false, value);
}
float GCFeJiggleBone::GetBaseUpFriction() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseUpFriction");
}
void GCFeJiggleBone::SetBaseUpFriction(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseUpFriction", false, value);
}
float GCFeJiggleBone::GetBaseMinForward() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseMinForward");
}
void GCFeJiggleBone::SetBaseMinForward(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseMinForward", false, value);
}
float GCFeJiggleBone::GetBaseMaxForward() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseMaxForward");
}
void GCFeJiggleBone::SetBaseMaxForward(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseMaxForward", false, value);
}
float GCFeJiggleBone::GetBaseForwardFriction() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flBaseForwardFriction");
}
void GCFeJiggleBone::SetBaseForwardFriction(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flBaseForwardFriction", false, value);
}
float GCFeJiggleBone::GetRadius0() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flRadius0");
}
void GCFeJiggleBone::SetRadius0(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flRadius0", false, value);
}
float GCFeJiggleBone::GetRadius1() const {
    return GetSchemaValue<float>(m_ptr, "CFeJiggleBone", "m_flRadius1");
}
void GCFeJiggleBone::SetRadius1(float value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_flRadius1", false, value);
}
Vector GCFeJiggleBone::GetPoint0() const {
    return GetSchemaValue<Vector>(m_ptr, "CFeJiggleBone", "m_vPoint0");
}
void GCFeJiggleBone::SetPoint0(Vector value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_vPoint0", false, value);
}
Vector GCFeJiggleBone::GetPoint1() const {
    return GetSchemaValue<Vector>(m_ptr, "CFeJiggleBone", "m_vPoint1");
}
void GCFeJiggleBone::SetPoint1(Vector value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_vPoint1", false, value);
}
uint16_t GCFeJiggleBone::GetCollisionMask() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CFeJiggleBone", "m_nCollisionMask");
}
void GCFeJiggleBone::SetCollisionMask(uint16_t value) {
    SetSchemaValue(m_ptr, "CFeJiggleBone", "m_nCollisionMask", false, value);
}
std::string GCFeJiggleBone::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFeJiggleBone::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCFeJiggleBone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFeJiggleBone>("CFeJiggleBone")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Flags", &GCFeJiggleBone::GetFlags, &GCFeJiggleBone::SetFlags)
        .addProperty("Length", &GCFeJiggleBone::GetLength, &GCFeJiggleBone::SetLength)
        .addProperty("TipMass", &GCFeJiggleBone::GetTipMass, &GCFeJiggleBone::SetTipMass)
        .addProperty("YawStiffness", &GCFeJiggleBone::GetYawStiffness, &GCFeJiggleBone::SetYawStiffness)
        .addProperty("YawDamping", &GCFeJiggleBone::GetYawDamping, &GCFeJiggleBone::SetYawDamping)
        .addProperty("PitchStiffness", &GCFeJiggleBone::GetPitchStiffness, &GCFeJiggleBone::SetPitchStiffness)
        .addProperty("PitchDamping", &GCFeJiggleBone::GetPitchDamping, &GCFeJiggleBone::SetPitchDamping)
        .addProperty("AlongStiffness", &GCFeJiggleBone::GetAlongStiffness, &GCFeJiggleBone::SetAlongStiffness)
        .addProperty("AlongDamping", &GCFeJiggleBone::GetAlongDamping, &GCFeJiggleBone::SetAlongDamping)
        .addProperty("AngleLimit", &GCFeJiggleBone::GetAngleLimit, &GCFeJiggleBone::SetAngleLimit)
        .addProperty("MinYaw", &GCFeJiggleBone::GetMinYaw, &GCFeJiggleBone::SetMinYaw)
        .addProperty("MaxYaw", &GCFeJiggleBone::GetMaxYaw, &GCFeJiggleBone::SetMaxYaw)
        .addProperty("YawFriction", &GCFeJiggleBone::GetYawFriction, &GCFeJiggleBone::SetYawFriction)
        .addProperty("YawBounce", &GCFeJiggleBone::GetYawBounce, &GCFeJiggleBone::SetYawBounce)
        .addProperty("MinPitch", &GCFeJiggleBone::GetMinPitch, &GCFeJiggleBone::SetMinPitch)
        .addProperty("MaxPitch", &GCFeJiggleBone::GetMaxPitch, &GCFeJiggleBone::SetMaxPitch)
        .addProperty("PitchFriction", &GCFeJiggleBone::GetPitchFriction, &GCFeJiggleBone::SetPitchFriction)
        .addProperty("PitchBounce", &GCFeJiggleBone::GetPitchBounce, &GCFeJiggleBone::SetPitchBounce)
        .addProperty("BaseMass", &GCFeJiggleBone::GetBaseMass, &GCFeJiggleBone::SetBaseMass)
        .addProperty("BaseStiffness", &GCFeJiggleBone::GetBaseStiffness, &GCFeJiggleBone::SetBaseStiffness)
        .addProperty("BaseDamping", &GCFeJiggleBone::GetBaseDamping, &GCFeJiggleBone::SetBaseDamping)
        .addProperty("BaseMinLeft", &GCFeJiggleBone::GetBaseMinLeft, &GCFeJiggleBone::SetBaseMinLeft)
        .addProperty("BaseMaxLeft", &GCFeJiggleBone::GetBaseMaxLeft, &GCFeJiggleBone::SetBaseMaxLeft)
        .addProperty("BaseLeftFriction", &GCFeJiggleBone::GetBaseLeftFriction, &GCFeJiggleBone::SetBaseLeftFriction)
        .addProperty("BaseMinUp", &GCFeJiggleBone::GetBaseMinUp, &GCFeJiggleBone::SetBaseMinUp)
        .addProperty("BaseMaxUp", &GCFeJiggleBone::GetBaseMaxUp, &GCFeJiggleBone::SetBaseMaxUp)
        .addProperty("BaseUpFriction", &GCFeJiggleBone::GetBaseUpFriction, &GCFeJiggleBone::SetBaseUpFriction)
        .addProperty("BaseMinForward", &GCFeJiggleBone::GetBaseMinForward, &GCFeJiggleBone::SetBaseMinForward)
        .addProperty("BaseMaxForward", &GCFeJiggleBone::GetBaseMaxForward, &GCFeJiggleBone::SetBaseMaxForward)
        .addProperty("BaseForwardFriction", &GCFeJiggleBone::GetBaseForwardFriction, &GCFeJiggleBone::SetBaseForwardFriction)
        .addProperty("Radius0", &GCFeJiggleBone::GetRadius0, &GCFeJiggleBone::SetRadius0)
        .addProperty("Radius1", &GCFeJiggleBone::GetRadius1, &GCFeJiggleBone::SetRadius1)
        .addProperty("Point0", &GCFeJiggleBone::GetPoint0, &GCFeJiggleBone::SetPoint0)
        .addProperty("Point1", &GCFeJiggleBone::GetPoint1, &GCFeJiggleBone::SetPoint1)
        .addProperty("CollisionMask", &GCFeJiggleBone::GetCollisionMask, &GCFeJiggleBone::SetCollisionMask)
        .addFunction("ToPtr", &GCFeJiggleBone::ToPtr)
        .addFunction("IsValid", &GCFeJiggleBone::IsValid)
        .endClass();
}