#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTeamplayRules::GCTeamplayRules(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTeamplayRules::GCTeamplayRules(void *ptr) {
    m_ptr = ptr;
}
std::string GCTeamplayRules::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTeamplayRules::IsValid() {
    return (m_ptr != nullptr);
}
GCMultiplayRules GCTeamplayRules::GetParent() const {
    GCMultiplayRules value(m_ptr);
    return value;
}
void GCTeamplayRules::SetParent(GCMultiplayRules value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTeamplayRules(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTeamplayRules>("CTeamplayRules")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCTeamplayRules::GetParent, &GCTeamplayRules::SetParent)
        .addFunction("ToPtr", &GCTeamplayRules::ToPtr)
        .addFunction("IsValid", &GCTeamplayRules::IsValid)
        .endClass();
}