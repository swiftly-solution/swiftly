#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSolveIKChainUpdateNode::GCSolveIKChainUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSolveIKChainUpdateNode::GCSolveIKChainUpdateNode(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCSolveIKTargetHandle_t> GCSolveIKChainUpdateNode::GetTargetHandles() const {
    CUtlVector<GCSolveIKTargetHandle_t>* vec = GetSchemaValue<CUtlVector<GCSolveIKTargetHandle_t>*>(m_ptr, "CSolveIKChainUpdateNode", "m_targetHandles"); std::vector<GCSolveIKTargetHandle_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSolveIKChainUpdateNode::SetTargetHandles(std::vector<GCSolveIKTargetHandle_t> value) {
    SetSchemaValueCUtlVector<GCSolveIKTargetHandle_t>(m_ptr, "CSolveIKChainUpdateNode", "m_targetHandles", false, value);
}
GSolveIKChainPoseOpFixedSettings_t GCSolveIKChainUpdateNode::GetOpFixedData() const {
    GSolveIKChainPoseOpFixedSettings_t value(GetSchemaPtr(m_ptr, "CSolveIKChainUpdateNode", "m_opFixedData"));
    return value;
}
void GCSolveIKChainUpdateNode::SetOpFixedData(GSolveIKChainPoseOpFixedSettings_t value) {
    SetSchemaValue(m_ptr, "CSolveIKChainUpdateNode", "m_opFixedData", false, value);
}
std::string GCSolveIKChainUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSolveIKChainUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCSolveIKChainUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCSolveIKChainUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSolveIKChainUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSolveIKChainUpdateNode>("CSolveIKChainUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TargetHandles", &GCSolveIKChainUpdateNode::GetTargetHandles, &GCSolveIKChainUpdateNode::SetTargetHandles)
        .addProperty("OpFixedData", &GCSolveIKChainUpdateNode::GetOpFixedData, &GCSolveIKChainUpdateNode::SetOpFixedData)
        .addProperty("Parent", &GCSolveIKChainUpdateNode::GetParent, &GCSolveIKChainUpdateNode::SetParent)
        .addFunction("ToPtr", &GCSolveIKChainUpdateNode::ToPtr)
        .addFunction("IsValid", &GCSolveIKChainUpdateNode::IsValid)
        .endClass();
}