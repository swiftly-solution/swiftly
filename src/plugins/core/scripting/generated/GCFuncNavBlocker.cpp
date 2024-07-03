#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncNavBlocker::GCFuncNavBlocker(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncNavBlocker::GCFuncNavBlocker(void *ptr) {
    m_ptr = ptr;
}
bool GCFuncNavBlocker::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncNavBlocker", "m_bDisabled");
}
void GCFuncNavBlocker::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CFuncNavBlocker", "m_bDisabled", false, value);
}
int32_t GCFuncNavBlocker::GetBlockedTeamNumber() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFuncNavBlocker", "m_nBlockedTeamNumber");
}
void GCFuncNavBlocker::SetBlockedTeamNumber(int32_t value) {
    SetSchemaValue(m_ptr, "CFuncNavBlocker", "m_nBlockedTeamNumber", false, value);
}
std::string GCFuncNavBlocker::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncNavBlocker::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCFuncNavBlocker::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCFuncNavBlocker::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncNavBlocker(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncNavBlocker>("CFuncNavBlocker")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Disabled", &GCFuncNavBlocker::GetDisabled, &GCFuncNavBlocker::SetDisabled)
        .addProperty("BlockedTeamNumber", &GCFuncNavBlocker::GetBlockedTeamNumber, &GCFuncNavBlocker::SetBlockedTeamNumber)
        .addProperty("Parent", &GCFuncNavBlocker::GetParent, &GCFuncNavBlocker::SetParent)
        .addFunction("ToPtr", &GCFuncNavBlocker::ToPtr)
        .addFunction("IsValid", &GCFuncNavBlocker::IsValid)
        .endClass();
}