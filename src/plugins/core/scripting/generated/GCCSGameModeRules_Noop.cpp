#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSGameModeRules_Noop::GCCSGameModeRules_Noop(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSGameModeRules_Noop::GCCSGameModeRules_Noop(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSGameModeRules_Noop::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSGameModeRules_Noop::IsValid() {
    return (m_ptr != nullptr);
}
GCCSGameModeRules GCCSGameModeRules_Noop::GetParent() const {
    GCCSGameModeRules value(m_ptr);
    return value;
}
void GCCSGameModeRules_Noop::SetParent(GCCSGameModeRules value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSGameModeRules_Noop(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGameModeRules_Noop>("CCSGameModeRules_Noop")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSGameModeRules_Noop::GetParent, &GCCSGameModeRules_Noop::SetParent)
        .addFunction("ToPtr", &GCCSGameModeRules_Noop::ToPtr)
        .addFunction("IsValid", &GCCSGameModeRules_Noop::IsValid)
        .endClass();
}