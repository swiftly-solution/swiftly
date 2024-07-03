#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GWorldBuilderParams_t::GWorldBuilderParams_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GWorldBuilderParams_t::GWorldBuilderParams_t(void *ptr) {
    m_ptr = ptr;
}
float GWorldBuilderParams_t::GetMinDrawVolumeSize() const {
    return GetSchemaValue<float>(m_ptr, "WorldBuilderParams_t", "m_flMinDrawVolumeSize");
}
void GWorldBuilderParams_t::SetMinDrawVolumeSize(float value) {
    SetSchemaValue(m_ptr, "WorldBuilderParams_t", "m_flMinDrawVolumeSize", true, value);
}
bool GWorldBuilderParams_t::GetBuildBakedLighting() const {
    return GetSchemaValue<bool>(m_ptr, "WorldBuilderParams_t", "m_bBuildBakedLighting");
}
void GWorldBuilderParams_t::SetBuildBakedLighting(bool value) {
    SetSchemaValue(m_ptr, "WorldBuilderParams_t", "m_bBuildBakedLighting", true, value);
}
GBakedLightingInfo_t GWorldBuilderParams_t::GetBakedLightingInfo() const {
    GBakedLightingInfo_t value(GetSchemaPtr(m_ptr, "WorldBuilderParams_t", "m_bakedLightingInfo"));
    return value;
}
void GWorldBuilderParams_t::SetBakedLightingInfo(GBakedLightingInfo_t value) {
    SetSchemaValue(m_ptr, "WorldBuilderParams_t", "m_bakedLightingInfo", true, value);
}
uint64_t GWorldBuilderParams_t::GetCompileTimestamp() const {
    return GetSchemaValue<uint64_t>(m_ptr, "WorldBuilderParams_t", "m_nCompileTimestamp");
}
void GWorldBuilderParams_t::SetCompileTimestamp(uint64_t value) {
    SetSchemaValue(m_ptr, "WorldBuilderParams_t", "m_nCompileTimestamp", true, value);
}
uint64_t GWorldBuilderParams_t::GetCompileFingerprint() const {
    return GetSchemaValue<uint64_t>(m_ptr, "WorldBuilderParams_t", "m_nCompileFingerprint");
}
void GWorldBuilderParams_t::SetCompileFingerprint(uint64_t value) {
    SetSchemaValue(m_ptr, "WorldBuilderParams_t", "m_nCompileFingerprint", true, value);
}
std::string GWorldBuilderParams_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GWorldBuilderParams_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassWorldBuilderParams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GWorldBuilderParams_t>("WorldBuilderParams_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MinDrawVolumeSize", &GWorldBuilderParams_t::GetMinDrawVolumeSize, &GWorldBuilderParams_t::SetMinDrawVolumeSize)
        .addProperty("BuildBakedLighting", &GWorldBuilderParams_t::GetBuildBakedLighting, &GWorldBuilderParams_t::SetBuildBakedLighting)
        .addProperty("BakedLightingInfo", &GWorldBuilderParams_t::GetBakedLightingInfo, &GWorldBuilderParams_t::SetBakedLightingInfo)
        .addProperty("CompileTimestamp", &GWorldBuilderParams_t::GetCompileTimestamp, &GWorldBuilderParams_t::SetCompileTimestamp)
        .addProperty("CompileFingerprint", &GWorldBuilderParams_t::GetCompileFingerprint, &GWorldBuilderParams_t::SetCompileFingerprint)
        .addFunction("ToPtr", &GWorldBuilderParams_t::ToPtr)
        .addFunction("IsValid", &GWorldBuilderParams_t::IsValid)
        .endClass();
}