#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLeanMatrixUpdateNode::GCLeanMatrixUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLeanMatrixUpdateNode::GCLeanMatrixUpdateNode(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCPoseHandle> GCLeanMatrixUpdateNode::GetPoses() const {
    GCPoseHandle* outValue = GetSchemaValue<GCPoseHandle*>(m_ptr, "CLeanMatrixUpdateNode", "m_poses"); std::vector<GCPoseHandle> ret; for(int i = 0; i < 9; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCLeanMatrixUpdateNode::SetPoses(std::vector<GCPoseHandle> value) {
    GCPoseHandle* outValue = GetSchemaValue<GCPoseHandle*>(m_ptr, "CLeanMatrixUpdateNode", "m_poses"); for(int i = 0; i < 9; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CLeanMatrixUpdateNode", "m_poses", false, outValue);
}
GCAnimInputDamping GCLeanMatrixUpdateNode::GetDamping() const {
    GCAnimInputDamping value(GetSchemaPtr(m_ptr, "CLeanMatrixUpdateNode", "m_damping"));
    return value;
}
void GCLeanMatrixUpdateNode::SetDamping(GCAnimInputDamping value) {
    SetSchemaValue(m_ptr, "CLeanMatrixUpdateNode", "m_damping", false, value);
}
uint64_t GCLeanMatrixUpdateNode::GetBlendSource() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CLeanMatrixUpdateNode", "m_blendSource");
}
void GCLeanMatrixUpdateNode::SetBlendSource(uint64_t value) {
    SetSchemaValue(m_ptr, "CLeanMatrixUpdateNode", "m_blendSource", false, value);
}
GCAnimParamHandle GCLeanMatrixUpdateNode::GetParamIndex() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CLeanMatrixUpdateNode", "m_paramIndex"));
    return value;
}
void GCLeanMatrixUpdateNode::SetParamIndex(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CLeanMatrixUpdateNode", "m_paramIndex", false, value);
}
Vector GCLeanMatrixUpdateNode::GetVerticalAxis() const {
    return GetSchemaValue<Vector>(m_ptr, "CLeanMatrixUpdateNode", "m_verticalAxis");
}
void GCLeanMatrixUpdateNode::SetVerticalAxis(Vector value) {
    SetSchemaValue(m_ptr, "CLeanMatrixUpdateNode", "m_verticalAxis", false, value);
}
Vector GCLeanMatrixUpdateNode::GetHorizontalAxis() const {
    return GetSchemaValue<Vector>(m_ptr, "CLeanMatrixUpdateNode", "m_horizontalAxis");
}
void GCLeanMatrixUpdateNode::SetHorizontalAxis(Vector value) {
    SetSchemaValue(m_ptr, "CLeanMatrixUpdateNode", "m_horizontalAxis", false, value);
}
float GCLeanMatrixUpdateNode::GetMaxValue() const {
    return GetSchemaValue<float>(m_ptr, "CLeanMatrixUpdateNode", "m_flMaxValue");
}
void GCLeanMatrixUpdateNode::SetMaxValue(float value) {
    SetSchemaValue(m_ptr, "CLeanMatrixUpdateNode", "m_flMaxValue", false, value);
}
int32_t GCLeanMatrixUpdateNode::GetSequenceMaxFrame() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLeanMatrixUpdateNode", "m_nSequenceMaxFrame");
}
void GCLeanMatrixUpdateNode::SetSequenceMaxFrame(int32_t value) {
    SetSchemaValue(m_ptr, "CLeanMatrixUpdateNode", "m_nSequenceMaxFrame", false, value);
}
std::string GCLeanMatrixUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLeanMatrixUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCLeafUpdateNode GCLeanMatrixUpdateNode::GetParent() const {
    GCLeafUpdateNode value(m_ptr);
    return value;
}
void GCLeanMatrixUpdateNode::SetParent(GCLeafUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLeanMatrixUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLeanMatrixUpdateNode>("CLeanMatrixUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Poses", &GCLeanMatrixUpdateNode::GetPoses, &GCLeanMatrixUpdateNode::SetPoses)
        .addProperty("Damping", &GCLeanMatrixUpdateNode::GetDamping, &GCLeanMatrixUpdateNode::SetDamping)
        .addProperty("BlendSource", &GCLeanMatrixUpdateNode::GetBlendSource, &GCLeanMatrixUpdateNode::SetBlendSource)
        .addProperty("ParamIndex", &GCLeanMatrixUpdateNode::GetParamIndex, &GCLeanMatrixUpdateNode::SetParamIndex)
        .addProperty("VerticalAxis", &GCLeanMatrixUpdateNode::GetVerticalAxis, &GCLeanMatrixUpdateNode::SetVerticalAxis)
        .addProperty("HorizontalAxis", &GCLeanMatrixUpdateNode::GetHorizontalAxis, &GCLeanMatrixUpdateNode::SetHorizontalAxis)
        .addProperty("MaxValue", &GCLeanMatrixUpdateNode::GetMaxValue, &GCLeanMatrixUpdateNode::SetMaxValue)
        .addProperty("SequenceMaxFrame", &GCLeanMatrixUpdateNode::GetSequenceMaxFrame, &GCLeanMatrixUpdateNode::SetSequenceMaxFrame)
        .addProperty("Parent", &GCLeanMatrixUpdateNode::GetParent, &GCLeanMatrixUpdateNode::SetParent)
        .addFunction("ToPtr", &GCLeanMatrixUpdateNode::ToPtr)
        .addFunction("IsValid", &GCLeanMatrixUpdateNode::IsValid)
        .endClass();
}