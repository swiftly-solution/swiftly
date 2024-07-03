#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCStopwatchBase::GCStopwatchBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCStopwatchBase::GCStopwatchBase(void *ptr) {
    m_ptr = ptr;
}
bool GCStopwatchBase::GetIsRunning() const {
    return GetSchemaValue<bool>(m_ptr, "CStopwatchBase", "m_fIsRunning");
}
void GCStopwatchBase::SetIsRunning(bool value) {
    SetSchemaValue(m_ptr, "CStopwatchBase", "m_fIsRunning", false, value);
}
std::string GCStopwatchBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCStopwatchBase::IsValid() {
    return (m_ptr != nullptr);
}
GCSimpleSimTimer GCStopwatchBase::GetParent() const {
    GCSimpleSimTimer value(m_ptr);
    return value;
}
void GCStopwatchBase::SetParent(GCSimpleSimTimer value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCStopwatchBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStopwatchBase>("CStopwatchBase")
        .addConstructor<void (*)(std::string)>()
        .addProperty("IsRunning", &GCStopwatchBase::GetIsRunning, &GCStopwatchBase::SetIsRunning)
        .addProperty("Parent", &GCStopwatchBase::GetParent, &GCStopwatchBase::SetParent)
        .addFunction("ToPtr", &GCStopwatchBase::ToPtr)
        .addFunction("IsValid", &GCStopwatchBase::IsValid)
        .endClass();
}