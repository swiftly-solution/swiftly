#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseDMStart::GCBaseDMStart(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseDMStart::GCBaseDMStart(void *ptr) {
    m_ptr = ptr;
}
std::string GCBaseDMStart::GetMaster() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseDMStart", "m_Master").String();
}
void GCBaseDMStart::SetMaster(std::string value) {
    SetSchemaValue(m_ptr, "CBaseDMStart", "m_Master", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBaseDMStart::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseDMStart::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCBaseDMStart::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCBaseDMStart::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseDMStart(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseDMStart>("CBaseDMStart")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Master", &GCBaseDMStart::GetMaster, &GCBaseDMStart::SetMaster)
        .addProperty("Parent", &GCBaseDMStart::GetParent, &GCBaseDMStart::SetParent)
        .addFunction("ToPtr", &GCBaseDMStart::ToPtr)
        .addFunction("IsValid", &GCBaseDMStart::IsValid)
        .endClass();
}