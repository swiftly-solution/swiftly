#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCStateMachineUpdateNode::GCStateMachineUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCStateMachineUpdateNode::GCStateMachineUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GCAnimStateMachineUpdater GCStateMachineUpdateNode::GetStateMachine() const {
    GCAnimStateMachineUpdater value(GetSchemaPtr(m_ptr, "CStateMachineUpdateNode", "m_stateMachine"));
    return value;
}
void GCStateMachineUpdateNode::SetStateMachine(GCAnimStateMachineUpdater value) {
    SetSchemaValue(m_ptr, "CStateMachineUpdateNode", "m_stateMachine", false, value);
}
std::vector<GCStateNodeStateData> GCStateMachineUpdateNode::GetStateData() const {
    CUtlVector<GCStateNodeStateData>* vec = GetSchemaValue<CUtlVector<GCStateNodeStateData>*>(m_ptr, "CStateMachineUpdateNode", "m_stateData"); std::vector<GCStateNodeStateData> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCStateMachineUpdateNode::SetStateData(std::vector<GCStateNodeStateData> value) {
    SetSchemaValueCUtlVector<GCStateNodeStateData>(m_ptr, "CStateMachineUpdateNode", "m_stateData", false, value);
}
std::vector<GCStateNodeTransitionData> GCStateMachineUpdateNode::GetTransitionData() const {
    CUtlVector<GCStateNodeTransitionData>* vec = GetSchemaValue<CUtlVector<GCStateNodeTransitionData>*>(m_ptr, "CStateMachineUpdateNode", "m_transitionData"); std::vector<GCStateNodeTransitionData> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCStateMachineUpdateNode::SetTransitionData(std::vector<GCStateNodeTransitionData> value) {
    SetSchemaValueCUtlVector<GCStateNodeTransitionData>(m_ptr, "CStateMachineUpdateNode", "m_transitionData", false, value);
}
bool GCStateMachineUpdateNode::GetBlockWaningTags() const {
    return GetSchemaValue<bool>(m_ptr, "CStateMachineUpdateNode", "m_bBlockWaningTags");
}
void GCStateMachineUpdateNode::SetBlockWaningTags(bool value) {
    SetSchemaValue(m_ptr, "CStateMachineUpdateNode", "m_bBlockWaningTags", false, value);
}
bool GCStateMachineUpdateNode::GetLockStateWhenWaning() const {
    return GetSchemaValue<bool>(m_ptr, "CStateMachineUpdateNode", "m_bLockStateWhenWaning");
}
void GCStateMachineUpdateNode::SetLockStateWhenWaning(bool value) {
    SetSchemaValue(m_ptr, "CStateMachineUpdateNode", "m_bLockStateWhenWaning", false, value);
}
std::string GCStateMachineUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCStateMachineUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimUpdateNodeBase GCStateMachineUpdateNode::GetParent() const {
    GCAnimUpdateNodeBase value(m_ptr);
    return value;
}
void GCStateMachineUpdateNode::SetParent(GCAnimUpdateNodeBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCStateMachineUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStateMachineUpdateNode>("CStateMachineUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StateMachine", &GCStateMachineUpdateNode::GetStateMachine, &GCStateMachineUpdateNode::SetStateMachine)
        .addProperty("StateData", &GCStateMachineUpdateNode::GetStateData, &GCStateMachineUpdateNode::SetStateData)
        .addProperty("TransitionData", &GCStateMachineUpdateNode::GetTransitionData, &GCStateMachineUpdateNode::SetTransitionData)
        .addProperty("BlockWaningTags", &GCStateMachineUpdateNode::GetBlockWaningTags, &GCStateMachineUpdateNode::SetBlockWaningTags)
        .addProperty("LockStateWhenWaning", &GCStateMachineUpdateNode::GetLockStateWhenWaning, &GCStateMachineUpdateNode::SetLockStateWhenWaning)
        .addProperty("Parent", &GCStateMachineUpdateNode::GetParent, &GCStateMachineUpdateNode::SetParent)
        .addFunction("ToPtr", &GCStateMachineUpdateNode::ToPtr)
        .addFunction("IsValid", &GCStateMachineUpdateNode::IsValid)
        .endClass();
}