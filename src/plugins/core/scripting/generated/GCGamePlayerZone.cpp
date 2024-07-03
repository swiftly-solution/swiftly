#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCGamePlayerZone::GCGamePlayerZone(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCGamePlayerZone::GCGamePlayerZone(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCGamePlayerZone::GetOnPlayerInZone() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CGamePlayerZone", "m_OnPlayerInZone"));
    return value;
}
void GCGamePlayerZone::SetOnPlayerInZone(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CGamePlayerZone", "m_OnPlayerInZone", false, value);
}
GCEntityIOOutput GCGamePlayerZone::GetOnPlayerOutZone() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CGamePlayerZone", "m_OnPlayerOutZone"));
    return value;
}
void GCGamePlayerZone::SetOnPlayerOutZone(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CGamePlayerZone", "m_OnPlayerOutZone", false, value);
}
std::string GCGamePlayerZone::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCGamePlayerZone::IsValid() {
    return (m_ptr != nullptr);
}
GCRuleBrushEntity GCGamePlayerZone::GetParent() const {
    GCRuleBrushEntity value(m_ptr);
    return value;
}
void GCGamePlayerZone::SetParent(GCRuleBrushEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCGamePlayerZone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGamePlayerZone>("CGamePlayerZone")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnPlayerInZone", &GCGamePlayerZone::GetOnPlayerInZone, &GCGamePlayerZone::SetOnPlayerInZone)
        .addProperty("OnPlayerOutZone", &GCGamePlayerZone::GetOnPlayerOutZone, &GCGamePlayerZone::SetOnPlayerOutZone)
        .addProperty("Parent", &GCGamePlayerZone::GetParent, &GCGamePlayerZone::SetParent)
        .addFunction("ToPtr", &GCGamePlayerZone::ToPtr)
        .addFunction("IsValid", &GCGamePlayerZone::IsValid)
        .endClass();
}