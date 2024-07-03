#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCHostageAlias_info_hostage_spawn::GCHostageAlias_info_hostage_spawn(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCHostageAlias_info_hostage_spawn::GCHostageAlias_info_hostage_spawn(void *ptr) {
    m_ptr = ptr;
}
std::string GCHostageAlias_info_hostage_spawn::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCHostageAlias_info_hostage_spawn::IsValid() {
    return (m_ptr != nullptr);
}
GCHostage GCHostageAlias_info_hostage_spawn::GetParent() const {
    GCHostage value(m_ptr);
    return value;
}
void GCHostageAlias_info_hostage_spawn::SetParent(GCHostage value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCHostageAlias_info_hostage_spawn(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHostageAlias_info_hostage_spawn>("CHostageAlias_info_hostage_spawn")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCHostageAlias_info_hostage_spawn::GetParent, &GCHostageAlias_info_hostage_spawn::SetParent)
        .addFunction("ToPtr", &GCHostageAlias_info_hostage_spawn::ToPtr)
        .addFunction("IsValid", &GCHostageAlias_info_hostage_spawn::IsValid)
        .endClass();
}