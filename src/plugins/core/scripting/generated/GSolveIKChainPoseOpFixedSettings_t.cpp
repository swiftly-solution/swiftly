#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSolveIKChainPoseOpFixedSettings_t::GSolveIKChainPoseOpFixedSettings_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSolveIKChainPoseOpFixedSettings_t::GSolveIKChainPoseOpFixedSettings_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<GChainToSolveData_t> GSolveIKChainPoseOpFixedSettings_t::GetChainsToSolveData() const {
    CUtlVector<GChainToSolveData_t>* vec = GetSchemaValue<CUtlVector<GChainToSolveData_t>*>(m_ptr, "SolveIKChainPoseOpFixedSettings_t", "m_ChainsToSolveData"); std::vector<GChainToSolveData_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GSolveIKChainPoseOpFixedSettings_t::SetChainsToSolveData(std::vector<GChainToSolveData_t> value) {
    SetSchemaValueCUtlVector<GChainToSolveData_t>(m_ptr, "SolveIKChainPoseOpFixedSettings_t", "m_ChainsToSolveData", true, value);
}
bool GSolveIKChainPoseOpFixedSettings_t::GetMatchTargetOrientation() const {
    return GetSchemaValue<bool>(m_ptr, "SolveIKChainPoseOpFixedSettings_t", "m_bMatchTargetOrientation");
}
void GSolveIKChainPoseOpFixedSettings_t::SetMatchTargetOrientation(bool value) {
    SetSchemaValue(m_ptr, "SolveIKChainPoseOpFixedSettings_t", "m_bMatchTargetOrientation", true, value);
}
std::string GSolveIKChainPoseOpFixedSettings_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSolveIKChainPoseOpFixedSettings_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSolveIKChainPoseOpFixedSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSolveIKChainPoseOpFixedSettings_t>("SolveIKChainPoseOpFixedSettings_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ChainsToSolveData", &GSolveIKChainPoseOpFixedSettings_t::GetChainsToSolveData, &GSolveIKChainPoseOpFixedSettings_t::SetChainsToSolveData)
        .addProperty("MatchTargetOrientation", &GSolveIKChainPoseOpFixedSettings_t::GetMatchTargetOrientation, &GSolveIKChainPoseOpFixedSettings_t::SetMatchTargetOrientation)
        .addFunction("ToPtr", &GSolveIKChainPoseOpFixedSettings_t::ToPtr)
        .addFunction("IsValid", &GSolveIKChainPoseOpFixedSettings_t::IsValid)
        .endClass();
}