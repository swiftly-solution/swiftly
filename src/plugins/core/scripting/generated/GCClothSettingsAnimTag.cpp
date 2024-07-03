#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCClothSettingsAnimTag::GCClothSettingsAnimTag(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCClothSettingsAnimTag::GCClothSettingsAnimTag(void *ptr) {
    m_ptr = ptr;
}
float GCClothSettingsAnimTag::GetStiffness() const {
    return GetSchemaValue<float>(m_ptr, "CClothSettingsAnimTag", "m_flStiffness");
}
void GCClothSettingsAnimTag::SetStiffness(float value) {
    SetSchemaValue(m_ptr, "CClothSettingsAnimTag", "m_flStiffness", false, value);
}
float GCClothSettingsAnimTag::GetEaseIn() const {
    return GetSchemaValue<float>(m_ptr, "CClothSettingsAnimTag", "m_flEaseIn");
}
void GCClothSettingsAnimTag::SetEaseIn(float value) {
    SetSchemaValue(m_ptr, "CClothSettingsAnimTag", "m_flEaseIn", false, value);
}
float GCClothSettingsAnimTag::GetEaseOut() const {
    return GetSchemaValue<float>(m_ptr, "CClothSettingsAnimTag", "m_flEaseOut");
}
void GCClothSettingsAnimTag::SetEaseOut(float value) {
    SetSchemaValue(m_ptr, "CClothSettingsAnimTag", "m_flEaseOut", false, value);
}
std::string GCClothSettingsAnimTag::GetVertexSet() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CClothSettingsAnimTag", "m_nVertexSet").Get();
}
void GCClothSettingsAnimTag::SetVertexSet(std::string value) {
    SetSchemaValue(m_ptr, "CClothSettingsAnimTag", "m_nVertexSet", false, CUtlString(value.c_str()));
}
std::string GCClothSettingsAnimTag::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCClothSettingsAnimTag::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimTagBase GCClothSettingsAnimTag::GetParent() const {
    GCAnimTagBase value(m_ptr);
    return value;
}
void GCClothSettingsAnimTag::SetParent(GCAnimTagBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCClothSettingsAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCClothSettingsAnimTag>("CClothSettingsAnimTag")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Stiffness", &GCClothSettingsAnimTag::GetStiffness, &GCClothSettingsAnimTag::SetStiffness)
        .addProperty("EaseIn", &GCClothSettingsAnimTag::GetEaseIn, &GCClothSettingsAnimTag::SetEaseIn)
        .addProperty("EaseOut", &GCClothSettingsAnimTag::GetEaseOut, &GCClothSettingsAnimTag::SetEaseOut)
        .addProperty("VertexSet", &GCClothSettingsAnimTag::GetVertexSet, &GCClothSettingsAnimTag::SetVertexSet)
        .addProperty("Parent", &GCClothSettingsAnimTag::GetParent, &GCClothSettingsAnimTag::SetParent)
        .addFunction("ToPtr", &GCClothSettingsAnimTag::ToPtr)
        .addFunction("IsValid", &GCClothSettingsAnimTag::IsValid)
        .endClass();
}