#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSingleplayRules::GCSingleplayRules(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSingleplayRules::GCSingleplayRules(void *ptr) {
    m_ptr = ptr;
}
bool GCSingleplayRules::GetSinglePlayerGameEnding() const {
    return GetSchemaValue<bool>(m_ptr, "CSingleplayRules", "m_bSinglePlayerGameEnding");
}
void GCSingleplayRules::SetSinglePlayerGameEnding(bool value) {
    SetSchemaValue(m_ptr, "CSingleplayRules", "m_bSinglePlayerGameEnding", false, value);
}
std::string GCSingleplayRules::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSingleplayRules::IsValid() {
    return (m_ptr != nullptr);
}
GCGameRules GCSingleplayRules::GetParent() const {
    GCGameRules value(m_ptr);
    return value;
}
void GCSingleplayRules::SetParent(GCGameRules value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSingleplayRules(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSingleplayRules>("CSingleplayRules")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SinglePlayerGameEnding", &GCSingleplayRules::GetSinglePlayerGameEnding, &GCSingleplayRules::SetSinglePlayerGameEnding)
        .addProperty("Parent", &GCSingleplayRules::GetParent, &GCSingleplayRules::SetParent)
        .addFunction("ToPtr", &GCSingleplayRules::ToPtr)
        .addFunction("IsValid", &GCSingleplayRules::IsValid)
        .endClass();
}