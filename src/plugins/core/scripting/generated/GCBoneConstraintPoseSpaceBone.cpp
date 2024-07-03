#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBoneConstraintPoseSpaceBone::GCBoneConstraintPoseSpaceBone(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBoneConstraintPoseSpaceBone::GCBoneConstraintPoseSpaceBone(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCBoneConstraintPoseSpaceBone> GCBoneConstraintPoseSpaceBone::GetInputList() const {
    CUtlVector<GCBoneConstraintPoseSpaceBone>* vec = GetSchemaValue<CUtlVector<GCBoneConstraintPoseSpaceBone>*>(m_ptr, "CBoneConstraintPoseSpaceBone", "m_inputList"); std::vector<GCBoneConstraintPoseSpaceBone> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBoneConstraintPoseSpaceBone::SetInputList(std::vector<GCBoneConstraintPoseSpaceBone> value) {
    SetSchemaValueCUtlVector<GCBoneConstraintPoseSpaceBone>(m_ptr, "CBoneConstraintPoseSpaceBone", "m_inputList", false, value);
}
std::string GCBoneConstraintPoseSpaceBone::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBoneConstraintPoseSpaceBone::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseConstraint GCBoneConstraintPoseSpaceBone::GetParent() const {
    GCBaseConstraint value(m_ptr);
    return value;
}
void GCBoneConstraintPoseSpaceBone::SetParent(GCBaseConstraint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBoneConstraintPoseSpaceBone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBoneConstraintPoseSpaceBone>("CBoneConstraintPoseSpaceBone")
        .addConstructor<void (*)(std::string)>()
        .addProperty("InputList", &GCBoneConstraintPoseSpaceBone::GetInputList, &GCBoneConstraintPoseSpaceBone::SetInputList)
        .addProperty("Parent", &GCBoneConstraintPoseSpaceBone::GetParent, &GCBoneConstraintPoseSpaceBone::SetParent)
        .addFunction("ToPtr", &GCBoneConstraintPoseSpaceBone::ToPtr)
        .addFunction("IsValid", &GCBoneConstraintPoseSpaceBone::IsValid)
        .endClass();
}