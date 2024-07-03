#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFourCovMatrices3::GFourCovMatrices3(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFourCovMatrices3::GFourCovMatrices3(void *ptr) {
    m_ptr = ptr;
}
float GFourCovMatrices3::GetXY() const {
    return GetSchemaValue<float>(m_ptr, "FourCovMatrices3", "m_flXY");
}
void GFourCovMatrices3::SetXY(float value) {
    SetSchemaValue(m_ptr, "FourCovMatrices3", "m_flXY", false, value);
}
float GFourCovMatrices3::GetXZ() const {
    return GetSchemaValue<float>(m_ptr, "FourCovMatrices3", "m_flXZ");
}
void GFourCovMatrices3::SetXZ(float value) {
    SetSchemaValue(m_ptr, "FourCovMatrices3", "m_flXZ", false, value);
}
float GFourCovMatrices3::GetYZ() const {
    return GetSchemaValue<float>(m_ptr, "FourCovMatrices3", "m_flYZ");
}
void GFourCovMatrices3::SetYZ(float value) {
    SetSchemaValue(m_ptr, "FourCovMatrices3", "m_flYZ", false, value);
}
std::string GFourCovMatrices3::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFourCovMatrices3::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFourCovMatrices3(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFourCovMatrices3>("FourCovMatrices3")
        .addConstructor<void (*)(std::string)>()
        .addProperty("XY", &GFourCovMatrices3::GetXY, &GFourCovMatrices3::SetXY)
        .addProperty("XZ", &GFourCovMatrices3::GetXZ, &GFourCovMatrices3::SetXZ)
        .addProperty("YZ", &GFourCovMatrices3::GetYZ, &GFourCovMatrices3::SetYZ)
        .addFunction("ToPtr", &GFourCovMatrices3::ToPtr)
        .addFunction("IsValid", &GFourCovMatrices3::IsValid)
        .endClass();
}