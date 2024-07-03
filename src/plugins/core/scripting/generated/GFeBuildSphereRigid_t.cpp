#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeBuildSphereRigid_t::GFeBuildSphereRigid_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeBuildSphereRigid_t::GFeBuildSphereRigid_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GFeBuildSphereRigid_t::GetPriority() const {
    return GetSchemaValue<int32_t>(m_ptr, "FeBuildSphereRigid_t", "m_nPriority");
}
void GFeBuildSphereRigid_t::SetPriority(int32_t value) {
    SetSchemaValue(m_ptr, "FeBuildSphereRigid_t", "m_nPriority", true, value);
}
uint32_t GFeBuildSphereRigid_t::GetVertexMapHash() const {
    return GetSchemaValue<uint32_t>(m_ptr, "FeBuildSphereRigid_t", "m_nVertexMapHash");
}
void GFeBuildSphereRigid_t::SetVertexMapHash(uint32_t value) {
    SetSchemaValue(m_ptr, "FeBuildSphereRigid_t", "m_nVertexMapHash", true, value);
}
std::string GFeBuildSphereRigid_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeBuildSphereRigid_t::IsValid() {
    return (m_ptr != nullptr);
}
GFeSphereRigid_t GFeBuildSphereRigid_t::GetParent() const {
    GFeSphereRigid_t value(m_ptr);
    return value;
}
void GFeBuildSphereRigid_t::SetParent(GFeSphereRigid_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassFeBuildSphereRigid_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeBuildSphereRigid_t>("FeBuildSphereRigid_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Priority", &GFeBuildSphereRigid_t::GetPriority, &GFeBuildSphereRigid_t::SetPriority)
        .addProperty("VertexMapHash", &GFeBuildSphereRigid_t::GetVertexMapHash, &GFeBuildSphereRigid_t::SetVertexMapHash)
        .addProperty("Parent", &GFeBuildSphereRigid_t::GetParent, &GFeBuildSphereRigid_t::SetParent)
        .addFunction("ToPtr", &GFeBuildSphereRigid_t::ToPtr)
        .addFunction("IsValid", &GFeBuildSphereRigid_t::IsValid)
        .endClass();
}