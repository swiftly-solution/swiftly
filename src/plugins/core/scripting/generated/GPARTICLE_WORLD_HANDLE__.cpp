#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GPARTICLE_WORLD_HANDLE__::GPARTICLE_WORLD_HANDLE__(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GPARTICLE_WORLD_HANDLE__::GPARTICLE_WORLD_HANDLE__(void *ptr) {
    m_ptr = ptr;
}
int32_t GPARTICLE_WORLD_HANDLE__::GetUnused() const {
    return GetSchemaValue<int32_t>(m_ptr, "PARTICLE_WORLD_HANDLE__", "unused");
}
void GPARTICLE_WORLD_HANDLE__::SetUnused(int32_t value) {
    SetSchemaValue(m_ptr, "PARTICLE_WORLD_HANDLE__", "unused", false, value);
}
std::string GPARTICLE_WORLD_HANDLE__::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GPARTICLE_WORLD_HANDLE__::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassPARTICLE_WORLD_HANDLE__(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPARTICLE_WORLD_HANDLE__>("PARTICLE_WORLD_HANDLE__")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Unused", &GPARTICLE_WORLD_HANDLE__::GetUnused, &GPARTICLE_WORLD_HANDLE__::SetUnused)
        .addFunction("ToPtr", &GPARTICLE_WORLD_HANDLE__::ToPtr)
        .addFunction("IsValid", &GPARTICLE_WORLD_HANDLE__::IsValid)
        .endClass();
}