#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSelectorUpdateNode::GCSelectorUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSelectorUpdateNode::GCSelectorUpdateNode(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCAnimUpdateNodeRef> GCSelectorUpdateNode::GetChildren() const {
    CUtlVector<GCAnimUpdateNodeRef>* vec = GetSchemaValue<CUtlVector<GCAnimUpdateNodeRef>*>(m_ptr, "CSelectorUpdateNode", "m_children"); std::vector<GCAnimUpdateNodeRef> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSelectorUpdateNode::SetChildren(std::vector<GCAnimUpdateNodeRef> value) {
    SetSchemaValueCUtlVector<GCAnimUpdateNodeRef>(m_ptr, "CSelectorUpdateNode", "m_children", false, value);
}
std::vector<int8> GCSelectorUpdateNode::GetTags() const {
    CUtlVector<int8>* vec = GetSchemaValue<CUtlVector<int8>*>(m_ptr, "CSelectorUpdateNode", "m_tags"); std::vector<int8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSelectorUpdateNode::SetTags(std::vector<int8> value) {
    SetSchemaValueCUtlVector<int8>(m_ptr, "CSelectorUpdateNode", "m_tags", false, value);
}
GCBlendCurve GCSelectorUpdateNode::GetBlendCurve() const {
    GCBlendCurve value(GetSchemaPtr(m_ptr, "CSelectorUpdateNode", "m_blendCurve"));
    return value;
}
void GCSelectorUpdateNode::SetBlendCurve(GCBlendCurve value) {
    SetSchemaValue(m_ptr, "CSelectorUpdateNode", "m_blendCurve", false, value);
}
GCAnimParamHandle GCSelectorUpdateNode::GetParameter() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CSelectorUpdateNode", "m_hParameter"));
    return value;
}
void GCSelectorUpdateNode::SetParameter(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CSelectorUpdateNode", "m_hParameter", false, value);
}
int32_t GCSelectorUpdateNode::GetTagIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSelectorUpdateNode", "m_nTagIndex");
}
void GCSelectorUpdateNode::SetTagIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CSelectorUpdateNode", "m_nTagIndex", false, value);
}
uint64_t GCSelectorUpdateNode::GetTagBehavior() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CSelectorUpdateNode", "m_eTagBehavior");
}
void GCSelectorUpdateNode::SetTagBehavior(uint64_t value) {
    SetSchemaValue(m_ptr, "CSelectorUpdateNode", "m_eTagBehavior", false, value);
}
bool GCSelectorUpdateNode::GetResetOnChange() const {
    return GetSchemaValue<bool>(m_ptr, "CSelectorUpdateNode", "m_bResetOnChange");
}
void GCSelectorUpdateNode::SetResetOnChange(bool value) {
    SetSchemaValue(m_ptr, "CSelectorUpdateNode", "m_bResetOnChange", false, value);
}
bool GCSelectorUpdateNode::GetLockWhenWaning() const {
    return GetSchemaValue<bool>(m_ptr, "CSelectorUpdateNode", "m_bLockWhenWaning");
}
void GCSelectorUpdateNode::SetLockWhenWaning(bool value) {
    SetSchemaValue(m_ptr, "CSelectorUpdateNode", "m_bLockWhenWaning", false, value);
}
bool GCSelectorUpdateNode::GetSyncCyclesOnChange() const {
    return GetSchemaValue<bool>(m_ptr, "CSelectorUpdateNode", "m_bSyncCyclesOnChange");
}
void GCSelectorUpdateNode::SetSyncCyclesOnChange(bool value) {
    SetSchemaValue(m_ptr, "CSelectorUpdateNode", "m_bSyncCyclesOnChange", false, value);
}
std::string GCSelectorUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSelectorUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimUpdateNodeBase GCSelectorUpdateNode::GetParent() const {
    GCAnimUpdateNodeBase value(m_ptr);
    return value;
}
void GCSelectorUpdateNode::SetParent(GCAnimUpdateNodeBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSelectorUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSelectorUpdateNode>("CSelectorUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Children", &GCSelectorUpdateNode::GetChildren, &GCSelectorUpdateNode::SetChildren)
        .addProperty("Tags", &GCSelectorUpdateNode::GetTags, &GCSelectorUpdateNode::SetTags)
        .addProperty("BlendCurve", &GCSelectorUpdateNode::GetBlendCurve, &GCSelectorUpdateNode::SetBlendCurve)
        .addProperty("Parameter", &GCSelectorUpdateNode::GetParameter, &GCSelectorUpdateNode::SetParameter)
        .addProperty("TagIndex", &GCSelectorUpdateNode::GetTagIndex, &GCSelectorUpdateNode::SetTagIndex)
        .addProperty("TagBehavior", &GCSelectorUpdateNode::GetTagBehavior, &GCSelectorUpdateNode::SetTagBehavior)
        .addProperty("ResetOnChange", &GCSelectorUpdateNode::GetResetOnChange, &GCSelectorUpdateNode::SetResetOnChange)
        .addProperty("LockWhenWaning", &GCSelectorUpdateNode::GetLockWhenWaning, &GCSelectorUpdateNode::SetLockWhenWaning)
        .addProperty("SyncCyclesOnChange", &GCSelectorUpdateNode::GetSyncCyclesOnChange, &GCSelectorUpdateNode::SetSyncCyclesOnChange)
        .addProperty("Parent", &GCSelectorUpdateNode::GetParent, &GCSelectorUpdateNode::SetParent)
        .addFunction("ToPtr", &GCSelectorUpdateNode::ToPtr)
        .addFunction("IsValid", &GCSelectorUpdateNode::IsValid)
        .endClass();
}