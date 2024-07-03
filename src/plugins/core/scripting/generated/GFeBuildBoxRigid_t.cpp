#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeBuildBoxRigid_t::GFeBuildBoxRigid_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeBuildBoxRigid_t::GFeBuildBoxRigid_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GFeBuildBoxRigid_t::GetPriority() const {
    return GetSchemaValue<int32_t>(m_ptr, "FeBuildBoxRigid_t", "m_nPriority");
}
void GFeBuildBoxRigid_t::SetPriority(int32_t value) {
    SetSchemaValue(m_ptr, "FeBuildBoxRigid_t", "m_nPriority", true, value);
}
uint32_t GFeBuildBoxRigid_t::GetVertexMapHash() const {
    return GetSchemaValue<uint32_t>(m_ptr, "FeBuildBoxRigid_t", "m_nVertexMapHash");
}
void GFeBuildBoxRigid_t::SetVertexMapHash(uint32_t value) {
    SetSchemaValue(m_ptr, "FeBuildBoxRigid_t", "m_nVertexMapHash", true, value);
}
std::string GFeBuildBoxRigid_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeBuildBoxRigid_t::IsValid() {
    return (m_ptr != nullptr);
}
GFeBoxRigid_t GFeBuildBoxRigid_t::GetParent() const {
    GFeBoxRigid_t value(m_ptr);
    return value;
}
void GFeBuildBoxRigid_t::SetParent(GFeBoxRigid_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassFeBuildBoxRigid_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeBuildBoxRigid_t>("FeBuildBoxRigid_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Priority", &GFeBuildBoxRigid_t::GetPriority, &GFeBuildBoxRigid_t::SetPriority)
        .addProperty("VertexMapHash", &GFeBuildBoxRigid_t::GetVertexMapHash, &GFeBuildBoxRigid_t::SetVertexMapHash)
        .addProperty("Parent", &GFeBuildBoxRigid_t::GetParent, &GFeBuildBoxRigid_t::SetParent)
        .addFunction("ToPtr", &GFeBuildBoxRigid_t::ToPtr)
        .addFunction("IsValid", &GFeBuildBoxRigid_t::IsValid)
        .endClass();
}