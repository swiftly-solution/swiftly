#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDampedPathAnimMotorUpdater::GCDampedPathAnimMotorUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDampedPathAnimMotorUpdater::GCDampedPathAnimMotorUpdater(void *ptr) {
    m_ptr = ptr;
}
float GCDampedPathAnimMotorUpdater::GetAnticipationTime() const {
    return GetSchemaValue<float>(m_ptr, "CDampedPathAnimMotorUpdater", "m_flAnticipationTime");
}
void GCDampedPathAnimMotorUpdater::SetAnticipationTime(float value) {
    SetSchemaValue(m_ptr, "CDampedPathAnimMotorUpdater", "m_flAnticipationTime", false, value);
}
float GCDampedPathAnimMotorUpdater::GetMinSpeedScale() const {
    return GetSchemaValue<float>(m_ptr, "CDampedPathAnimMotorUpdater", "m_flMinSpeedScale");
}
void GCDampedPathAnimMotorUpdater::SetMinSpeedScale(float value) {
    SetSchemaValue(m_ptr, "CDampedPathAnimMotorUpdater", "m_flMinSpeedScale", false, value);
}
GCAnimParamHandle GCDampedPathAnimMotorUpdater::GetAnticipationPosParam() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CDampedPathAnimMotorUpdater", "m_hAnticipationPosParam"));
    return value;
}
void GCDampedPathAnimMotorUpdater::SetAnticipationPosParam(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CDampedPathAnimMotorUpdater", "m_hAnticipationPosParam", false, value);
}
GCAnimParamHandle GCDampedPathAnimMotorUpdater::GetAnticipationHeadingParam() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CDampedPathAnimMotorUpdater", "m_hAnticipationHeadingParam"));
    return value;
}
void GCDampedPathAnimMotorUpdater::SetAnticipationHeadingParam(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CDampedPathAnimMotorUpdater", "m_hAnticipationHeadingParam", false, value);
}
float GCDampedPathAnimMotorUpdater::GetSpringConstant() const {
    return GetSchemaValue<float>(m_ptr, "CDampedPathAnimMotorUpdater", "m_flSpringConstant");
}
void GCDampedPathAnimMotorUpdater::SetSpringConstant(float value) {
    SetSchemaValue(m_ptr, "CDampedPathAnimMotorUpdater", "m_flSpringConstant", false, value);
}
float GCDampedPathAnimMotorUpdater::GetMinSpringTension() const {
    return GetSchemaValue<float>(m_ptr, "CDampedPathAnimMotorUpdater", "m_flMinSpringTension");
}
void GCDampedPathAnimMotorUpdater::SetMinSpringTension(float value) {
    SetSchemaValue(m_ptr, "CDampedPathAnimMotorUpdater", "m_flMinSpringTension", false, value);
}
float GCDampedPathAnimMotorUpdater::GetMaxSpringTension() const {
    return GetSchemaValue<float>(m_ptr, "CDampedPathAnimMotorUpdater", "m_flMaxSpringTension");
}
void GCDampedPathAnimMotorUpdater::SetMaxSpringTension(float value) {
    SetSchemaValue(m_ptr, "CDampedPathAnimMotorUpdater", "m_flMaxSpringTension", false, value);
}
std::string GCDampedPathAnimMotorUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDampedPathAnimMotorUpdater::IsValid() {
    return (m_ptr != nullptr);
}
GCPathAnimMotorUpdaterBase GCDampedPathAnimMotorUpdater::GetParent() const {
    GCPathAnimMotorUpdaterBase value(m_ptr);
    return value;
}
void GCDampedPathAnimMotorUpdater::SetParent(GCPathAnimMotorUpdaterBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCDampedPathAnimMotorUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDampedPathAnimMotorUpdater>("CDampedPathAnimMotorUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AnticipationTime", &GCDampedPathAnimMotorUpdater::GetAnticipationTime, &GCDampedPathAnimMotorUpdater::SetAnticipationTime)
        .addProperty("MinSpeedScale", &GCDampedPathAnimMotorUpdater::GetMinSpeedScale, &GCDampedPathAnimMotorUpdater::SetMinSpeedScale)
        .addProperty("AnticipationPosParam", &GCDampedPathAnimMotorUpdater::GetAnticipationPosParam, &GCDampedPathAnimMotorUpdater::SetAnticipationPosParam)
        .addProperty("AnticipationHeadingParam", &GCDampedPathAnimMotorUpdater::GetAnticipationHeadingParam, &GCDampedPathAnimMotorUpdater::SetAnticipationHeadingParam)
        .addProperty("SpringConstant", &GCDampedPathAnimMotorUpdater::GetSpringConstant, &GCDampedPathAnimMotorUpdater::SetSpringConstant)
        .addProperty("MinSpringTension", &GCDampedPathAnimMotorUpdater::GetMinSpringTension, &GCDampedPathAnimMotorUpdater::SetMinSpringTension)
        .addProperty("MaxSpringTension", &GCDampedPathAnimMotorUpdater::GetMaxSpringTension, &GCDampedPathAnimMotorUpdater::SetMaxSpringTension)
        .addProperty("Parent", &GCDampedPathAnimMotorUpdater::GetParent, &GCDampedPathAnimMotorUpdater::SetParent)
        .addFunction("ToPtr", &GCDampedPathAnimMotorUpdater::ToPtr)
        .addFunction("IsValid", &GCDampedPathAnimMotorUpdater::IsValid)
        .endClass();
}