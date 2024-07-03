#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNavVolumeSphericalShell::GCNavVolumeSphericalShell(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNavVolumeSphericalShell::GCNavVolumeSphericalShell(void *ptr) {
    m_ptr = ptr;
}
float GCNavVolumeSphericalShell::GetRadiusInner() const {
    return GetSchemaValue<float>(m_ptr, "CNavVolumeSphericalShell", "m_flRadiusInner");
}
void GCNavVolumeSphericalShell::SetRadiusInner(float value) {
    SetSchemaValue(m_ptr, "CNavVolumeSphericalShell", "m_flRadiusInner", false, value);
}
std::string GCNavVolumeSphericalShell::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNavVolumeSphericalShell::IsValid() {
    return (m_ptr != nullptr);
}
GCNavVolumeSphere GCNavVolumeSphericalShell::GetParent() const {
    GCNavVolumeSphere value(m_ptr);
    return value;
}
void GCNavVolumeSphericalShell::SetParent(GCNavVolumeSphere value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNavVolumeSphericalShell(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavVolumeSphericalShell>("CNavVolumeSphericalShell")
        .addConstructor<void (*)(std::string)>()
        .addProperty("RadiusInner", &GCNavVolumeSphericalShell::GetRadiusInner, &GCNavVolumeSphericalShell::SetRadiusInner)
        .addProperty("Parent", &GCNavVolumeSphericalShell::GetParent, &GCNavVolumeSphericalShell::SetParent)
        .addFunction("ToPtr", &GCNavVolumeSphericalShell::ToPtr)
        .addFunction("IsValid", &GCNavVolumeSphericalShell::IsValid)
        .endClass();
}