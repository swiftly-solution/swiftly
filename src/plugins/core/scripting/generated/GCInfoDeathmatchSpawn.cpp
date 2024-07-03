#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoDeathmatchSpawn::GCInfoDeathmatchSpawn(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoDeathmatchSpawn::GCInfoDeathmatchSpawn(void *ptr) {
    m_ptr = ptr;
}
std::string GCInfoDeathmatchSpawn::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoDeathmatchSpawn::IsValid() {
    return (m_ptr != nullptr);
}
GSpawnPoint GCInfoDeathmatchSpawn::GetParent() const {
    GSpawnPoint value(m_ptr);
    return value;
}
void GCInfoDeathmatchSpawn::SetParent(GSpawnPoint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoDeathmatchSpawn(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoDeathmatchSpawn>("CInfoDeathmatchSpawn")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCInfoDeathmatchSpawn::GetParent, &GCInfoDeathmatchSpawn::SetParent)
        .addFunction("ToPtr", &GCInfoDeathmatchSpawn::ToPtr)
        .addFunction("IsValid", &GCInfoDeathmatchSpawn::IsValid)
        .endClass();
}