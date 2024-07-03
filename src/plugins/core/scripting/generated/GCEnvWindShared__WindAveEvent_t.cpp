#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvWindShared__WindAveEvent_t::GCEnvWindShared__WindAveEvent_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvWindShared__WindAveEvent_t::GCEnvWindShared__WindAveEvent_t(void *ptr) {
    m_ptr = ptr;
}
float GCEnvWindShared__WindAveEvent_t::GetStartWindSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CEnvWindShared__WindAveEvent_t", "m_flStartWindSpeed");
}
void GCEnvWindShared__WindAveEvent_t::SetStartWindSpeed(float value) {
    SetSchemaValue(m_ptr, "CEnvWindShared__WindAveEvent_t", "m_flStartWindSpeed", true, value);
}
float GCEnvWindShared__WindAveEvent_t::GetAveWindSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CEnvWindShared__WindAveEvent_t", "m_flAveWindSpeed");
}
void GCEnvWindShared__WindAveEvent_t::SetAveWindSpeed(float value) {
    SetSchemaValue(m_ptr, "CEnvWindShared__WindAveEvent_t", "m_flAveWindSpeed", true, value);
}
std::string GCEnvWindShared__WindAveEvent_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvWindShared__WindAveEvent_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCEnvWindShared__WindAveEvent_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvWindShared__WindAveEvent_t>("CEnvWindShared__WindAveEvent_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StartWindSpeed", &GCEnvWindShared__WindAveEvent_t::GetStartWindSpeed, &GCEnvWindShared__WindAveEvent_t::SetStartWindSpeed)
        .addProperty("AveWindSpeed", &GCEnvWindShared__WindAveEvent_t::GetAveWindSpeed, &GCEnvWindShared__WindAveEvent_t::SetAveWindSpeed)
        .addFunction("ToPtr", &GCEnvWindShared__WindAveEvent_t::ToPtr)
        .addFunction("IsValid", &GCEnvWindShared__WindAveEvent_t::IsValid)
        .endClass();
}