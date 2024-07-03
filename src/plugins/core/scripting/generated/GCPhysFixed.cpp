#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysFixed::GCPhysFixed(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysFixed::GCPhysFixed(void *ptr) {
    m_ptr = ptr;
}
float GCPhysFixed::GetLinearFrequency() const {
    return GetSchemaValue<float>(m_ptr, "CPhysFixed", "m_flLinearFrequency");
}
void GCPhysFixed::SetLinearFrequency(float value) {
    SetSchemaValue(m_ptr, "CPhysFixed", "m_flLinearFrequency", false, value);
}
float GCPhysFixed::GetLinearDampingRatio() const {
    return GetSchemaValue<float>(m_ptr, "CPhysFixed", "m_flLinearDampingRatio");
}
void GCPhysFixed::SetLinearDampingRatio(float value) {
    SetSchemaValue(m_ptr, "CPhysFixed", "m_flLinearDampingRatio", false, value);
}
float GCPhysFixed::GetAngularFrequency() const {
    return GetSchemaValue<float>(m_ptr, "CPhysFixed", "m_flAngularFrequency");
}
void GCPhysFixed::SetAngularFrequency(float value) {
    SetSchemaValue(m_ptr, "CPhysFixed", "m_flAngularFrequency", false, value);
}
float GCPhysFixed::GetAngularDampingRatio() const {
    return GetSchemaValue<float>(m_ptr, "CPhysFixed", "m_flAngularDampingRatio");
}
void GCPhysFixed::SetAngularDampingRatio(float value) {
    SetSchemaValue(m_ptr, "CPhysFixed", "m_flAngularDampingRatio", false, value);
}
bool GCPhysFixed::GetEnableLinearConstraint() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysFixed", "m_bEnableLinearConstraint");
}
void GCPhysFixed::SetEnableLinearConstraint(bool value) {
    SetSchemaValue(m_ptr, "CPhysFixed", "m_bEnableLinearConstraint", false, value);
}
bool GCPhysFixed::GetEnableAngularConstraint() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysFixed", "m_bEnableAngularConstraint");
}
void GCPhysFixed::SetEnableAngularConstraint(bool value) {
    SetSchemaValue(m_ptr, "CPhysFixed", "m_bEnableAngularConstraint", false, value);
}
std::string GCPhysFixed::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysFixed::IsValid() {
    return (m_ptr != nullptr);
}
GCPhysConstraint GCPhysFixed::GetParent() const {
    GCPhysConstraint value(m_ptr);
    return value;
}
void GCPhysFixed::SetParent(GCPhysConstraint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysFixed(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysFixed>("CPhysFixed")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LinearFrequency", &GCPhysFixed::GetLinearFrequency, &GCPhysFixed::SetLinearFrequency)
        .addProperty("LinearDampingRatio", &GCPhysFixed::GetLinearDampingRatio, &GCPhysFixed::SetLinearDampingRatio)
        .addProperty("AngularFrequency", &GCPhysFixed::GetAngularFrequency, &GCPhysFixed::SetAngularFrequency)
        .addProperty("AngularDampingRatio", &GCPhysFixed::GetAngularDampingRatio, &GCPhysFixed::SetAngularDampingRatio)
        .addProperty("EnableLinearConstraint", &GCPhysFixed::GetEnableLinearConstraint, &GCPhysFixed::SetEnableLinearConstraint)
        .addProperty("EnableAngularConstraint", &GCPhysFixed::GetEnableAngularConstraint, &GCPhysFixed::SetEnableAngularConstraint)
        .addProperty("Parent", &GCPhysFixed::GetParent, &GCPhysFixed::SetParent)
        .addFunction("ToPtr", &GCPhysFixed::ToPtr)
        .addFunction("IsValid", &GCPhysFixed::IsValid)
        .endClass();
}