#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPlayerInputAnimMotorUpdater::GCPlayerInputAnimMotorUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPlayerInputAnimMotorUpdater::GCPlayerInputAnimMotorUpdater(void *ptr) {
    m_ptr = ptr;
}
std::vector<float32> GCPlayerInputAnimMotorUpdater::GetSampleTimes() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CPlayerInputAnimMotorUpdater", "m_sampleTimes"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCPlayerInputAnimMotorUpdater::SetSampleTimes(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CPlayerInputAnimMotorUpdater", "m_sampleTimes", false, value);
}
float GCPlayerInputAnimMotorUpdater::GetSpringConstant() const {
    return GetSchemaValue<float>(m_ptr, "CPlayerInputAnimMotorUpdater", "m_flSpringConstant");
}
void GCPlayerInputAnimMotorUpdater::SetSpringConstant(float value) {
    SetSchemaValue(m_ptr, "CPlayerInputAnimMotorUpdater", "m_flSpringConstant", false, value);
}
float GCPlayerInputAnimMotorUpdater::GetAnticipationDistance() const {
    return GetSchemaValue<float>(m_ptr, "CPlayerInputAnimMotorUpdater", "m_flAnticipationDistance");
}
void GCPlayerInputAnimMotorUpdater::SetAnticipationDistance(float value) {
    SetSchemaValue(m_ptr, "CPlayerInputAnimMotorUpdater", "m_flAnticipationDistance", false, value);
}
GCAnimParamHandle GCPlayerInputAnimMotorUpdater::GetAnticipationPosParam() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CPlayerInputAnimMotorUpdater", "m_hAnticipationPosParam"));
    return value;
}
void GCPlayerInputAnimMotorUpdater::SetAnticipationPosParam(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CPlayerInputAnimMotorUpdater", "m_hAnticipationPosParam", false, value);
}
GCAnimParamHandle GCPlayerInputAnimMotorUpdater::GetAnticipationHeadingParam() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CPlayerInputAnimMotorUpdater", "m_hAnticipationHeadingParam"));
    return value;
}
void GCPlayerInputAnimMotorUpdater::SetAnticipationHeadingParam(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CPlayerInputAnimMotorUpdater", "m_hAnticipationHeadingParam", false, value);
}
bool GCPlayerInputAnimMotorUpdater::GetUseAcceleration() const {
    return GetSchemaValue<bool>(m_ptr, "CPlayerInputAnimMotorUpdater", "m_bUseAcceleration");
}
void GCPlayerInputAnimMotorUpdater::SetUseAcceleration(bool value) {
    SetSchemaValue(m_ptr, "CPlayerInputAnimMotorUpdater", "m_bUseAcceleration", false, value);
}
std::string GCPlayerInputAnimMotorUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPlayerInputAnimMotorUpdater::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimMotorUpdaterBase GCPlayerInputAnimMotorUpdater::GetParent() const {
    GCAnimMotorUpdaterBase value(m_ptr);
    return value;
}
void GCPlayerInputAnimMotorUpdater::SetParent(GCAnimMotorUpdaterBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPlayerInputAnimMotorUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayerInputAnimMotorUpdater>("CPlayerInputAnimMotorUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SampleTimes", &GCPlayerInputAnimMotorUpdater::GetSampleTimes, &GCPlayerInputAnimMotorUpdater::SetSampleTimes)
        .addProperty("SpringConstant", &GCPlayerInputAnimMotorUpdater::GetSpringConstant, &GCPlayerInputAnimMotorUpdater::SetSpringConstant)
        .addProperty("AnticipationDistance", &GCPlayerInputAnimMotorUpdater::GetAnticipationDistance, &GCPlayerInputAnimMotorUpdater::SetAnticipationDistance)
        .addProperty("AnticipationPosParam", &GCPlayerInputAnimMotorUpdater::GetAnticipationPosParam, &GCPlayerInputAnimMotorUpdater::SetAnticipationPosParam)
        .addProperty("AnticipationHeadingParam", &GCPlayerInputAnimMotorUpdater::GetAnticipationHeadingParam, &GCPlayerInputAnimMotorUpdater::SetAnticipationHeadingParam)
        .addProperty("UseAcceleration", &GCPlayerInputAnimMotorUpdater::GetUseAcceleration, &GCPlayerInputAnimMotorUpdater::SetUseAcceleration)
        .addProperty("Parent", &GCPlayerInputAnimMotorUpdater::GetParent, &GCPlayerInputAnimMotorUpdater::SetParent)
        .addFunction("ToPtr", &GCPlayerInputAnimMotorUpdater::ToPtr)
        .addFunction("IsValid", &GCPlayerInputAnimMotorUpdater::IsValid)
        .endClass();
}