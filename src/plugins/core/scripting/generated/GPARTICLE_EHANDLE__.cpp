#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GPARTICLE_EHANDLE__::GPARTICLE_EHANDLE__(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GPARTICLE_EHANDLE__::GPARTICLE_EHANDLE__(void *ptr) {
    m_ptr = ptr;
}
int32_t GPARTICLE_EHANDLE__::GetUnused() const {
    return GetSchemaValue<int32_t>(m_ptr, "PARTICLE_EHANDLE__", "unused");
}
void GPARTICLE_EHANDLE__::SetUnused(int32_t value) {
    SetSchemaValue(m_ptr, "PARTICLE_EHANDLE__", "unused", false, value);
}
std::string GPARTICLE_EHANDLE__::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GPARTICLE_EHANDLE__::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassPARTICLE_EHANDLE__(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPARTICLE_EHANDLE__>("PARTICLE_EHANDLE__")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Unused", &GPARTICLE_EHANDLE__::GetUnused, &GPARTICLE_EHANDLE__::SetUnused)
        .addFunction("ToPtr", &GPARTICLE_EHANDLE__::ToPtr)
        .addFunction("IsValid", &GPARTICLE_EHANDLE__::IsValid)
        .endClass();
}