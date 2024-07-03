#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysBallSocket::GCPhysBallSocket(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysBallSocket::GCPhysBallSocket(void *ptr) {
    m_ptr = ptr;
}
float GCPhysBallSocket::GetJointFriction() const {
    return GetSchemaValue<float>(m_ptr, "CPhysBallSocket", "m_flJointFriction");
}
void GCPhysBallSocket::SetJointFriction(float value) {
    SetSchemaValue(m_ptr, "CPhysBallSocket", "m_flJointFriction", false, value);
}
bool GCPhysBallSocket::GetEnableSwingLimit() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysBallSocket", "m_bEnableSwingLimit");
}
void GCPhysBallSocket::SetEnableSwingLimit(bool value) {
    SetSchemaValue(m_ptr, "CPhysBallSocket", "m_bEnableSwingLimit", false, value);
}
float GCPhysBallSocket::GetSwingLimit() const {
    return GetSchemaValue<float>(m_ptr, "CPhysBallSocket", "m_flSwingLimit");
}
void GCPhysBallSocket::SetSwingLimit(float value) {
    SetSchemaValue(m_ptr, "CPhysBallSocket", "m_flSwingLimit", false, value);
}
bool GCPhysBallSocket::GetEnableTwistLimit() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysBallSocket", "m_bEnableTwistLimit");
}
void GCPhysBallSocket::SetEnableTwistLimit(bool value) {
    SetSchemaValue(m_ptr, "CPhysBallSocket", "m_bEnableTwistLimit", false, value);
}
float GCPhysBallSocket::GetMinTwistAngle() const {
    return GetSchemaValue<float>(m_ptr, "CPhysBallSocket", "m_flMinTwistAngle");
}
void GCPhysBallSocket::SetMinTwistAngle(float value) {
    SetSchemaValue(m_ptr, "CPhysBallSocket", "m_flMinTwistAngle", false, value);
}
float GCPhysBallSocket::GetMaxTwistAngle() const {
    return GetSchemaValue<float>(m_ptr, "CPhysBallSocket", "m_flMaxTwistAngle");
}
void GCPhysBallSocket::SetMaxTwistAngle(float value) {
    SetSchemaValue(m_ptr, "CPhysBallSocket", "m_flMaxTwistAngle", false, value);
}
std::string GCPhysBallSocket::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysBallSocket::IsValid() {
    return (m_ptr != nullptr);
}
GCPhysConstraint GCPhysBallSocket::GetParent() const {
    GCPhysConstraint value(m_ptr);
    return value;
}
void GCPhysBallSocket::SetParent(GCPhysConstraint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysBallSocket(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysBallSocket>("CPhysBallSocket")
        .addConstructor<void (*)(std::string)>()
        .addProperty("JointFriction", &GCPhysBallSocket::GetJointFriction, &GCPhysBallSocket::SetJointFriction)
        .addProperty("EnableSwingLimit", &GCPhysBallSocket::GetEnableSwingLimit, &GCPhysBallSocket::SetEnableSwingLimit)
        .addProperty("SwingLimit", &GCPhysBallSocket::GetSwingLimit, &GCPhysBallSocket::SetSwingLimit)
        .addProperty("EnableTwistLimit", &GCPhysBallSocket::GetEnableTwistLimit, &GCPhysBallSocket::SetEnableTwistLimit)
        .addProperty("MinTwistAngle", &GCPhysBallSocket::GetMinTwistAngle, &GCPhysBallSocket::SetMinTwistAngle)
        .addProperty("MaxTwistAngle", &GCPhysBallSocket::GetMaxTwistAngle, &GCPhysBallSocket::SetMaxTwistAngle)
        .addProperty("Parent", &GCPhysBallSocket::GetParent, &GCPhysBallSocket::SetParent)
        .addFunction("ToPtr", &GCPhysBallSocket::ToPtr)
        .addFunction("IsValid", &GCPhysBallSocket::IsValid)
        .endClass();
}