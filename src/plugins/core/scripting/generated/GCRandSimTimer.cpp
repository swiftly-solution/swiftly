#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRandSimTimer::GCRandSimTimer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRandSimTimer::GCRandSimTimer(void *ptr) {
    m_ptr = ptr;
}
float GCRandSimTimer::GetMinInterval() const {
    return GetSchemaValue<float>(m_ptr, "CRandSimTimer", "m_minInterval");
}
void GCRandSimTimer::SetMinInterval(float value) {
    SetSchemaValue(m_ptr, "CRandSimTimer", "m_minInterval", false, value);
}
float GCRandSimTimer::GetMaxInterval() const {
    return GetSchemaValue<float>(m_ptr, "CRandSimTimer", "m_maxInterval");
}
void GCRandSimTimer::SetMaxInterval(float value) {
    SetSchemaValue(m_ptr, "CRandSimTimer", "m_maxInterval", false, value);
}
std::string GCRandSimTimer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRandSimTimer::IsValid() {
    return (m_ptr != nullptr);
}
GCSimpleSimTimer GCRandSimTimer::GetParent() const {
    GCSimpleSimTimer value(m_ptr);
    return value;
}
void GCRandSimTimer::SetParent(GCSimpleSimTimer value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRandSimTimer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRandSimTimer>("CRandSimTimer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MinInterval", &GCRandSimTimer::GetMinInterval, &GCRandSimTimer::SetMinInterval)
        .addProperty("MaxInterval", &GCRandSimTimer::GetMaxInterval, &GCRandSimTimer::SetMaxInterval)
        .addProperty("Parent", &GCRandSimTimer::GetParent, &GCRandSimTimer::SetParent)
        .addFunction("ToPtr", &GCRandSimTimer::ToPtr)
        .addFunction("IsValid", &GCRandSimTimer::IsValid)
        .endClass();
}