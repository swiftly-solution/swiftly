#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCStanceOverrideUpdateNode::GCStanceOverrideUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCStanceOverrideUpdateNode::GCStanceOverrideUpdateNode(void *ptr) {
    m_ptr = ptr;
}
std::vector<GStanceInfo_t> GCStanceOverrideUpdateNode::GetFootStanceInfo() const {
    CUtlVector<GStanceInfo_t>* vec = GetSchemaValue<CUtlVector<GStanceInfo_t>*>(m_ptr, "CStanceOverrideUpdateNode", "m_footStanceInfo"); std::vector<GStanceInfo_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCStanceOverrideUpdateNode::SetFootStanceInfo(std::vector<GStanceInfo_t> value) {
    SetSchemaValueCUtlVector<GStanceInfo_t>(m_ptr, "CStanceOverrideUpdateNode", "m_footStanceInfo", false, value);
}
GCAnimUpdateNodeRef GCStanceOverrideUpdateNode::GetStanceSourceNode() const {
    GCAnimUpdateNodeRef value(GetSchemaPtr(m_ptr, "CStanceOverrideUpdateNode", "m_pStanceSourceNode"));
    return value;
}
void GCStanceOverrideUpdateNode::SetStanceSourceNode(GCAnimUpdateNodeRef value) {
    SetSchemaValue(m_ptr, "CStanceOverrideUpdateNode", "m_pStanceSourceNode", false, value);
}
GCAnimParamHandle GCStanceOverrideUpdateNode::GetParameter() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CStanceOverrideUpdateNode", "m_hParameter"));
    return value;
}
void GCStanceOverrideUpdateNode::SetParameter(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CStanceOverrideUpdateNode", "m_hParameter", false, value);
}
uint64_t GCStanceOverrideUpdateNode::GetMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CStanceOverrideUpdateNode", "m_eMode");
}
void GCStanceOverrideUpdateNode::SetMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CStanceOverrideUpdateNode", "m_eMode", false, value);
}
std::string GCStanceOverrideUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCStanceOverrideUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCStanceOverrideUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCStanceOverrideUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCStanceOverrideUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStanceOverrideUpdateNode>("CStanceOverrideUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FootStanceInfo", &GCStanceOverrideUpdateNode::GetFootStanceInfo, &GCStanceOverrideUpdateNode::SetFootStanceInfo)
        .addProperty("StanceSourceNode", &GCStanceOverrideUpdateNode::GetStanceSourceNode, &GCStanceOverrideUpdateNode::SetStanceSourceNode)
        .addProperty("Parameter", &GCStanceOverrideUpdateNode::GetParameter, &GCStanceOverrideUpdateNode::SetParameter)
        .addProperty("Mode", &GCStanceOverrideUpdateNode::GetMode, &GCStanceOverrideUpdateNode::SetMode)
        .addProperty("Parent", &GCStanceOverrideUpdateNode::GetParent, &GCStanceOverrideUpdateNode::SetParent)
        .addFunction("ToPtr", &GCStanceOverrideUpdateNode::ToPtr)
        .addFunction("IsValid", &GCStanceOverrideUpdateNode::IsValid)
        .endClass();
}