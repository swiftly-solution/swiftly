#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvSoundscapeProxy::GCEnvSoundscapeProxy(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvSoundscapeProxy::GCEnvSoundscapeProxy(void *ptr) {
    m_ptr = ptr;
}
std::string GCEnvSoundscapeProxy::GetMainSoundscapeName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvSoundscapeProxy", "m_MainSoundscapeName").String();
}
void GCEnvSoundscapeProxy::SetMainSoundscapeName(std::string value) {
    SetSchemaValue(m_ptr, "CEnvSoundscapeProxy", "m_MainSoundscapeName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCEnvSoundscapeProxy::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvSoundscapeProxy::IsValid() {
    return (m_ptr != nullptr);
}
GCEnvSoundscape GCEnvSoundscapeProxy::GetParent() const {
    GCEnvSoundscape value(m_ptr);
    return value;
}
void GCEnvSoundscapeProxy::SetParent(GCEnvSoundscape value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvSoundscapeProxy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvSoundscapeProxy>("CEnvSoundscapeProxy")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MainSoundscapeName", &GCEnvSoundscapeProxy::GetMainSoundscapeName, &GCEnvSoundscapeProxy::SetMainSoundscapeName)
        .addProperty("Parent", &GCEnvSoundscapeProxy::GetParent, &GCEnvSoundscapeProxy::SetParent)
        .addFunction("ToPtr", &GCEnvSoundscapeProxy::ToPtr)
        .addFunction("IsValid", &GCEnvSoundscapeProxy::IsValid)
        .endClass();
}