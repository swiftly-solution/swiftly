#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvWindShared__WindVariationEvent_t::GCEnvWindShared__WindVariationEvent_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvWindShared__WindVariationEvent_t::GCEnvWindShared__WindVariationEvent_t(void *ptr) {
    m_ptr = ptr;
}
float GCEnvWindShared__WindVariationEvent_t::GetWindAngleVariation() const {
    return GetSchemaValue<float>(m_ptr, "CEnvWindShared__WindVariationEvent_t", "m_flWindAngleVariation");
}
void GCEnvWindShared__WindVariationEvent_t::SetWindAngleVariation(float value) {
    SetSchemaValue(m_ptr, "CEnvWindShared__WindVariationEvent_t", "m_flWindAngleVariation", true, value);
}
float GCEnvWindShared__WindVariationEvent_t::GetWindSpeedVariation() const {
    return GetSchemaValue<float>(m_ptr, "CEnvWindShared__WindVariationEvent_t", "m_flWindSpeedVariation");
}
void GCEnvWindShared__WindVariationEvent_t::SetWindSpeedVariation(float value) {
    SetSchemaValue(m_ptr, "CEnvWindShared__WindVariationEvent_t", "m_flWindSpeedVariation", true, value);
}
std::string GCEnvWindShared__WindVariationEvent_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvWindShared__WindVariationEvent_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCEnvWindShared__WindVariationEvent_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvWindShared__WindVariationEvent_t>("CEnvWindShared__WindVariationEvent_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("WindAngleVariation", &GCEnvWindShared__WindVariationEvent_t::GetWindAngleVariation, &GCEnvWindShared__WindVariationEvent_t::SetWindAngleVariation)
        .addProperty("WindSpeedVariation", &GCEnvWindShared__WindVariationEvent_t::GetWindSpeedVariation, &GCEnvWindShared__WindVariationEvent_t::SetWindSpeedVariation)
        .addFunction("ToPtr", &GCEnvWindShared__WindVariationEvent_t::ToPtr)
        .addFunction("IsValid", &GCEnvWindShared__WindVariationEvent_t::IsValid)
        .endClass();
}