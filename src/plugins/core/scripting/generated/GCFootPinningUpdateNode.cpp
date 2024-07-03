#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFootPinningUpdateNode::GCFootPinningUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFootPinningUpdateNode::GCFootPinningUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GFootPinningPoseOpFixedData_t GCFootPinningUpdateNode::GetPoseOpFixedData() const {
    GFootPinningPoseOpFixedData_t value(GetSchemaPtr(m_ptr, "CFootPinningUpdateNode", "m_poseOpFixedData"));
    return value;
}
void GCFootPinningUpdateNode::SetPoseOpFixedData(GFootPinningPoseOpFixedData_t value) {
    SetSchemaValue(m_ptr, "CFootPinningUpdateNode", "m_poseOpFixedData", false, value);
}
uint64_t GCFootPinningUpdateNode::GetTimingSource() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CFootPinningUpdateNode", "m_eTimingSource");
}
void GCFootPinningUpdateNode::SetTimingSource(uint64_t value) {
    SetSchemaValue(m_ptr, "CFootPinningUpdateNode", "m_eTimingSource", false, value);
}
std::vector<GCAnimParamHandle> GCFootPinningUpdateNode::GetParams() const {
    CUtlVector<GCAnimParamHandle>* vec = GetSchemaValue<CUtlVector<GCAnimParamHandle>*>(m_ptr, "CFootPinningUpdateNode", "m_params"); std::vector<GCAnimParamHandle> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFootPinningUpdateNode::SetParams(std::vector<GCAnimParamHandle> value) {
    SetSchemaValueCUtlVector<GCAnimParamHandle>(m_ptr, "CFootPinningUpdateNode", "m_params", false, value);
}
bool GCFootPinningUpdateNode::GetResetChild() const {
    return GetSchemaValue<bool>(m_ptr, "CFootPinningUpdateNode", "m_bResetChild");
}
void GCFootPinningUpdateNode::SetResetChild(bool value) {
    SetSchemaValue(m_ptr, "CFootPinningUpdateNode", "m_bResetChild", false, value);
}
std::string GCFootPinningUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFootPinningUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCFootPinningUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCFootPinningUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFootPinningUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootPinningUpdateNode>("CFootPinningUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PoseOpFixedData", &GCFootPinningUpdateNode::GetPoseOpFixedData, &GCFootPinningUpdateNode::SetPoseOpFixedData)
        .addProperty("TimingSource", &GCFootPinningUpdateNode::GetTimingSource, &GCFootPinningUpdateNode::SetTimingSource)
        .addProperty("Params", &GCFootPinningUpdateNode::GetParams, &GCFootPinningUpdateNode::SetParams)
        .addProperty("ResetChild", &GCFootPinningUpdateNode::GetResetChild, &GCFootPinningUpdateNode::SetResetChild)
        .addProperty("Parent", &GCFootPinningUpdateNode::GetParent, &GCFootPinningUpdateNode::SetParent)
        .addFunction("ToPtr", &GCFootPinningUpdateNode::ToPtr)
        .addFunction("IsValid", &GCFootPinningUpdateNode::IsValid)
        .endClass();
}