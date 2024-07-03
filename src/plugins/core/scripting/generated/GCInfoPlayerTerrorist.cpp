#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoPlayerTerrorist::GCInfoPlayerTerrorist(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoPlayerTerrorist::GCInfoPlayerTerrorist(void *ptr) {
    m_ptr = ptr;
}
std::string GCInfoPlayerTerrorist::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoPlayerTerrorist::IsValid() {
    return (m_ptr != nullptr);
}
GSpawnPoint GCInfoPlayerTerrorist::GetParent() const {
    GSpawnPoint value(m_ptr);
    return value;
}
void GCInfoPlayerTerrorist::SetParent(GSpawnPoint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoPlayerTerrorist(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoPlayerTerrorist>("CInfoPlayerTerrorist")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCInfoPlayerTerrorist::GetParent, &GCInfoPlayerTerrorist::SetParent)
        .addFunction("ToPtr", &GCInfoPlayerTerrorist::ToPtr)
        .addFunction("IsValid", &GCInfoPlayerTerrorist::IsValid)
        .endClass();
}