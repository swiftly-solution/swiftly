#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCGameRulesProxy::GCGameRulesProxy(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCGameRulesProxy::GCGameRulesProxy(void *ptr) {
    m_ptr = ptr;
}
std::string GCGameRulesProxy::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCGameRulesProxy::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCGameRulesProxy::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCGameRulesProxy::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCGameRulesProxy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGameRulesProxy>("CGameRulesProxy")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCGameRulesProxy::GetParent, &GCGameRulesProxy::SetParent)
        .addFunction("ToPtr", &GCGameRulesProxy::ToPtr)
        .addFunction("IsValid", &GCGameRulesProxy::IsValid)
        .endClass();
}