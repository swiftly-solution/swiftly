#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeBuildTaperedCapsuleRigid_t::GFeBuildTaperedCapsuleRigid_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeBuildTaperedCapsuleRigid_t::GFeBuildTaperedCapsuleRigid_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GFeBuildTaperedCapsuleRigid_t::GetPriority() const {
    return GetSchemaValue<int32_t>(m_ptr, "FeBuildTaperedCapsuleRigid_t", "m_nPriority");
}
void GFeBuildTaperedCapsuleRigid_t::SetPriority(int32_t value) {
    SetSchemaValue(m_ptr, "FeBuildTaperedCapsuleRigid_t", "m_nPriority", true, value);
}
uint32_t GFeBuildTaperedCapsuleRigid_t::GetVertexMapHash() const {
    return GetSchemaValue<uint32_t>(m_ptr, "FeBuildTaperedCapsuleRigid_t", "m_nVertexMapHash");
}
void GFeBuildTaperedCapsuleRigid_t::SetVertexMapHash(uint32_t value) {
    SetSchemaValue(m_ptr, "FeBuildTaperedCapsuleRigid_t", "m_nVertexMapHash", true, value);
}
std::string GFeBuildTaperedCapsuleRigid_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeBuildTaperedCapsuleRigid_t::IsValid() {
    return (m_ptr != nullptr);
}
GFeTaperedCapsuleRigid_t GFeBuildTaperedCapsuleRigid_t::GetParent() const {
    GFeTaperedCapsuleRigid_t value(m_ptr);
    return value;
}
void GFeBuildTaperedCapsuleRigid_t::SetParent(GFeTaperedCapsuleRigid_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassFeBuildTaperedCapsuleRigid_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeBuildTaperedCapsuleRigid_t>("FeBuildTaperedCapsuleRigid_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Priority", &GFeBuildTaperedCapsuleRigid_t::GetPriority, &GFeBuildTaperedCapsuleRigid_t::SetPriority)
        .addProperty("VertexMapHash", &GFeBuildTaperedCapsuleRigid_t::GetVertexMapHash, &GFeBuildTaperedCapsuleRigid_t::SetVertexMapHash)
        .addProperty("Parent", &GFeBuildTaperedCapsuleRigid_t::GetParent, &GFeBuildTaperedCapsuleRigid_t::SetParent)
        .addFunction("ToPtr", &GFeBuildTaperedCapsuleRigid_t::ToPtr)
        .addFunction("IsValid", &GFeBuildTaperedCapsuleRigid_t::IsValid)
        .endClass();
}