#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBlendCurve::GCBlendCurve(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBlendCurve::GCBlendCurve(void *ptr) {
    m_ptr = ptr;
}
float GCBlendCurve::GetControlPoint1() const {
    return GetSchemaValue<float>(m_ptr, "CBlendCurve", "m_flControlPoint1");
}
void GCBlendCurve::SetControlPoint1(float value) {
    SetSchemaValue(m_ptr, "CBlendCurve", "m_flControlPoint1", false, value);
}
float GCBlendCurve::GetControlPoint2() const {
    return GetSchemaValue<float>(m_ptr, "CBlendCurve", "m_flControlPoint2");
}
void GCBlendCurve::SetControlPoint2(float value) {
    SetSchemaValue(m_ptr, "CBlendCurve", "m_flControlPoint2", false, value);
}
std::string GCBlendCurve::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBlendCurve::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCBlendCurve(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBlendCurve>("CBlendCurve")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ControlPoint1", &GCBlendCurve::GetControlPoint1, &GCBlendCurve::SetControlPoint1)
        .addProperty("ControlPoint2", &GCBlendCurve::GetControlPoint2, &GCBlendCurve::SetControlPoint2)
        .addFunction("ToPtr", &GCBlendCurve::ToPtr)
        .addFunction("IsValid", &GCBlendCurve::IsValid)
        .endClass();
}