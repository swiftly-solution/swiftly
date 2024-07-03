#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFootStepTriggerUpdateNode::GCFootStepTriggerUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFootStepTriggerUpdateNode::GCFootStepTriggerUpdateNode(void *ptr) {
    m_ptr = ptr;
}
std::vector<GFootStepTrigger> GCFootStepTriggerUpdateNode::GetTriggers() const {
    CUtlVector<GFootStepTrigger>* vec = GetSchemaValue<CUtlVector<GFootStepTrigger>*>(m_ptr, "CFootStepTriggerUpdateNode", "m_triggers"); std::vector<GFootStepTrigger> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFootStepTriggerUpdateNode::SetTriggers(std::vector<GFootStepTrigger> value) {
    SetSchemaValueCUtlVector<GFootStepTrigger>(m_ptr, "CFootStepTriggerUpdateNode", "m_triggers", false, value);
}
float GCFootStepTriggerUpdateNode::GetTolerance() const {
    return GetSchemaValue<float>(m_ptr, "CFootStepTriggerUpdateNode", "m_flTolerance");
}
void GCFootStepTriggerUpdateNode::SetTolerance(float value) {
    SetSchemaValue(m_ptr, "CFootStepTriggerUpdateNode", "m_flTolerance", false, value);
}
std::string GCFootStepTriggerUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFootStepTriggerUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCFootStepTriggerUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCFootStepTriggerUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFootStepTriggerUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootStepTriggerUpdateNode>("CFootStepTriggerUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Triggers", &GCFootStepTriggerUpdateNode::GetTriggers, &GCFootStepTriggerUpdateNode::SetTriggers)
        .addProperty("Tolerance", &GCFootStepTriggerUpdateNode::GetTolerance, &GCFootStepTriggerUpdateNode::SetTolerance)
        .addProperty("Parent", &GCFootStepTriggerUpdateNode::GetParent, &GCFootStepTriggerUpdateNode::SetParent)
        .addFunction("ToPtr", &GCFootStepTriggerUpdateNode::ToPtr)
        .addFunction("IsValid", &GCFootStepTriggerUpdateNode::IsValid)
        .endClass();
}