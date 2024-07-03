#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointCameraVFOV::GCPointCameraVFOV(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointCameraVFOV::GCPointCameraVFOV(void *ptr) {
    m_ptr = ptr;
}
float GCPointCameraVFOV::GetVerticalFOV() const {
    return GetSchemaValue<float>(m_ptr, "CPointCameraVFOV", "m_flVerticalFOV");
}
void GCPointCameraVFOV::SetVerticalFOV(float value) {
    SetSchemaValue(m_ptr, "CPointCameraVFOV", "m_flVerticalFOV", false, value);
}
std::string GCPointCameraVFOV::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointCameraVFOV::IsValid() {
    return (m_ptr != nullptr);
}
GCPointCamera GCPointCameraVFOV::GetParent() const {
    GCPointCamera value(m_ptr);
    return value;
}
void GCPointCameraVFOV::SetParent(GCPointCamera value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointCameraVFOV(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointCameraVFOV>("CPointCameraVFOV")
        .addConstructor<void (*)(std::string)>()
        .addProperty("VerticalFOV", &GCPointCameraVFOV::GetVerticalFOV, &GCPointCameraVFOV::SetVerticalFOV)
        .addProperty("Parent", &GCPointCameraVFOV::GetParent, &GCPointCameraVFOV::SetParent)
        .addFunction("ToPtr", &GCPointCameraVFOV::ToPtr)
        .addFunction("IsValid", &GCPointCameraVFOV::IsValid)
        .endClass();
}