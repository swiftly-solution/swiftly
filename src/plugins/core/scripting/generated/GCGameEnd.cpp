#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCGameEnd::GCGameEnd(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCGameEnd::GCGameEnd(void *ptr) {
    m_ptr = ptr;
}
std::string GCGameEnd::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCGameEnd::IsValid() {
    return (m_ptr != nullptr);
}
GCRulePointEntity GCGameEnd::GetParent() const {
    GCRulePointEntity value(m_ptr);
    return value;
}
void GCGameEnd::SetParent(GCRulePointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCGameEnd(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGameEnd>("CGameEnd")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCGameEnd::GetParent, &GCGameEnd::SetParent)
        .addFunction("ToPtr", &GCGameEnd::ToPtr)
        .addFunction("IsValid", &GCGameEnd::IsValid)
        .endClass();
}