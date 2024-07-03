#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvHudHint::GCEnvHudHint(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvHudHint::GCEnvHudHint(void *ptr) {
    m_ptr = ptr;
}
std::string GCEnvHudHint::GetMessage() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvHudHint", "m_iszMessage").String();
}
void GCEnvHudHint::SetMessage(std::string value) {
    SetSchemaValue(m_ptr, "CEnvHudHint", "m_iszMessage", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCEnvHudHint::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvHudHint::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCEnvHudHint::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCEnvHudHint::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvHudHint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvHudHint>("CEnvHudHint")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Message", &GCEnvHudHint::GetMessage, &GCEnvHudHint::SetMessage)
        .addProperty("Parent", &GCEnvHudHint::GetParent, &GCEnvHudHint::SetParent)
        .addFunction("ToPtr", &GCEnvHudHint::ToPtr)
        .addFunction("IsValid", &GCEnvHudHint::IsValid)
        .endClass();
}