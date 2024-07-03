#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSGameRulesProxy::GCCSGameRulesProxy(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSGameRulesProxy::GCCSGameRulesProxy(void *ptr) {
    m_ptr = ptr;
}
GCCSGameRules GCCSGameRulesProxy::GetGameRules() const {
    GCCSGameRules value(*GetSchemaValuePtr<void*>(m_ptr, "CCSGameRulesProxy", "m_pGameRules"));
    return value;
}
void GCCSGameRulesProxy::SetGameRules(GCCSGameRules* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'GameRules' is not possible.\n");
}
std::string GCCSGameRulesProxy::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSGameRulesProxy::IsValid() {
    return (m_ptr != nullptr);
}
GCGameRulesProxy GCCSGameRulesProxy::GetParent() const {
    GCGameRulesProxy value(m_ptr);
    return value;
}
void GCCSGameRulesProxy::SetParent(GCGameRulesProxy value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSGameRulesProxy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGameRulesProxy>("CCSGameRulesProxy")
        .addConstructor<void (*)(std::string)>()
        .addProperty("GameRules", &GCCSGameRulesProxy::GetGameRules, &GCCSGameRulesProxy::SetGameRules)
        .addProperty("Parent", &GCCSGameRulesProxy::GetParent, &GCCSGameRulesProxy::SetParent)
        .addFunction("ToPtr", &GCCSGameRulesProxy::ToPtr)
        .addFunction("IsValid", &GCCSGameRulesProxy::IsValid)
        .endClass();
}