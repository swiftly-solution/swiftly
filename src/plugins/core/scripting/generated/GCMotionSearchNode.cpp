#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMotionSearchNode::GCMotionSearchNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMotionSearchNode::GCMotionSearchNode(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCMotionSearchNode*> GCMotionSearchNode::GetChildren() const {
    CUtlVector<GCMotionSearchNode*>* vec = GetSchemaValue<CUtlVector<GCMotionSearchNode*>*>(m_ptr, "CMotionSearchNode", "m_children"); std::vector<GCMotionSearchNode*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCMotionSearchNode::SetChildren(std::vector<GCMotionSearchNode*> value) {
    SetSchemaValueCUtlVector<GCMotionSearchNode*>(m_ptr, "CMotionSearchNode", "m_children", false, value);
}
GCVectorQuantizer GCMotionSearchNode::GetQuantizer() const {
    GCVectorQuantizer value(GetSchemaPtr(m_ptr, "CMotionSearchNode", "m_quantizer"));
    return value;
}
void GCMotionSearchNode::SetQuantizer(GCVectorQuantizer value) {
    SetSchemaValue(m_ptr, "CMotionSearchNode", "m_quantizer", false, value);
}
std::vector<int32> GCMotionSearchNode::GetSelectableSamples() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CMotionSearchNode", "m_selectableSamples"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCMotionSearchNode::SetSelectableSamples(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "CMotionSearchNode", "m_selectableSamples", false, value);
}
std::string GCMotionSearchNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMotionSearchNode::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCMotionSearchNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionSearchNode>("CMotionSearchNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Children", &GCMotionSearchNode::GetChildren, &GCMotionSearchNode::SetChildren)
        .addProperty("Quantizer", &GCMotionSearchNode::GetQuantizer, &GCMotionSearchNode::SetQuantizer)
        .addProperty("SelectableSamples", &GCMotionSearchNode::GetSelectableSamples, &GCMotionSearchNode::SetSelectableSamples)
        .addFunction("ToPtr", &GCMotionSearchNode::ToPtr)
        .addFunction("IsValid", &GCMotionSearchNode::IsValid)
        .endClass();
}