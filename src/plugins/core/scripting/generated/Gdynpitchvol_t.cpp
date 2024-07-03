#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

Gdynpitchvol_t::Gdynpitchvol_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
Gdynpitchvol_t::Gdynpitchvol_t(void *ptr) {
    m_ptr = ptr;
}
std::string Gdynpitchvol_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool Gdynpitchvol_t::IsValid() {
    return (m_ptr != nullptr);
}
Gdynpitchvol_base_t Gdynpitchvol_t::GetParent() const {
    Gdynpitchvol_base_t value(m_ptr);
    return value;
}
void Gdynpitchvol_t::SetParent(Gdynpitchvol_base_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassdynpitchvol_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gdynpitchvol_t>("dynpitchvol_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &Gdynpitchvol_t::GetParent, &Gdynpitchvol_t::SetParent)
        .addFunction("ToPtr", &Gdynpitchvol_t::ToPtr)
        .addFunction("IsValid", &Gdynpitchvol_t::IsValid)
        .endClass();
}