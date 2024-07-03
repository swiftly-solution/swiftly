#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncVPhysicsClip::GCFuncVPhysicsClip(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncVPhysicsClip::GCFuncVPhysicsClip(void *ptr) {
    m_ptr = ptr;
}
bool GCFuncVPhysicsClip::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncVPhysicsClip", "m_bDisabled");
}
void GCFuncVPhysicsClip::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CFuncVPhysicsClip", "m_bDisabled", false, value);
}
std::string GCFuncVPhysicsClip::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncVPhysicsClip::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCFuncVPhysicsClip::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCFuncVPhysicsClip::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncVPhysicsClip(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncVPhysicsClip>("CFuncVPhysicsClip")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Disabled", &GCFuncVPhysicsClip::GetDisabled, &GCFuncVPhysicsClip::SetDisabled)
        .addProperty("Parent", &GCFuncVPhysicsClip::GetParent, &GCFuncVPhysicsClip::SetParent)
        .addFunction("ToPtr", &GCFuncVPhysicsClip::ToPtr)
        .addFunction("IsValid", &GCFuncVPhysicsClip::IsValid)
        .endClass();
}