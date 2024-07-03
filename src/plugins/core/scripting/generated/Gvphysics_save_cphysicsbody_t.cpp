#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

Gvphysics_save_cphysicsbody_t::Gvphysics_save_cphysicsbody_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
Gvphysics_save_cphysicsbody_t::Gvphysics_save_cphysicsbody_t(void *ptr) {
    m_ptr = ptr;
}
uint64_t Gvphysics_save_cphysicsbody_t::GetOldPointer() const {
    return GetSchemaValue<uint64_t>(m_ptr, "vphysics_save_cphysicsbody_t", "m_nOldPointer");
}
void Gvphysics_save_cphysicsbody_t::SetOldPointer(uint64_t value) {
    SetSchemaValue(m_ptr, "vphysics_save_cphysicsbody_t", "m_nOldPointer", true, value);
}
std::string Gvphysics_save_cphysicsbody_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool Gvphysics_save_cphysicsbody_t::IsValid() {
    return (m_ptr != nullptr);
}
GRnBodyDesc_t Gvphysics_save_cphysicsbody_t::GetParent() const {
    GRnBodyDesc_t value(m_ptr);
    return value;
}
void Gvphysics_save_cphysicsbody_t::SetParent(GRnBodyDesc_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassvphysics_save_cphysicsbody_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gvphysics_save_cphysicsbody_t>("vphysics_save_cphysicsbody_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OldPointer", &Gvphysics_save_cphysicsbody_t::GetOldPointer, &Gvphysics_save_cphysicsbody_t::SetOldPointer)
        .addProperty("Parent", &Gvphysics_save_cphysicsbody_t::GetParent, &Gvphysics_save_cphysicsbody_t::SetParent)
        .addFunction("ToPtr", &Gvphysics_save_cphysicsbody_t::ToPtr)
        .addFunction("IsValid", &Gvphysics_save_cphysicsbody_t::IsValid)
        .endClass();
}