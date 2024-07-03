#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoPlayerStart::GCInfoPlayerStart(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoPlayerStart::GCInfoPlayerStart(void *ptr) {
    m_ptr = ptr;
}
bool GCInfoPlayerStart::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CInfoPlayerStart", "m_bDisabled");
}
void GCInfoPlayerStart::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CInfoPlayerStart", "m_bDisabled", false, value);
}
std::string GCInfoPlayerStart::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoPlayerStart::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCInfoPlayerStart::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCInfoPlayerStart::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoPlayerStart(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoPlayerStart>("CInfoPlayerStart")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Disabled", &GCInfoPlayerStart::GetDisabled, &GCInfoPlayerStart::SetDisabled)
        .addProperty("Parent", &GCInfoPlayerStart::GetParent, &GCInfoPlayerStart::SetParent)
        .addFunction("ToPtr", &GCInfoPlayerStart::ToPtr)
        .addFunction("IsValid", &GCInfoPlayerStart::IsValid)
        .endClass();
}