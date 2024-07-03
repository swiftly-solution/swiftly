#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundEnvelope::GCSoundEnvelope(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundEnvelope::GCSoundEnvelope(void *ptr) {
    m_ptr = ptr;
}
float GCSoundEnvelope::GetCurrent() const {
    return GetSchemaValue<float>(m_ptr, "CSoundEnvelope", "m_current");
}
void GCSoundEnvelope::SetCurrent(float value) {
    SetSchemaValue(m_ptr, "CSoundEnvelope", "m_current", false, value);
}
float GCSoundEnvelope::GetTarget() const {
    return GetSchemaValue<float>(m_ptr, "CSoundEnvelope", "m_target");
}
void GCSoundEnvelope::SetTarget(float value) {
    SetSchemaValue(m_ptr, "CSoundEnvelope", "m_target", false, value);
}
float GCSoundEnvelope::GetRate() const {
    return GetSchemaValue<float>(m_ptr, "CSoundEnvelope", "m_rate");
}
void GCSoundEnvelope::SetRate(float value) {
    SetSchemaValue(m_ptr, "CSoundEnvelope", "m_rate", false, value);
}
bool GCSoundEnvelope::GetForceupdate() const {
    return GetSchemaValue<bool>(m_ptr, "CSoundEnvelope", "m_forceupdate");
}
void GCSoundEnvelope::SetForceupdate(bool value) {
    SetSchemaValue(m_ptr, "CSoundEnvelope", "m_forceupdate", false, value);
}
std::string GCSoundEnvelope::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundEnvelope::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSoundEnvelope(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundEnvelope>("CSoundEnvelope")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Current", &GCSoundEnvelope::GetCurrent, &GCSoundEnvelope::SetCurrent)
        .addProperty("Target", &GCSoundEnvelope::GetTarget, &GCSoundEnvelope::SetTarget)
        .addProperty("Rate", &GCSoundEnvelope::GetRate, &GCSoundEnvelope::SetRate)
        .addProperty("Forceupdate", &GCSoundEnvelope::GetForceupdate, &GCSoundEnvelope::SetForceupdate)
        .addFunction("ToPtr", &GCSoundEnvelope::ToPtr)
        .addFunction("IsValid", &GCSoundEnvelope::IsValid)
        .endClass();
}