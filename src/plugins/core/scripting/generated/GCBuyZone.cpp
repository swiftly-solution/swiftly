#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBuyZone::GCBuyZone(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBuyZone::GCBuyZone(void *ptr) {
    m_ptr = ptr;
}
int32_t GCBuyZone::GetLegacyTeamNum() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBuyZone", "m_LegacyTeamNum");
}
void GCBuyZone::SetLegacyTeamNum(int32_t value) {
    SetSchemaValue(m_ptr, "CBuyZone", "m_LegacyTeamNum", false, value);
}
std::string GCBuyZone::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBuyZone::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCBuyZone::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCBuyZone::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBuyZone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBuyZone>("CBuyZone")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LegacyTeamNum", &GCBuyZone::GetLegacyTeamNum, &GCBuyZone::SetLegacyTeamNum)
        .addProperty("Parent", &GCBuyZone::GetParent, &GCBuyZone::SetParent)
        .addFunction("ToPtr", &GCBuyZone::ToPtr)
        .addFunction("IsValid", &GCBuyZone::IsValid)
        .endClass();
}