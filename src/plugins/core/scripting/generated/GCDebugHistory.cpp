#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDebugHistory::GCDebugHistory(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDebugHistory::GCDebugHistory(void *ptr) {
    m_ptr = ptr;
}
int32_t GCDebugHistory::GetNpcEvents() const {
    return GetSchemaValue<int32_t>(m_ptr, "CDebugHistory", "m_nNpcEvents");
}
void GCDebugHistory::SetNpcEvents(int32_t value) {
    SetSchemaValue(m_ptr, "CDebugHistory", "m_nNpcEvents", false, value);
}
std::string GCDebugHistory::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDebugHistory::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCDebugHistory::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCDebugHistory::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCDebugHistory(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDebugHistory>("CDebugHistory")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NpcEvents", &GCDebugHistory::GetNpcEvents, &GCDebugHistory::SetNpcEvents)
        .addProperty("Parent", &GCDebugHistory::GetParent, &GCDebugHistory::SetParent)
        .addFunction("ToPtr", &GCDebugHistory::ToPtr)
        .addFunction("IsValid", &GCDebugHistory::IsValid)
        .endClass();
}