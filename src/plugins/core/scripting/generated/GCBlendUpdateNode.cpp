#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBlendUpdateNode::GCBlendUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBlendUpdateNode::GCBlendUpdateNode(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCAnimUpdateNodeRef> GCBlendUpdateNode::GetChildren() const {
    CUtlVector<GCAnimUpdateNodeRef>* vec = GetSchemaValue<CUtlVector<GCAnimUpdateNodeRef>*>(m_ptr, "CBlendUpdateNode", "m_children"); std::vector<GCAnimUpdateNodeRef> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBlendUpdateNode::SetChildren(std::vector<GCAnimUpdateNodeRef> value) {
    SetSchemaValueCUtlVector<GCAnimUpdateNodeRef>(m_ptr, "CBlendUpdateNode", "m_children", false, value);
}
std::vector<uint8> GCBlendUpdateNode::GetSortedOrder() const {
    CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "CBlendUpdateNode", "m_sortedOrder"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBlendUpdateNode::SetSortedOrder(std::vector<uint8> value) {
    SetSchemaValueCUtlVector<uint8>(m_ptr, "CBlendUpdateNode", "m_sortedOrder", false, value);
}
std::vector<float32> GCBlendUpdateNode::GetTargetValues() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CBlendUpdateNode", "m_targetValues"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBlendUpdateNode::SetTargetValues(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CBlendUpdateNode", "m_targetValues", false, value);
}
uint64_t GCBlendUpdateNode::GetBlendValueSource() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBlendUpdateNode", "m_blendValueSource");
}
void GCBlendUpdateNode::SetBlendValueSource(uint64_t value) {
    SetSchemaValue(m_ptr, "CBlendUpdateNode", "m_blendValueSource", false, value);
}
GCAnimParamHandle GCBlendUpdateNode::GetParamIndex() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CBlendUpdateNode", "m_paramIndex"));
    return value;
}
void GCBlendUpdateNode::SetParamIndex(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CBlendUpdateNode", "m_paramIndex", false, value);
}
GCAnimInputDamping GCBlendUpdateNode::GetDamping() const {
    GCAnimInputDamping value(GetSchemaPtr(m_ptr, "CBlendUpdateNode", "m_damping"));
    return value;
}
void GCBlendUpdateNode::SetDamping(GCAnimInputDamping value) {
    SetSchemaValue(m_ptr, "CBlendUpdateNode", "m_damping", false, value);
}
uint64_t GCBlendUpdateNode::GetBlendKeyType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBlendUpdateNode", "m_blendKeyType");
}
void GCBlendUpdateNode::SetBlendKeyType(uint64_t value) {
    SetSchemaValue(m_ptr, "CBlendUpdateNode", "m_blendKeyType", false, value);
}
bool GCBlendUpdateNode::GetLockBlendOnReset() const {
    return GetSchemaValue<bool>(m_ptr, "CBlendUpdateNode", "m_bLockBlendOnReset");
}
void GCBlendUpdateNode::SetLockBlendOnReset(bool value) {
    SetSchemaValue(m_ptr, "CBlendUpdateNode", "m_bLockBlendOnReset", false, value);
}
bool GCBlendUpdateNode::GetSyncCycles() const {
    return GetSchemaValue<bool>(m_ptr, "CBlendUpdateNode", "m_bSyncCycles");
}
void GCBlendUpdateNode::SetSyncCycles(bool value) {
    SetSchemaValue(m_ptr, "CBlendUpdateNode", "m_bSyncCycles", false, value);
}
bool GCBlendUpdateNode::GetLoop() const {
    return GetSchemaValue<bool>(m_ptr, "CBlendUpdateNode", "m_bLoop");
}
void GCBlendUpdateNode::SetLoop(bool value) {
    SetSchemaValue(m_ptr, "CBlendUpdateNode", "m_bLoop", false, value);
}
bool GCBlendUpdateNode::GetLockWhenWaning() const {
    return GetSchemaValue<bool>(m_ptr, "CBlendUpdateNode", "m_bLockWhenWaning");
}
void GCBlendUpdateNode::SetLockWhenWaning(bool value) {
    SetSchemaValue(m_ptr, "CBlendUpdateNode", "m_bLockWhenWaning", false, value);
}
std::string GCBlendUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBlendUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimUpdateNodeBase GCBlendUpdateNode::GetParent() const {
    GCAnimUpdateNodeBase value(m_ptr);
    return value;
}
void GCBlendUpdateNode::SetParent(GCAnimUpdateNodeBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBlendUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBlendUpdateNode>("CBlendUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Children", &GCBlendUpdateNode::GetChildren, &GCBlendUpdateNode::SetChildren)
        .addProperty("SortedOrder", &GCBlendUpdateNode::GetSortedOrder, &GCBlendUpdateNode::SetSortedOrder)
        .addProperty("TargetValues", &GCBlendUpdateNode::GetTargetValues, &GCBlendUpdateNode::SetTargetValues)
        .addProperty("BlendValueSource", &GCBlendUpdateNode::GetBlendValueSource, &GCBlendUpdateNode::SetBlendValueSource)
        .addProperty("ParamIndex", &GCBlendUpdateNode::GetParamIndex, &GCBlendUpdateNode::SetParamIndex)
        .addProperty("Damping", &GCBlendUpdateNode::GetDamping, &GCBlendUpdateNode::SetDamping)
        .addProperty("BlendKeyType", &GCBlendUpdateNode::GetBlendKeyType, &GCBlendUpdateNode::SetBlendKeyType)
        .addProperty("LockBlendOnReset", &GCBlendUpdateNode::GetLockBlendOnReset, &GCBlendUpdateNode::SetLockBlendOnReset)
        .addProperty("SyncCycles", &GCBlendUpdateNode::GetSyncCycles, &GCBlendUpdateNode::SetSyncCycles)
        .addProperty("Loop", &GCBlendUpdateNode::GetLoop, &GCBlendUpdateNode::SetLoop)
        .addProperty("LockWhenWaning", &GCBlendUpdateNode::GetLockWhenWaning, &GCBlendUpdateNode::SetLockWhenWaning)
        .addProperty("Parent", &GCBlendUpdateNode::GetParent, &GCBlendUpdateNode::SetParent)
        .addFunction("ToPtr", &GCBlendUpdateNode::ToPtr)
        .addFunction("IsValid", &GCBlendUpdateNode::IsValid)
        .endClass();
}