#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCastSphereSATParams_t::GCastSphereSATParams_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCastSphereSATParams_t::GCastSphereSATParams_t(void *ptr) {
    m_ptr = ptr;
}
Vector GCastSphereSATParams_t::GetRayStart() const {
    return GetSchemaValue<Vector>(m_ptr, "CastSphereSATParams_t", "m_vRayStart");
}
void GCastSphereSATParams_t::SetRayStart(Vector value) {
    SetSchemaValue(m_ptr, "CastSphereSATParams_t", "m_vRayStart", true, value);
}
Vector GCastSphereSATParams_t::GetRayDelta() const {
    return GetSchemaValue<Vector>(m_ptr, "CastSphereSATParams_t", "m_vRayDelta");
}
void GCastSphereSATParams_t::SetRayDelta(Vector value) {
    SetSchemaValue(m_ptr, "CastSphereSATParams_t", "m_vRayDelta", true, value);
}
float GCastSphereSATParams_t::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CastSphereSATParams_t", "m_flRadius");
}
void GCastSphereSATParams_t::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CastSphereSATParams_t", "m_flRadius", true, value);
}
float GCastSphereSATParams_t::GetMaxFraction() const {
    return GetSchemaValue<float>(m_ptr, "CastSphereSATParams_t", "m_flMaxFraction");
}
void GCastSphereSATParams_t::SetMaxFraction(float value) {
    SetSchemaValue(m_ptr, "CastSphereSATParams_t", "m_flMaxFraction", true, value);
}
float GCastSphereSATParams_t::GetScale() const {
    return GetSchemaValue<float>(m_ptr, "CastSphereSATParams_t", "m_flScale");
}
void GCastSphereSATParams_t::SetScale(float value) {
    SetSchemaValue(m_ptr, "CastSphereSATParams_t", "m_flScale", true, value);
}
GRnHull_t GCastSphereSATParams_t::GetHull() const {
    GRnHull_t value(*GetSchemaValuePtr<void*>(m_ptr, "CastSphereSATParams_t", "m_pHull"));
    return value;
}
void GCastSphereSATParams_t::SetHull(GRnHull_t* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Hull' is not possible.\n");
}
std::string GCastSphereSATParams_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCastSphereSATParams_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCastSphereSATParams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCastSphereSATParams_t>("CastSphereSATParams_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("RayStart", &GCastSphereSATParams_t::GetRayStart, &GCastSphereSATParams_t::SetRayStart)
        .addProperty("RayDelta", &GCastSphereSATParams_t::GetRayDelta, &GCastSphereSATParams_t::SetRayDelta)
        .addProperty("Radius", &GCastSphereSATParams_t::GetRadius, &GCastSphereSATParams_t::SetRadius)
        .addProperty("MaxFraction", &GCastSphereSATParams_t::GetMaxFraction, &GCastSphereSATParams_t::SetMaxFraction)
        .addProperty("Scale", &GCastSphereSATParams_t::GetScale, &GCastSphereSATParams_t::SetScale)
        .addProperty("Hull", &GCastSphereSATParams_t::GetHull, &GCastSphereSATParams_t::SetHull)
        .addFunction("ToPtr", &GCastSphereSATParams_t::ToPtr)
        .addFunction("IsValid", &GCastSphereSATParams_t::IsValid)
        .endClass();
}