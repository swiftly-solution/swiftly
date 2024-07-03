#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMorphConstraint::GCMorphConstraint(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMorphConstraint::GCMorphConstraint(void *ptr) {
    m_ptr = ptr;
}
std::string GCMorphConstraint::GetTargetMorph() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CMorphConstraint", "m_sTargetMorph").Get();
}
void GCMorphConstraint::SetTargetMorph(std::string value) {
    SetSchemaValue(m_ptr, "CMorphConstraint", "m_sTargetMorph", false, CUtlString(value.c_str()));
}
int32_t GCMorphConstraint::GetSlaveChannel() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMorphConstraint", "m_nSlaveChannel");
}
void GCMorphConstraint::SetSlaveChannel(int32_t value) {
    SetSchemaValue(m_ptr, "CMorphConstraint", "m_nSlaveChannel", false, value);
}
float GCMorphConstraint::GetMin() const {
    return GetSchemaValue<float>(m_ptr, "CMorphConstraint", "m_flMin");
}
void GCMorphConstraint::SetMin(float value) {
    SetSchemaValue(m_ptr, "CMorphConstraint", "m_flMin", false, value);
}
float GCMorphConstraint::GetMax() const {
    return GetSchemaValue<float>(m_ptr, "CMorphConstraint", "m_flMax");
}
void GCMorphConstraint::SetMax(float value) {
    SetSchemaValue(m_ptr, "CMorphConstraint", "m_flMax", false, value);
}
std::string GCMorphConstraint::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMorphConstraint::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseConstraint GCMorphConstraint::GetParent() const {
    GCBaseConstraint value(m_ptr);
    return value;
}
void GCMorphConstraint::SetParent(GCBaseConstraint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMorphConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMorphConstraint>("CMorphConstraint")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TargetMorph", &GCMorphConstraint::GetTargetMorph, &GCMorphConstraint::SetTargetMorph)
        .addProperty("SlaveChannel", &GCMorphConstraint::GetSlaveChannel, &GCMorphConstraint::SetSlaveChannel)
        .addProperty("Min", &GCMorphConstraint::GetMin, &GCMorphConstraint::SetMin)
        .addProperty("Max", &GCMorphConstraint::GetMax, &GCMorphConstraint::SetMax)
        .addProperty("Parent", &GCMorphConstraint::GetParent, &GCMorphConstraint::SetParent)
        .addFunction("ToPtr", &GCMorphConstraint::ToPtr)
        .addFunction("IsValid", &GCMorphConstraint::IsValid)
        .endClass();
}