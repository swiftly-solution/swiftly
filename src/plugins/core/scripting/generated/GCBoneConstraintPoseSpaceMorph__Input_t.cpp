#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBoneConstraintPoseSpaceMorph__Input_t::GCBoneConstraintPoseSpaceMorph__Input_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBoneConstraintPoseSpaceMorph__Input_t::GCBoneConstraintPoseSpaceMorph__Input_t(void *ptr) {
    m_ptr = ptr;
}
Vector GCBoneConstraintPoseSpaceMorph__Input_t::GetInputValue() const {
    return GetSchemaValue<Vector>(m_ptr, "CBoneConstraintPoseSpaceMorph__Input_t", "m_inputValue");
}
void GCBoneConstraintPoseSpaceMorph__Input_t::SetInputValue(Vector value) {
    SetSchemaValue(m_ptr, "CBoneConstraintPoseSpaceMorph__Input_t", "m_inputValue", true, value);
}
std::vector<float32> GCBoneConstraintPoseSpaceMorph__Input_t::GetOutputWeightList() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CBoneConstraintPoseSpaceMorph__Input_t", "m_outputWeightList"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBoneConstraintPoseSpaceMorph__Input_t::SetOutputWeightList(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CBoneConstraintPoseSpaceMorph__Input_t", "m_outputWeightList", true, value);
}
std::string GCBoneConstraintPoseSpaceMorph__Input_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBoneConstraintPoseSpaceMorph__Input_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCBoneConstraintPoseSpaceMorph__Input_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBoneConstraintPoseSpaceMorph__Input_t>("CBoneConstraintPoseSpaceMorph__Input_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("InputValue", &GCBoneConstraintPoseSpaceMorph__Input_t::GetInputValue, &GCBoneConstraintPoseSpaceMorph__Input_t::SetInputValue)
        .addProperty("OutputWeightList", &GCBoneConstraintPoseSpaceMorph__Input_t::GetOutputWeightList, &GCBoneConstraintPoseSpaceMorph__Input_t::SetOutputWeightList)
        .addFunction("ToPtr", &GCBoneConstraintPoseSpaceMorph__Input_t::ToPtr)
        .addFunction("IsValid", &GCBoneConstraintPoseSpaceMorph__Input_t::IsValid)
        .endClass();
}