#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBlend2DUpdateNode::GCBlend2DUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBlend2DUpdateNode::GCBlend2DUpdateNode(void *ptr) {
    m_ptr = ptr;
}
std::vector<GBlendItem_t> GCBlend2DUpdateNode::GetItems() const {
    CUtlVector<GBlendItem_t>* vec = GetSchemaValue<CUtlVector<GBlendItem_t>*>(m_ptr, "CBlend2DUpdateNode", "m_items"); std::vector<GBlendItem_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBlend2DUpdateNode::SetItems(std::vector<GBlendItem_t> value) {
    SetSchemaValueCUtlVector<GBlendItem_t>(m_ptr, "CBlend2DUpdateNode", "m_items", false, value);
}
std::vector<GTagSpan_t> GCBlend2DUpdateNode::GetTags() const {
    CUtlVector<GTagSpan_t>* vec = GetSchemaValue<CUtlVector<GTagSpan_t>*>(m_ptr, "CBlend2DUpdateNode", "m_tags"); std::vector<GTagSpan_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBlend2DUpdateNode::SetTags(std::vector<GTagSpan_t> value) {
    SetSchemaValueCUtlVector<GTagSpan_t>(m_ptr, "CBlend2DUpdateNode", "m_tags", false, value);
}
GCParamSpanUpdater GCBlend2DUpdateNode::GetParamSpans() const {
    GCParamSpanUpdater value(GetSchemaPtr(m_ptr, "CBlend2DUpdateNode", "m_paramSpans"));
    return value;
}
void GCBlend2DUpdateNode::SetParamSpans(GCParamSpanUpdater value) {
    SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_paramSpans", false, value);
}
std::vector<int32> GCBlend2DUpdateNode::GetNodeItemIndices() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CBlend2DUpdateNode", "m_nodeItemIndices"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBlend2DUpdateNode::SetNodeItemIndices(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "CBlend2DUpdateNode", "m_nodeItemIndices", false, value);
}
GCAnimInputDamping GCBlend2DUpdateNode::GetDamping() const {
    GCAnimInputDamping value(GetSchemaPtr(m_ptr, "CBlend2DUpdateNode", "m_damping"));
    return value;
}
void GCBlend2DUpdateNode::SetDamping(GCAnimInputDamping value) {
    SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_damping", false, value);
}
uint64_t GCBlend2DUpdateNode::GetBlendSourceX() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBlend2DUpdateNode", "m_blendSourceX");
}
void GCBlend2DUpdateNode::SetBlendSourceX(uint64_t value) {
    SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_blendSourceX", false, value);
}
GCAnimParamHandle GCBlend2DUpdateNode::GetParamX() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CBlend2DUpdateNode", "m_paramX"));
    return value;
}
void GCBlend2DUpdateNode::SetParamX(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_paramX", false, value);
}
uint64_t GCBlend2DUpdateNode::GetBlendSourceY() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBlend2DUpdateNode", "m_blendSourceY");
}
void GCBlend2DUpdateNode::SetBlendSourceY(uint64_t value) {
    SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_blendSourceY", false, value);
}
GCAnimParamHandle GCBlend2DUpdateNode::GetParamY() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CBlend2DUpdateNode", "m_paramY"));
    return value;
}
void GCBlend2DUpdateNode::SetParamY(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_paramY", false, value);
}
uint64_t GCBlend2DUpdateNode::GetBlendMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBlend2DUpdateNode", "m_eBlendMode");
}
void GCBlend2DUpdateNode::SetBlendMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_eBlendMode", false, value);
}
float GCBlend2DUpdateNode::GetPlaybackSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CBlend2DUpdateNode", "m_playbackSpeed");
}
void GCBlend2DUpdateNode::SetPlaybackSpeed(float value) {
    SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_playbackSpeed", false, value);
}
bool GCBlend2DUpdateNode::GetLoop() const {
    return GetSchemaValue<bool>(m_ptr, "CBlend2DUpdateNode", "m_bLoop");
}
void GCBlend2DUpdateNode::SetLoop(bool value) {
    SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_bLoop", false, value);
}
bool GCBlend2DUpdateNode::GetLockBlendOnReset() const {
    return GetSchemaValue<bool>(m_ptr, "CBlend2DUpdateNode", "m_bLockBlendOnReset");
}
void GCBlend2DUpdateNode::SetLockBlendOnReset(bool value) {
    SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_bLockBlendOnReset", false, value);
}
bool GCBlend2DUpdateNode::GetLockWhenWaning() const {
    return GetSchemaValue<bool>(m_ptr, "CBlend2DUpdateNode", "m_bLockWhenWaning");
}
void GCBlend2DUpdateNode::SetLockWhenWaning(bool value) {
    SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_bLockWhenWaning", false, value);
}
bool GCBlend2DUpdateNode::GetAnimEventsAndTagsOnMostWeightedOnly() const {
    return GetSchemaValue<bool>(m_ptr, "CBlend2DUpdateNode", "m_bAnimEventsAndTagsOnMostWeightedOnly");
}
void GCBlend2DUpdateNode::SetAnimEventsAndTagsOnMostWeightedOnly(bool value) {
    SetSchemaValue(m_ptr, "CBlend2DUpdateNode", "m_bAnimEventsAndTagsOnMostWeightedOnly", false, value);
}
std::string GCBlend2DUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBlend2DUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimUpdateNodeBase GCBlend2DUpdateNode::GetParent() const {
    GCAnimUpdateNodeBase value(m_ptr);
    return value;
}
void GCBlend2DUpdateNode::SetParent(GCAnimUpdateNodeBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBlend2DUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBlend2DUpdateNode>("CBlend2DUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Items", &GCBlend2DUpdateNode::GetItems, &GCBlend2DUpdateNode::SetItems)
        .addProperty("Tags", &GCBlend2DUpdateNode::GetTags, &GCBlend2DUpdateNode::SetTags)
        .addProperty("ParamSpans", &GCBlend2DUpdateNode::GetParamSpans, &GCBlend2DUpdateNode::SetParamSpans)
        .addProperty("NodeItemIndices", &GCBlend2DUpdateNode::GetNodeItemIndices, &GCBlend2DUpdateNode::SetNodeItemIndices)
        .addProperty("Damping", &GCBlend2DUpdateNode::GetDamping, &GCBlend2DUpdateNode::SetDamping)
        .addProperty("BlendSourceX", &GCBlend2DUpdateNode::GetBlendSourceX, &GCBlend2DUpdateNode::SetBlendSourceX)
        .addProperty("ParamX", &GCBlend2DUpdateNode::GetParamX, &GCBlend2DUpdateNode::SetParamX)
        .addProperty("BlendSourceY", &GCBlend2DUpdateNode::GetBlendSourceY, &GCBlend2DUpdateNode::SetBlendSourceY)
        .addProperty("ParamY", &GCBlend2DUpdateNode::GetParamY, &GCBlend2DUpdateNode::SetParamY)
        .addProperty("BlendMode", &GCBlend2DUpdateNode::GetBlendMode, &GCBlend2DUpdateNode::SetBlendMode)
        .addProperty("PlaybackSpeed", &GCBlend2DUpdateNode::GetPlaybackSpeed, &GCBlend2DUpdateNode::SetPlaybackSpeed)
        .addProperty("Loop", &GCBlend2DUpdateNode::GetLoop, &GCBlend2DUpdateNode::SetLoop)
        .addProperty("LockBlendOnReset", &GCBlend2DUpdateNode::GetLockBlendOnReset, &GCBlend2DUpdateNode::SetLockBlendOnReset)
        .addProperty("LockWhenWaning", &GCBlend2DUpdateNode::GetLockWhenWaning, &GCBlend2DUpdateNode::SetLockWhenWaning)
        .addProperty("AnimEventsAndTagsOnMostWeightedOnly", &GCBlend2DUpdateNode::GetAnimEventsAndTagsOnMostWeightedOnly, &GCBlend2DUpdateNode::SetAnimEventsAndTagsOnMostWeightedOnly)
        .addProperty("Parent", &GCBlend2DUpdateNode::GetParent, &GCBlend2DUpdateNode::SetParent)
        .addFunction("ToPtr", &GCBlend2DUpdateNode::ToPtr)
        .addFunction("IsValid", &GCBlend2DUpdateNode::IsValid)
        .endClass();
}