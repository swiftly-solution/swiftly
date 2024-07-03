#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMultiplayRules::GCMultiplayRules(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMultiplayRules::GCMultiplayRules(void *ptr) {
    m_ptr = ptr;
}
std::string GCMultiplayRules::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMultiplayRules::IsValid() {
    return (m_ptr != nullptr);
}
GCGameRules GCMultiplayRules::GetParent() const {
    GCGameRules value(m_ptr);
    return value;
}
void GCMultiplayRules::SetParent(GCGameRules value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMultiplayRules(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMultiplayRules>("CMultiplayRules")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCMultiplayRules::GetParent, &GCMultiplayRules::SetParent)
        .addFunction("ToPtr", &GCMultiplayRules::ToPtr)
        .addFunction("IsValid", &GCMultiplayRules::IsValid)
        .endClass();
}