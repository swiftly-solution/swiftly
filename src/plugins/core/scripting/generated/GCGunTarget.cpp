#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCGunTarget::GCGunTarget(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCGunTarget::GCGunTarget(void *ptr) {
    m_ptr = ptr;
}
bool GCGunTarget::GetOn() const {
    return GetSchemaValue<bool>(m_ptr, "CGunTarget", "m_on");
}
void GCGunTarget::SetOn(bool value) {
    SetSchemaValue(m_ptr, "CGunTarget", "m_on", false, value);
}
GCBaseEntity GCGunTarget::GetTargetEnt() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CGunTarget", "m_hTargetEnt"));
    return value;
}
void GCGunTarget::SetTargetEnt(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetEnt' is not possible.\n");
}
GCEntityIOOutput GCGunTarget::GetOnDeath() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CGunTarget", "m_OnDeath"));
    return value;
}
void GCGunTarget::SetOnDeath(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CGunTarget", "m_OnDeath", false, value);
}
std::string GCGunTarget::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCGunTarget::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseToggle GCGunTarget::GetParent() const {
    GCBaseToggle value(m_ptr);
    return value;
}
void GCGunTarget::SetParent(GCBaseToggle value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCGunTarget(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGunTarget>("CGunTarget")
        .addConstructor<void (*)(std::string)>()
        .addProperty("On", &GCGunTarget::GetOn, &GCGunTarget::SetOn)
        .addProperty("TargetEnt", &GCGunTarget::GetTargetEnt, &GCGunTarget::SetTargetEnt)
        .addProperty("OnDeath", &GCGunTarget::GetOnDeath, &GCGunTarget::SetOnDeath)
        .addProperty("Parent", &GCGunTarget::GetParent, &GCGunTarget::SetParent)
        .addFunction("ToPtr", &GCGunTarget::ToPtr)
        .addFunction("IsValid", &GCGunTarget::IsValid)
        .endClass();
}