#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GAggregateMeshInfo_t::GAggregateMeshInfo_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GAggregateMeshInfo_t::GAggregateMeshInfo_t(void *ptr) {
    m_ptr = ptr;
}
uint32_t GAggregateMeshInfo_t::GetVisClusterMemberOffset() const {
    return GetSchemaValue<uint32_t>(m_ptr, "AggregateMeshInfo_t", "m_nVisClusterMemberOffset");
}
void GAggregateMeshInfo_t::SetVisClusterMemberOffset(uint32_t value) {
    SetSchemaValue(m_ptr, "AggregateMeshInfo_t", "m_nVisClusterMemberOffset", true, value);
}
uint8_t GAggregateMeshInfo_t::GetVisClusterMemberCount() const {
    return GetSchemaValue<uint8_t>(m_ptr, "AggregateMeshInfo_t", "m_nVisClusterMemberCount");
}
void GAggregateMeshInfo_t::SetVisClusterMemberCount(uint8_t value) {
    SetSchemaValue(m_ptr, "AggregateMeshInfo_t", "m_nVisClusterMemberCount", true, value);
}
bool GAggregateMeshInfo_t::GetHasTransform() const {
    return GetSchemaValue<bool>(m_ptr, "AggregateMeshInfo_t", "m_bHasTransform");
}
void GAggregateMeshInfo_t::SetHasTransform(bool value) {
    SetSchemaValue(m_ptr, "AggregateMeshInfo_t", "m_bHasTransform", true, value);
}
int16_t GAggregateMeshInfo_t::GetDrawCallIndex() const {
    return GetSchemaValue<int16_t>(m_ptr, "AggregateMeshInfo_t", "m_nDrawCallIndex");
}
void GAggregateMeshInfo_t::SetDrawCallIndex(int16_t value) {
    SetSchemaValue(m_ptr, "AggregateMeshInfo_t", "m_nDrawCallIndex", true, value);
}
int16_t GAggregateMeshInfo_t::GetLODSetupIndex() const {
    return GetSchemaValue<int16_t>(m_ptr, "AggregateMeshInfo_t", "m_nLODSetupIndex");
}
void GAggregateMeshInfo_t::SetLODSetupIndex(int16_t value) {
    SetSchemaValue(m_ptr, "AggregateMeshInfo_t", "m_nLODSetupIndex", true, value);
}
uint8_t GAggregateMeshInfo_t::GetLODGroupMask() const {
    return GetSchemaValue<uint8_t>(m_ptr, "AggregateMeshInfo_t", "m_nLODGroupMask");
}
void GAggregateMeshInfo_t::SetLODGroupMask(uint8_t value) {
    SetSchemaValue(m_ptr, "AggregateMeshInfo_t", "m_nLODGroupMask", true, value);
}
Color GAggregateMeshInfo_t::GetTintColor() const {
    return GetSchemaValue<Color>(m_ptr, "AggregateMeshInfo_t", "m_vTintColor");
}
void GAggregateMeshInfo_t::SetTintColor(Color value) {
    SetSchemaValue(m_ptr, "AggregateMeshInfo_t", "m_vTintColor", true, value);
}
uint64_t GAggregateMeshInfo_t::GetObjectFlags() const {
    return GetSchemaValue<uint64_t>(m_ptr, "AggregateMeshInfo_t", "m_objectFlags");
}
void GAggregateMeshInfo_t::SetObjectFlags(uint64_t value) {
    SetSchemaValue(m_ptr, "AggregateMeshInfo_t", "m_objectFlags", true, value);
}
int32_t GAggregateMeshInfo_t::GetLightProbeVolumePrecomputedHandshake() const {
    return GetSchemaValue<int32_t>(m_ptr, "AggregateMeshInfo_t", "m_nLightProbeVolumePrecomputedHandshake");
}
void GAggregateMeshInfo_t::SetLightProbeVolumePrecomputedHandshake(int32_t value) {
    SetSchemaValue(m_ptr, "AggregateMeshInfo_t", "m_nLightProbeVolumePrecomputedHandshake", true, value);
}
std::string GAggregateMeshInfo_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GAggregateMeshInfo_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassAggregateMeshInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAggregateMeshInfo_t>("AggregateMeshInfo_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("VisClusterMemberOffset", &GAggregateMeshInfo_t::GetVisClusterMemberOffset, &GAggregateMeshInfo_t::SetVisClusterMemberOffset)
        .addProperty("VisClusterMemberCount", &GAggregateMeshInfo_t::GetVisClusterMemberCount, &GAggregateMeshInfo_t::SetVisClusterMemberCount)
        .addProperty("HasTransform", &GAggregateMeshInfo_t::GetHasTransform, &GAggregateMeshInfo_t::SetHasTransform)
        .addProperty("DrawCallIndex", &GAggregateMeshInfo_t::GetDrawCallIndex, &GAggregateMeshInfo_t::SetDrawCallIndex)
        .addProperty("LODSetupIndex", &GAggregateMeshInfo_t::GetLODSetupIndex, &GAggregateMeshInfo_t::SetLODSetupIndex)
        .addProperty("LODGroupMask", &GAggregateMeshInfo_t::GetLODGroupMask, &GAggregateMeshInfo_t::SetLODGroupMask)
        .addProperty("TintColor", &GAggregateMeshInfo_t::GetTintColor, &GAggregateMeshInfo_t::SetTintColor)
        .addProperty("ObjectFlags", &GAggregateMeshInfo_t::GetObjectFlags, &GAggregateMeshInfo_t::SetObjectFlags)
        .addProperty("LightProbeVolumePrecomputedHandshake", &GAggregateMeshInfo_t::GetLightProbeVolumePrecomputedHandshake, &GAggregateMeshInfo_t::SetLightProbeVolumePrecomputedHandshake)
        .addFunction("ToPtr", &GAggregateMeshInfo_t::ToPtr)
        .addFunction("IsValid", &GAggregateMeshInfo_t::IsValid)
        .endClass();
}