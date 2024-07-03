#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRnMeshDesc_t::GRnMeshDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRnMeshDesc_t::GRnMeshDesc_t(void *ptr) {
    m_ptr = ptr;
}
GRnMesh_t GRnMeshDesc_t::GetMesh() const {
    GRnMesh_t value(GetSchemaPtr(m_ptr, "RnMeshDesc_t", "m_Mesh"));
    return value;
}
void GRnMeshDesc_t::SetMesh(GRnMesh_t value) {
    SetSchemaValue(m_ptr, "RnMeshDesc_t", "m_Mesh", true, value);
}
std::string GRnMeshDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRnMeshDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
GRnShapeDesc_t GRnMeshDesc_t::GetParent() const {
    GRnShapeDesc_t value(m_ptr);
    return value;
}
void GRnMeshDesc_t::SetParent(GRnShapeDesc_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassRnMeshDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnMeshDesc_t>("RnMeshDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Mesh", &GRnMeshDesc_t::GetMesh, &GRnMeshDesc_t::SetMesh)
        .addProperty("Parent", &GRnMeshDesc_t::GetParent, &GRnMeshDesc_t::SetParent)
        .addFunction("ToPtr", &GRnMeshDesc_t::ToPtr)
        .addFunction("IsValid", &GRnMeshDesc_t::IsValid)
        .endClass();
}