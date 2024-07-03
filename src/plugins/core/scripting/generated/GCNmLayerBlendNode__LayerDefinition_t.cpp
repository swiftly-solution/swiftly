#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmLayerBlendNode__LayerDefinition_t::GCNmLayerBlendNode__LayerDefinition_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmLayerBlendNode__LayerDefinition_t::GCNmLayerBlendNode__LayerDefinition_t(void *ptr) {
    m_ptr = ptr;
}
int16_t GCNmLayerBlendNode__LayerDefinition_t::GetInputNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_nInputNodeIdx");
}
void GCNmLayerBlendNode__LayerDefinition_t::SetInputNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_nInputNodeIdx", true, value);
}
int16_t GCNmLayerBlendNode__LayerDefinition_t::GetWeightValueNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_nWeightValueNodeIdx");
}
void GCNmLayerBlendNode__LayerDefinition_t::SetWeightValueNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_nWeightValueNodeIdx", true, value);
}
int16_t GCNmLayerBlendNode__LayerDefinition_t::GetBoneMaskValueNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_nBoneMaskValueNodeIdx");
}
void GCNmLayerBlendNode__LayerDefinition_t::SetBoneMaskValueNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_nBoneMaskValueNodeIdx", true, value);
}
int16_t GCNmLayerBlendNode__LayerDefinition_t::GetRootMotionWeightValueNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_nRootMotionWeightValueNodeIdx");
}
void GCNmLayerBlendNode__LayerDefinition_t::SetRootMotionWeightValueNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_nRootMotionWeightValueNodeIdx", true, value);
}
bool GCNmLayerBlendNode__LayerDefinition_t::GetIsSynchronized() const {
    return GetSchemaValue<bool>(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_bIsSynchronized");
}
void GCNmLayerBlendNode__LayerDefinition_t::SetIsSynchronized(bool value) {
    SetSchemaValue(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_bIsSynchronized", true, value);
}
bool GCNmLayerBlendNode__LayerDefinition_t::GetIgnoreEvents() const {
    return GetSchemaValue<bool>(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_bIgnoreEvents");
}
void GCNmLayerBlendNode__LayerDefinition_t::SetIgnoreEvents(bool value) {
    SetSchemaValue(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_bIgnoreEvents", true, value);
}
bool GCNmLayerBlendNode__LayerDefinition_t::GetIsStateMachineLayer() const {
    return GetSchemaValue<bool>(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_bIsStateMachineLayer");
}
void GCNmLayerBlendNode__LayerDefinition_t::SetIsStateMachineLayer(bool value) {
    SetSchemaValue(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_bIsStateMachineLayer", true, value);
}
uint64_t GCNmLayerBlendNode__LayerDefinition_t::GetBlendMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_blendMode");
}
void GCNmLayerBlendNode__LayerDefinition_t::SetBlendMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CNmLayerBlendNode__LayerDefinition_t", "m_blendMode", true, value);
}
std::string GCNmLayerBlendNode__LayerDefinition_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmLayerBlendNode__LayerDefinition_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNmLayerBlendNode__LayerDefinition_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmLayerBlendNode__LayerDefinition_t>("CNmLayerBlendNode__LayerDefinition_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("InputNodeIdx", &GCNmLayerBlendNode__LayerDefinition_t::GetInputNodeIdx, &GCNmLayerBlendNode__LayerDefinition_t::SetInputNodeIdx)
        .addProperty("WeightValueNodeIdx", &GCNmLayerBlendNode__LayerDefinition_t::GetWeightValueNodeIdx, &GCNmLayerBlendNode__LayerDefinition_t::SetWeightValueNodeIdx)
        .addProperty("BoneMaskValueNodeIdx", &GCNmLayerBlendNode__LayerDefinition_t::GetBoneMaskValueNodeIdx, &GCNmLayerBlendNode__LayerDefinition_t::SetBoneMaskValueNodeIdx)
        .addProperty("RootMotionWeightValueNodeIdx", &GCNmLayerBlendNode__LayerDefinition_t::GetRootMotionWeightValueNodeIdx, &GCNmLayerBlendNode__LayerDefinition_t::SetRootMotionWeightValueNodeIdx)
        .addProperty("IsSynchronized", &GCNmLayerBlendNode__LayerDefinition_t::GetIsSynchronized, &GCNmLayerBlendNode__LayerDefinition_t::SetIsSynchronized)
        .addProperty("IgnoreEvents", &GCNmLayerBlendNode__LayerDefinition_t::GetIgnoreEvents, &GCNmLayerBlendNode__LayerDefinition_t::SetIgnoreEvents)
        .addProperty("IsStateMachineLayer", &GCNmLayerBlendNode__LayerDefinition_t::GetIsStateMachineLayer, &GCNmLayerBlendNode__LayerDefinition_t::SetIsStateMachineLayer)
        .addProperty("BlendMode", &GCNmLayerBlendNode__LayerDefinition_t::GetBlendMode, &GCNmLayerBlendNode__LayerDefinition_t::SetBlendMode)
        .addFunction("ToPtr", &GCNmLayerBlendNode__LayerDefinition_t::ToPtr)
        .addFunction("IsValid", &GCNmLayerBlendNode__LayerDefinition_t::IsValid)
        .endClass();
}