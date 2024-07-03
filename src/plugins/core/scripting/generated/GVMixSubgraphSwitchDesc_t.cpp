#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixSubgraphSwitchDesc_t::GVMixSubgraphSwitchDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixSubgraphSwitchDesc_t::GVMixSubgraphSwitchDesc_t(void *ptr) {
    m_ptr = ptr;
}
uint64_t GVMixSubgraphSwitchDesc_t::GetInterpolationMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "VMixSubgraphSwitchDesc_t", "m_interpolationMode");
}
void GVMixSubgraphSwitchDesc_t::SetInterpolationMode(uint64_t value) {
    SetSchemaValue(m_ptr, "VMixSubgraphSwitchDesc_t", "m_interpolationMode", true, value);
}
bool GVMixSubgraphSwitchDesc_t::GetOnlyTailsOnFadeOut() const {
    return GetSchemaValue<bool>(m_ptr, "VMixSubgraphSwitchDesc_t", "m_bOnlyTailsOnFadeOut");
}
void GVMixSubgraphSwitchDesc_t::SetOnlyTailsOnFadeOut(bool value) {
    SetSchemaValue(m_ptr, "VMixSubgraphSwitchDesc_t", "m_bOnlyTailsOnFadeOut", true, value);
}
float GVMixSubgraphSwitchDesc_t::GetInterpolationTime() const {
    return GetSchemaValue<float>(m_ptr, "VMixSubgraphSwitchDesc_t", "m_flInterpolationTime");
}
void GVMixSubgraphSwitchDesc_t::SetInterpolationTime(float value) {
    SetSchemaValue(m_ptr, "VMixSubgraphSwitchDesc_t", "m_flInterpolationTime", true, value);
}
std::string GVMixSubgraphSwitchDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixSubgraphSwitchDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixSubgraphSwitchDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixSubgraphSwitchDesc_t>("VMixSubgraphSwitchDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("InterpolationMode", &GVMixSubgraphSwitchDesc_t::GetInterpolationMode, &GVMixSubgraphSwitchDesc_t::SetInterpolationMode)
        .addProperty("OnlyTailsOnFadeOut", &GVMixSubgraphSwitchDesc_t::GetOnlyTailsOnFadeOut, &GVMixSubgraphSwitchDesc_t::SetOnlyTailsOnFadeOut)
        .addProperty("InterpolationTime", &GVMixSubgraphSwitchDesc_t::GetInterpolationTime, &GVMixSubgraphSwitchDesc_t::SetInterpolationTime)
        .addFunction("ToPtr", &GVMixSubgraphSwitchDesc_t::ToPtr)
        .addFunction("IsValid", &GVMixSubgraphSwitchDesc_t::IsValid)
        .endClass();
}