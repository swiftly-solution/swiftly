#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSkyboxReference::GCSkyboxReference(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSkyboxReference::GCSkyboxReference(void *ptr) {
    m_ptr = ptr;
}
WorldGroupId_t GCSkyboxReference::GetWorldGroupId() const {
    return GetSchemaValue<WorldGroupId_t>(m_ptr, "CSkyboxReference", "m_worldGroupId");
}
void GCSkyboxReference::SetWorldGroupId(WorldGroupId_t value) {
    SetSchemaValue(m_ptr, "CSkyboxReference", "m_worldGroupId", false, value);
}
GCSkyCamera GCSkyboxReference::GetSkyCamera() const {
    GCSkyCamera value(*GetSchemaValuePtr<void*>(m_ptr, "CSkyboxReference", "m_hSkyCamera"));
    return value;
}
void GCSkyboxReference::SetSkyCamera(GCSkyCamera* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'SkyCamera' is not possible.\n");
}
std::string GCSkyboxReference::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSkyboxReference::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCSkyboxReference::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCSkyboxReference::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSkyboxReference(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSkyboxReference>("CSkyboxReference")
        .addConstructor<void (*)(std::string)>()
        .addProperty("WorldGroupId", &GCSkyboxReference::GetWorldGroupId, &GCSkyboxReference::SetWorldGroupId)
        .addProperty("SkyCamera", &GCSkyboxReference::GetSkyCamera, &GCSkyboxReference::SetSkyCamera)
        .addProperty("Parent", &GCSkyboxReference::GetParent, &GCSkyboxReference::SetParent)
        .addFunction("ToPtr", &GCSkyboxReference::ToPtr)
        .addFunction("IsValid", &GCSkyboxReference::IsValid)
        .endClass();
}