#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVPhysXJoint_t::GVPhysXJoint_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVPhysXJoint_t::GVPhysXJoint_t(void *ptr) {
    m_ptr = ptr;
}
uint16_t GVPhysXJoint_t::GetType() const {
    return GetSchemaValue<uint16_t>(m_ptr, "VPhysXJoint_t", "m_nType");
}
void GVPhysXJoint_t::SetType(uint16_t value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_nType", true, value);
}
uint16_t GVPhysXJoint_t::GetBody1() const {
    return GetSchemaValue<uint16_t>(m_ptr, "VPhysXJoint_t", "m_nBody1");
}
void GVPhysXJoint_t::SetBody1(uint16_t value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_nBody1", true, value);
}
uint16_t GVPhysXJoint_t::GetBody2() const {
    return GetSchemaValue<uint16_t>(m_ptr, "VPhysXJoint_t", "m_nBody2");
}
void GVPhysXJoint_t::SetBody2(uint16_t value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_nBody2", true, value);
}
uint16_t GVPhysXJoint_t::GetFlags() const {
    return GetSchemaValue<uint16_t>(m_ptr, "VPhysXJoint_t", "m_nFlags");
}
void GVPhysXJoint_t::SetFlags(uint16_t value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_nFlags", true, value);
}
bool GVPhysXJoint_t::GetEnableCollision() const {
    return GetSchemaValue<bool>(m_ptr, "VPhysXJoint_t", "m_bEnableCollision");
}
void GVPhysXJoint_t::SetEnableCollision(bool value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_bEnableCollision", true, value);
}
bool GVPhysXJoint_t::GetEnableLinearLimit() const {
    return GetSchemaValue<bool>(m_ptr, "VPhysXJoint_t", "m_bEnableLinearLimit");
}
void GVPhysXJoint_t::SetEnableLinearLimit(bool value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_bEnableLinearLimit", true, value);
}
GVPhysXRange_t GVPhysXJoint_t::GetLinearLimit() const {
    GVPhysXRange_t value(GetSchemaPtr(m_ptr, "VPhysXJoint_t", "m_LinearLimit"));
    return value;
}
void GVPhysXJoint_t::SetLinearLimit(GVPhysXRange_t value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_LinearLimit", true, value);
}
bool GVPhysXJoint_t::GetEnableLinearMotor() const {
    return GetSchemaValue<bool>(m_ptr, "VPhysXJoint_t", "m_bEnableLinearMotor");
}
void GVPhysXJoint_t::SetEnableLinearMotor(bool value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_bEnableLinearMotor", true, value);
}
Vector GVPhysXJoint_t::GetLinearTargetVelocity() const {
    return GetSchemaValue<Vector>(m_ptr, "VPhysXJoint_t", "m_vLinearTargetVelocity");
}
void GVPhysXJoint_t::SetLinearTargetVelocity(Vector value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_vLinearTargetVelocity", true, value);
}
float GVPhysXJoint_t::GetMaxForce() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXJoint_t", "m_flMaxForce");
}
void GVPhysXJoint_t::SetMaxForce(float value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_flMaxForce", true, value);
}
bool GVPhysXJoint_t::GetEnableSwingLimit() const {
    return GetSchemaValue<bool>(m_ptr, "VPhysXJoint_t", "m_bEnableSwingLimit");
}
void GVPhysXJoint_t::SetEnableSwingLimit(bool value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_bEnableSwingLimit", true, value);
}
GVPhysXRange_t GVPhysXJoint_t::GetSwingLimit() const {
    GVPhysXRange_t value(GetSchemaPtr(m_ptr, "VPhysXJoint_t", "m_SwingLimit"));
    return value;
}
void GVPhysXJoint_t::SetSwingLimit(GVPhysXRange_t value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_SwingLimit", true, value);
}
bool GVPhysXJoint_t::GetEnableTwistLimit() const {
    return GetSchemaValue<bool>(m_ptr, "VPhysXJoint_t", "m_bEnableTwistLimit");
}
void GVPhysXJoint_t::SetEnableTwistLimit(bool value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_bEnableTwistLimit", true, value);
}
GVPhysXRange_t GVPhysXJoint_t::GetTwistLimit() const {
    GVPhysXRange_t value(GetSchemaPtr(m_ptr, "VPhysXJoint_t", "m_TwistLimit"));
    return value;
}
void GVPhysXJoint_t::SetTwistLimit(GVPhysXRange_t value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_TwistLimit", true, value);
}
bool GVPhysXJoint_t::GetEnableAngularMotor() const {
    return GetSchemaValue<bool>(m_ptr, "VPhysXJoint_t", "m_bEnableAngularMotor");
}
void GVPhysXJoint_t::SetEnableAngularMotor(bool value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_bEnableAngularMotor", true, value);
}
Vector GVPhysXJoint_t::GetAngularTargetVelocity() const {
    return GetSchemaValue<Vector>(m_ptr, "VPhysXJoint_t", "m_vAngularTargetVelocity");
}
void GVPhysXJoint_t::SetAngularTargetVelocity(Vector value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_vAngularTargetVelocity", true, value);
}
float GVPhysXJoint_t::GetMaxTorque() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXJoint_t", "m_flMaxTorque");
}
void GVPhysXJoint_t::SetMaxTorque(float value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_flMaxTorque", true, value);
}
float GVPhysXJoint_t::GetLinearFrequency() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXJoint_t", "m_flLinearFrequency");
}
void GVPhysXJoint_t::SetLinearFrequency(float value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_flLinearFrequency", true, value);
}
float GVPhysXJoint_t::GetLinearDampingRatio() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXJoint_t", "m_flLinearDampingRatio");
}
void GVPhysXJoint_t::SetLinearDampingRatio(float value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_flLinearDampingRatio", true, value);
}
float GVPhysXJoint_t::GetAngularFrequency() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXJoint_t", "m_flAngularFrequency");
}
void GVPhysXJoint_t::SetAngularFrequency(float value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_flAngularFrequency", true, value);
}
float GVPhysXJoint_t::GetAngularDampingRatio() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXJoint_t", "m_flAngularDampingRatio");
}
void GVPhysXJoint_t::SetAngularDampingRatio(float value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_flAngularDampingRatio", true, value);
}
float GVPhysXJoint_t::GetFriction() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXJoint_t", "m_flFriction");
}
void GVPhysXJoint_t::SetFriction(float value) {
    SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_flFriction", true, value);
}
std::string GVPhysXJoint_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVPhysXJoint_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVPhysXJoint_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVPhysXJoint_t>("VPhysXJoint_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Type", &GVPhysXJoint_t::GetType, &GVPhysXJoint_t::SetType)
        .addProperty("Body1", &GVPhysXJoint_t::GetBody1, &GVPhysXJoint_t::SetBody1)
        .addProperty("Body2", &GVPhysXJoint_t::GetBody2, &GVPhysXJoint_t::SetBody2)
        .addProperty("Flags", &GVPhysXJoint_t::GetFlags, &GVPhysXJoint_t::SetFlags)
        .addProperty("EnableCollision", &GVPhysXJoint_t::GetEnableCollision, &GVPhysXJoint_t::SetEnableCollision)
        .addProperty("EnableLinearLimit", &GVPhysXJoint_t::GetEnableLinearLimit, &GVPhysXJoint_t::SetEnableLinearLimit)
        .addProperty("LinearLimit", &GVPhysXJoint_t::GetLinearLimit, &GVPhysXJoint_t::SetLinearLimit)
        .addProperty("EnableLinearMotor", &GVPhysXJoint_t::GetEnableLinearMotor, &GVPhysXJoint_t::SetEnableLinearMotor)
        .addProperty("LinearTargetVelocity", &GVPhysXJoint_t::GetLinearTargetVelocity, &GVPhysXJoint_t::SetLinearTargetVelocity)
        .addProperty("MaxForce", &GVPhysXJoint_t::GetMaxForce, &GVPhysXJoint_t::SetMaxForce)
        .addProperty("EnableSwingLimit", &GVPhysXJoint_t::GetEnableSwingLimit, &GVPhysXJoint_t::SetEnableSwingLimit)
        .addProperty("SwingLimit", &GVPhysXJoint_t::GetSwingLimit, &GVPhysXJoint_t::SetSwingLimit)
        .addProperty("EnableTwistLimit", &GVPhysXJoint_t::GetEnableTwistLimit, &GVPhysXJoint_t::SetEnableTwistLimit)
        .addProperty("TwistLimit", &GVPhysXJoint_t::GetTwistLimit, &GVPhysXJoint_t::SetTwistLimit)
        .addProperty("EnableAngularMotor", &GVPhysXJoint_t::GetEnableAngularMotor, &GVPhysXJoint_t::SetEnableAngularMotor)
        .addProperty("AngularTargetVelocity", &GVPhysXJoint_t::GetAngularTargetVelocity, &GVPhysXJoint_t::SetAngularTargetVelocity)
        .addProperty("MaxTorque", &GVPhysXJoint_t::GetMaxTorque, &GVPhysXJoint_t::SetMaxTorque)
        .addProperty("LinearFrequency", &GVPhysXJoint_t::GetLinearFrequency, &GVPhysXJoint_t::SetLinearFrequency)
        .addProperty("LinearDampingRatio", &GVPhysXJoint_t::GetLinearDampingRatio, &GVPhysXJoint_t::SetLinearDampingRatio)
        .addProperty("AngularFrequency", &GVPhysXJoint_t::GetAngularFrequency, &GVPhysXJoint_t::SetAngularFrequency)
        .addProperty("AngularDampingRatio", &GVPhysXJoint_t::GetAngularDampingRatio, &GVPhysXJoint_t::SetAngularDampingRatio)
        .addProperty("Friction", &GVPhysXJoint_t::GetFriction, &GVPhysXJoint_t::SetFriction)
        .addFunction("ToPtr", &GVPhysXJoint_t::ToPtr)
        .addFunction("IsValid", &GVPhysXJoint_t::IsValid)
        .endClass();
}