#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMultiplayer_Expresser::GCMultiplayer_Expresser(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMultiplayer_Expresser::GCMultiplayer_Expresser(void *ptr) {
    m_ptr = ptr;
}
bool GCMultiplayer_Expresser::GetAllowMultipleScenes() const {
    return GetSchemaValue<bool>(m_ptr, "CMultiplayer_Expresser", "m_bAllowMultipleScenes");
}
void GCMultiplayer_Expresser::SetAllowMultipleScenes(bool value) {
    SetSchemaValue(m_ptr, "CMultiplayer_Expresser", "m_bAllowMultipleScenes", false, value);
}
std::string GCMultiplayer_Expresser::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMultiplayer_Expresser::IsValid() {
    return (m_ptr != nullptr);
}
GCAI_ExpresserWithFollowup GCMultiplayer_Expresser::GetParent() const {
    GCAI_ExpresserWithFollowup value(m_ptr);
    return value;
}
void GCMultiplayer_Expresser::SetParent(GCAI_ExpresserWithFollowup value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMultiplayer_Expresser(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMultiplayer_Expresser>("CMultiplayer_Expresser")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AllowMultipleScenes", &GCMultiplayer_Expresser::GetAllowMultipleScenes, &GCMultiplayer_Expresser::SetAllowMultipleScenes)
        .addProperty("Parent", &GCMultiplayer_Expresser::GetParent, &GCMultiplayer_Expresser::SetParent)
        .addFunction("ToPtr", &GCMultiplayer_Expresser::ToPtr)
        .addFunction("IsValid", &GCMultiplayer_Expresser::IsValid)
        .endClass();
}