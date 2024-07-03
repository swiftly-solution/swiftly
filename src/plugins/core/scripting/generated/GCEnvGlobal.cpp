#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvGlobal::GCEnvGlobal(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvGlobal::GCEnvGlobal(void *ptr) {
    m_ptr = ptr;
}
std::string GCEnvGlobal::GetGlobalstate() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvGlobal", "m_globalstate").String();
}
void GCEnvGlobal::SetGlobalstate(std::string value) {
    SetSchemaValue(m_ptr, "CEnvGlobal", "m_globalstate", false, CUtlSymbolLarge(value.c_str()));
}
int32_t GCEnvGlobal::GetTriggermode() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvGlobal", "m_triggermode");
}
void GCEnvGlobal::SetTriggermode(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvGlobal", "m_triggermode", false, value);
}
int32_t GCEnvGlobal::GetInitialstate() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvGlobal", "m_initialstate");
}
void GCEnvGlobal::SetInitialstate(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvGlobal", "m_initialstate", false, value);
}
int32_t GCEnvGlobal::GetCounter() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvGlobal", "m_counter");
}
void GCEnvGlobal::SetCounter(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvGlobal", "m_counter", false, value);
}
std::string GCEnvGlobal::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvGlobal::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCEnvGlobal::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCEnvGlobal::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvGlobal(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvGlobal>("CEnvGlobal")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Globalstate", &GCEnvGlobal::GetGlobalstate, &GCEnvGlobal::SetGlobalstate)
        .addProperty("Triggermode", &GCEnvGlobal::GetTriggermode, &GCEnvGlobal::SetTriggermode)
        .addProperty("Initialstate", &GCEnvGlobal::GetInitialstate, &GCEnvGlobal::SetInitialstate)
        .addProperty("Counter", &GCEnvGlobal::GetCounter, &GCEnvGlobal::SetCounter)
        .addProperty("Parent", &GCEnvGlobal::GetParent, &GCEnvGlobal::SetParent)
        .addFunction("ToPtr", &GCEnvGlobal::ToPtr)
        .addFunction("IsValid", &GCEnvGlobal::IsValid)
        .endClass();
}