#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBoneMaskUpdateNode::GCBoneMaskUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBoneMaskUpdateNode::GCBoneMaskUpdateNode(void *ptr) {
    m_ptr = ptr;
}
int32_t GCBoneMaskUpdateNode::GetWeightListIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBoneMaskUpdateNode", "m_nWeightListIndex");
}
void GCBoneMaskUpdateNode::SetWeightListIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CBoneMaskUpdateNode", "m_nWeightListIndex", false, value);
}
float GCBoneMaskUpdateNode::GetRootMotionBlend() const {
    return GetSchemaValue<float>(m_ptr, "CBoneMaskUpdateNode", "m_flRootMotionBlend");
}
void GCBoneMaskUpdateNode::SetRootMotionBlend(float value) {
    SetSchemaValue(m_ptr, "CBoneMaskUpdateNode", "m_flRootMotionBlend", false, value);
}
uint64_t GCBoneMaskUpdateNode::GetBlendSpace() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBoneMaskUpdateNode", "m_blendSpace");
}
void GCBoneMaskUpdateNode::SetBlendSpace(uint64_t value) {
    SetSchemaValue(m_ptr, "CBoneMaskUpdateNode", "m_blendSpace", false, value);
}
uint64_t GCBoneMaskUpdateNode::GetFootMotionTiming() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBoneMaskUpdateNode", "m_footMotionTiming");
}
void GCBoneMaskUpdateNode::SetFootMotionTiming(uint64_t value) {
    SetSchemaValue(m_ptr, "CBoneMaskUpdateNode", "m_footMotionTiming", false, value);
}
bool GCBoneMaskUpdateNode::GetUseBlendScale() const {
    return GetSchemaValue<bool>(m_ptr, "CBoneMaskUpdateNode", "m_bUseBlendScale");
}
void GCBoneMaskUpdateNode::SetUseBlendScale(bool value) {
    SetSchemaValue(m_ptr, "CBoneMaskUpdateNode", "m_bUseBlendScale", false, value);
}
uint64_t GCBoneMaskUpdateNode::GetBlendValueSource() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBoneMaskUpdateNode", "m_blendValueSource");
}
void GCBoneMaskUpdateNode::SetBlendValueSource(uint64_t value) {
    SetSchemaValue(m_ptr, "CBoneMaskUpdateNode", "m_blendValueSource", false, value);
}
GCAnimParamHandle GCBoneMaskUpdateNode::GetBlendParameter() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CBoneMaskUpdateNode", "m_hBlendParameter"));
    return value;
}
void GCBoneMaskUpdateNode::SetBlendParameter(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CBoneMaskUpdateNode", "m_hBlendParameter", false, value);
}
std::string GCBoneMaskUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBoneMaskUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCBinaryUpdateNode GCBoneMaskUpdateNode::GetParent() const {
    GCBinaryUpdateNode value(m_ptr);
    return value;
}
void GCBoneMaskUpdateNode::SetParent(GCBinaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBoneMaskUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBoneMaskUpdateNode>("CBoneMaskUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("WeightListIndex", &GCBoneMaskUpdateNode::GetWeightListIndex, &GCBoneMaskUpdateNode::SetWeightListIndex)
        .addProperty("RootMotionBlend", &GCBoneMaskUpdateNode::GetRootMotionBlend, &GCBoneMaskUpdateNode::SetRootMotionBlend)
        .addProperty("BlendSpace", &GCBoneMaskUpdateNode::GetBlendSpace, &GCBoneMaskUpdateNode::SetBlendSpace)
        .addProperty("FootMotionTiming", &GCBoneMaskUpdateNode::GetFootMotionTiming, &GCBoneMaskUpdateNode::SetFootMotionTiming)
        .addProperty("UseBlendScale", &GCBoneMaskUpdateNode::GetUseBlendScale, &GCBoneMaskUpdateNode::SetUseBlendScale)
        .addProperty("BlendValueSource", &GCBoneMaskUpdateNode::GetBlendValueSource, &GCBoneMaskUpdateNode::SetBlendValueSource)
        .addProperty("BlendParameter", &GCBoneMaskUpdateNode::GetBlendParameter, &GCBoneMaskUpdateNode::SetBlendParameter)
        .addProperty("Parent", &GCBoneMaskUpdateNode::GetParent, &GCBoneMaskUpdateNode::SetParent)
        .addFunction("ToPtr", &GCBoneMaskUpdateNode::ToPtr)
        .addFunction("IsValid", &GCBoneMaskUpdateNode::IsValid)
        .endClass();
}