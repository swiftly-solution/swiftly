#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMathColorBlend::GCMathColorBlend(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMathColorBlend::GCMathColorBlend(void *ptr) {
    m_ptr = ptr;
}
float GCMathColorBlend::GetInMin() const {
    return GetSchemaValue<float>(m_ptr, "CMathColorBlend", "m_flInMin");
}
void GCMathColorBlend::SetInMin(float value) {
    SetSchemaValue(m_ptr, "CMathColorBlend", "m_flInMin", false, value);
}
float GCMathColorBlend::GetInMax() const {
    return GetSchemaValue<float>(m_ptr, "CMathColorBlend", "m_flInMax");
}
void GCMathColorBlend::SetInMax(float value) {
    SetSchemaValue(m_ptr, "CMathColorBlend", "m_flInMax", false, value);
}
Color GCMathColorBlend::GetOutColor1() const {
    return GetSchemaValue<Color>(m_ptr, "CMathColorBlend", "m_OutColor1");
}
void GCMathColorBlend::SetOutColor1(Color value) {
    SetSchemaValue(m_ptr, "CMathColorBlend", "m_OutColor1", false, value);
}
Color GCMathColorBlend::GetOutColor2() const {
    return GetSchemaValue<Color>(m_ptr, "CMathColorBlend", "m_OutColor2");
}
void GCMathColorBlend::SetOutColor2(Color value) {
    SetSchemaValue(m_ptr, "CMathColorBlend", "m_OutColor2", false, value);
}
std::string GCMathColorBlend::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMathColorBlend::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCMathColorBlend::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCMathColorBlend::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMathColorBlend(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMathColorBlend>("CMathColorBlend")
        .addConstructor<void (*)(std::string)>()
        .addProperty("InMin", &GCMathColorBlend::GetInMin, &GCMathColorBlend::SetInMin)
        .addProperty("InMax", &GCMathColorBlend::GetInMax, &GCMathColorBlend::SetInMax)
        .addProperty("OutColor1", &GCMathColorBlend::GetOutColor1, &GCMathColorBlend::SetOutColor1)
        .addProperty("OutColor2", &GCMathColorBlend::GetOutColor2, &GCMathColorBlend::SetOutColor2)
        .addProperty("Parent", &GCMathColorBlend::GetParent, &GCMathColorBlend::SetParent)
        .addFunction("ToPtr", &GCMathColorBlend::ToPtr)
        .addFunction("IsValid", &GCMathColorBlend::IsValid)
        .endClass();
}