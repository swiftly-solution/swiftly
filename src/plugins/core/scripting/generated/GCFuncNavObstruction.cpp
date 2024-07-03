#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncNavObstruction::GCFuncNavObstruction(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncNavObstruction::GCFuncNavObstruction(void *ptr) {
    m_ptr = ptr;
}
bool GCFuncNavObstruction::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncNavObstruction", "m_bDisabled");
}
void GCFuncNavObstruction::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CFuncNavObstruction", "m_bDisabled", false, value);
}
std::string GCFuncNavObstruction::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncNavObstruction::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCFuncNavObstruction::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCFuncNavObstruction::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncNavObstruction(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncNavObstruction>("CFuncNavObstruction")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Disabled", &GCFuncNavObstruction::GetDisabled, &GCFuncNavObstruction::SetDisabled)
        .addProperty("Parent", &GCFuncNavObstruction::GetParent, &GCFuncNavObstruction::SetParent)
        .addFunction("ToPtr", &GCFuncNavObstruction::ToPtr)
        .addFunction("IsValid", &GCFuncNavObstruction::IsValid)
        .endClass();
}