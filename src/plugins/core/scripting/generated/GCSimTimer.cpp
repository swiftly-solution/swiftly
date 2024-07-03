#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSimTimer::GCSimTimer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSimTimer::GCSimTimer(void *ptr) {
    m_ptr = ptr;
}
float GCSimTimer::GetInterval() const {
    return GetSchemaValue<float>(m_ptr, "CSimTimer", "m_interval");
}
void GCSimTimer::SetInterval(float value) {
    SetSchemaValue(m_ptr, "CSimTimer", "m_interval", false, value);
}
std::string GCSimTimer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSimTimer::IsValid() {
    return (m_ptr != nullptr);
}
GCSimpleSimTimer GCSimTimer::GetParent() const {
    GCSimpleSimTimer value(m_ptr);
    return value;
}
void GCSimTimer::SetParent(GCSimpleSimTimer value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSimTimer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSimTimer>("CSimTimer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Interval", &GCSimTimer::GetInterval, &GCSimTimer::SetInterval)
        .addProperty("Parent", &GCSimTimer::GetParent, &GCSimTimer::SetParent)
        .addFunction("ToPtr", &GCSimTimer::ToPtr)
        .addFunction("IsValid", &GCSimTimer::IsValid)
        .endClass();
}