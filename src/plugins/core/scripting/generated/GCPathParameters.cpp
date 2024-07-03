#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPathParameters::GCPathParameters(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPathParameters::GCPathParameters(void *ptr) {
    m_ptr = ptr;
}
int32_t GCPathParameters::GetStartControlPointNumber() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPathParameters", "m_nStartControlPointNumber");
}
void GCPathParameters::SetStartControlPointNumber(int32_t value) {
    SetSchemaValue(m_ptr, "CPathParameters", "m_nStartControlPointNumber", false, value);
}
int32_t GCPathParameters::GetEndControlPointNumber() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPathParameters", "m_nEndControlPointNumber");
}
void GCPathParameters::SetEndControlPointNumber(int32_t value) {
    SetSchemaValue(m_ptr, "CPathParameters", "m_nEndControlPointNumber", false, value);
}
int32_t GCPathParameters::GetBulgeControl() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPathParameters", "m_nBulgeControl");
}
void GCPathParameters::SetBulgeControl(int32_t value) {
    SetSchemaValue(m_ptr, "CPathParameters", "m_nBulgeControl", false, value);
}
float GCPathParameters::GetBulge() const {
    return GetSchemaValue<float>(m_ptr, "CPathParameters", "m_flBulge");
}
void GCPathParameters::SetBulge(float value) {
    SetSchemaValue(m_ptr, "CPathParameters", "m_flBulge", false, value);
}
float GCPathParameters::GetMidPoint() const {
    return GetSchemaValue<float>(m_ptr, "CPathParameters", "m_flMidPoint");
}
void GCPathParameters::SetMidPoint(float value) {
    SetSchemaValue(m_ptr, "CPathParameters", "m_flMidPoint", false, value);
}
Vector GCPathParameters::GetStartPointOffset() const {
    return GetSchemaValue<Vector>(m_ptr, "CPathParameters", "m_vStartPointOffset");
}
void GCPathParameters::SetStartPointOffset(Vector value) {
    SetSchemaValue(m_ptr, "CPathParameters", "m_vStartPointOffset", false, value);
}
Vector GCPathParameters::GetMidPointOffset() const {
    return GetSchemaValue<Vector>(m_ptr, "CPathParameters", "m_vMidPointOffset");
}
void GCPathParameters::SetMidPointOffset(Vector value) {
    SetSchemaValue(m_ptr, "CPathParameters", "m_vMidPointOffset", false, value);
}
Vector GCPathParameters::GetEndOffset() const {
    return GetSchemaValue<Vector>(m_ptr, "CPathParameters", "m_vEndOffset");
}
void GCPathParameters::SetEndOffset(Vector value) {
    SetSchemaValue(m_ptr, "CPathParameters", "m_vEndOffset", false, value);
}
std::string GCPathParameters::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPathParameters::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCPathParameters(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathParameters>("CPathParameters")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StartControlPointNumber", &GCPathParameters::GetStartControlPointNumber, &GCPathParameters::SetStartControlPointNumber)
        .addProperty("EndControlPointNumber", &GCPathParameters::GetEndControlPointNumber, &GCPathParameters::SetEndControlPointNumber)
        .addProperty("BulgeControl", &GCPathParameters::GetBulgeControl, &GCPathParameters::SetBulgeControl)
        .addProperty("Bulge", &GCPathParameters::GetBulge, &GCPathParameters::SetBulge)
        .addProperty("MidPoint", &GCPathParameters::GetMidPoint, &GCPathParameters::SetMidPoint)
        .addProperty("StartPointOffset", &GCPathParameters::GetStartPointOffset, &GCPathParameters::SetStartPointOffset)
        .addProperty("MidPointOffset", &GCPathParameters::GetMidPointOffset, &GCPathParameters::SetMidPointOffset)
        .addProperty("EndOffset", &GCPathParameters::GetEndOffset, &GCPathParameters::SetEndOffset)
        .addFunction("ToPtr", &GCPathParameters::ToPtr)
        .addFunction("IsValid", &GCPathParameters::IsValid)
        .endClass();
}