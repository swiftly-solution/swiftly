#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRandStopwatch::GCRandStopwatch(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRandStopwatch::GCRandStopwatch(void *ptr) {
    m_ptr = ptr;
}
float GCRandStopwatch::GetMinInterval() const {
    return GetSchemaValue<float>(m_ptr, "CRandStopwatch", "m_minInterval");
}
void GCRandStopwatch::SetMinInterval(float value) {
    SetSchemaValue(m_ptr, "CRandStopwatch", "m_minInterval", false, value);
}
float GCRandStopwatch::GetMaxInterval() const {
    return GetSchemaValue<float>(m_ptr, "CRandStopwatch", "m_maxInterval");
}
void GCRandStopwatch::SetMaxInterval(float value) {
    SetSchemaValue(m_ptr, "CRandStopwatch", "m_maxInterval", false, value);
}
std::string GCRandStopwatch::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRandStopwatch::IsValid() {
    return (m_ptr != nullptr);
}
GCStopwatchBase GCRandStopwatch::GetParent() const {
    GCStopwatchBase value(m_ptr);
    return value;
}
void GCRandStopwatch::SetParent(GCStopwatchBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRandStopwatch(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRandStopwatch>("CRandStopwatch")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MinInterval", &GCRandStopwatch::GetMinInterval, &GCRandStopwatch::SetMinInterval)
        .addProperty("MaxInterval", &GCRandStopwatch::GetMaxInterval, &GCRandStopwatch::SetMaxInterval)
        .addProperty("Parent", &GCRandStopwatch::GetParent, &GCRandStopwatch::SetParent)
        .addFunction("ToPtr", &GCRandStopwatch::ToPtr)
        .addFunction("IsValid", &GCRandStopwatch::IsValid)
        .endClass();
}