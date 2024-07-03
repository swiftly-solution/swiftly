#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCProjectedDecal::GCProjectedDecal(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCProjectedDecal::GCProjectedDecal(void *ptr) {
    m_ptr = ptr;
}
int32_t GCProjectedDecal::GetTexture() const {
    return GetSchemaValue<int32_t>(m_ptr, "CProjectedDecal", "m_nTexture");
}
void GCProjectedDecal::SetTexture(int32_t value) {
    SetSchemaValue(m_ptr, "CProjectedDecal", "m_nTexture", false, value);
}
float GCProjectedDecal::GetDistance() const {
    return GetSchemaValue<float>(m_ptr, "CProjectedDecal", "m_flDistance");
}
void GCProjectedDecal::SetDistance(float value) {
    SetSchemaValue(m_ptr, "CProjectedDecal", "m_flDistance", false, value);
}
std::string GCProjectedDecal::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCProjectedDecal::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCProjectedDecal::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCProjectedDecal::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCProjectedDecal(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCProjectedDecal>("CProjectedDecal")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Texture", &GCProjectedDecal::GetTexture, &GCProjectedDecal::SetTexture)
        .addProperty("Distance", &GCProjectedDecal::GetDistance, &GCProjectedDecal::SetDistance)
        .addProperty("Parent", &GCProjectedDecal::GetParent, &GCProjectedDecal::SetParent)
        .addFunction("ToPtr", &GCProjectedDecal::ToPtr)
        .addFunction("IsValid", &GCProjectedDecal::IsValid)
        .endClass();
}