#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GPointCameraSettings_t::GPointCameraSettings_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GPointCameraSettings_t::GPointCameraSettings_t(void *ptr) {
    m_ptr = ptr;
}
float GPointCameraSettings_t::GetNearBlurryDistance() const {
    return GetSchemaValue<float>(m_ptr, "PointCameraSettings_t", "m_flNearBlurryDistance");
}
void GPointCameraSettings_t::SetNearBlurryDistance(float value) {
    SetSchemaValue(m_ptr, "PointCameraSettings_t", "m_flNearBlurryDistance", true, value);
}
float GPointCameraSettings_t::GetNearCrispDistance() const {
    return GetSchemaValue<float>(m_ptr, "PointCameraSettings_t", "m_flNearCrispDistance");
}
void GPointCameraSettings_t::SetNearCrispDistance(float value) {
    SetSchemaValue(m_ptr, "PointCameraSettings_t", "m_flNearCrispDistance", true, value);
}
float GPointCameraSettings_t::GetFarCrispDistance() const {
    return GetSchemaValue<float>(m_ptr, "PointCameraSettings_t", "m_flFarCrispDistance");
}
void GPointCameraSettings_t::SetFarCrispDistance(float value) {
    SetSchemaValue(m_ptr, "PointCameraSettings_t", "m_flFarCrispDistance", true, value);
}
float GPointCameraSettings_t::GetFarBlurryDistance() const {
    return GetSchemaValue<float>(m_ptr, "PointCameraSettings_t", "m_flFarBlurryDistance");
}
void GPointCameraSettings_t::SetFarBlurryDistance(float value) {
    SetSchemaValue(m_ptr, "PointCameraSettings_t", "m_flFarBlurryDistance", true, value);
}
std::string GPointCameraSettings_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GPointCameraSettings_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassPointCameraSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPointCameraSettings_t>("PointCameraSettings_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NearBlurryDistance", &GPointCameraSettings_t::GetNearBlurryDistance, &GPointCameraSettings_t::SetNearBlurryDistance)
        .addProperty("NearCrispDistance", &GPointCameraSettings_t::GetNearCrispDistance, &GPointCameraSettings_t::SetNearCrispDistance)
        .addProperty("FarCrispDistance", &GPointCameraSettings_t::GetFarCrispDistance, &GPointCameraSettings_t::SetFarCrispDistance)
        .addProperty("FarBlurryDistance", &GPointCameraSettings_t::GetFarBlurryDistance, &GPointCameraSettings_t::SetFarBlurryDistance)
        .addFunction("ToPtr", &GPointCameraSettings_t::ToPtr)
        .addFunction("IsValid", &GPointCameraSettings_t::IsValid)
        .endClass();
}