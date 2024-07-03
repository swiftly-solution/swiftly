#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCStopwatch::GCStopwatch(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCStopwatch::GCStopwatch(void *ptr) {
    m_ptr = ptr;
}
float GCStopwatch::GetInterval() const {
    return GetSchemaValue<float>(m_ptr, "CStopwatch", "m_interval");
}
void GCStopwatch::SetInterval(float value) {
    SetSchemaValue(m_ptr, "CStopwatch", "m_interval", false, value);
}
std::string GCStopwatch::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCStopwatch::IsValid() {
    return (m_ptr != nullptr);
}
GCStopwatchBase GCStopwatch::GetParent() const {
    GCStopwatchBase value(m_ptr);
    return value;
}
void GCStopwatch::SetParent(GCStopwatchBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCStopwatch(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStopwatch>("CStopwatch")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Interval", &GCStopwatch::GetInterval, &GCStopwatch::SetInterval)
        .addProperty("Parent", &GCStopwatch::GetParent, &GCStopwatch::SetParent)
        .addFunction("ToPtr", &GCStopwatch::ToPtr)
        .addFunction("IsValid", &GCStopwatch::IsValid)
        .endClass();
}