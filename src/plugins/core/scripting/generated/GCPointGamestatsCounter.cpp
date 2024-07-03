#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointGamestatsCounter::GCPointGamestatsCounter(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointGamestatsCounter::GCPointGamestatsCounter(void *ptr) {
    m_ptr = ptr;
}
std::string GCPointGamestatsCounter::GetStrStatisticName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointGamestatsCounter", "m_strStatisticName").String();
}
void GCPointGamestatsCounter::SetStrStatisticName(std::string value) {
    SetSchemaValue(m_ptr, "CPointGamestatsCounter", "m_strStatisticName", false, CUtlSymbolLarge(value.c_str()));
}
bool GCPointGamestatsCounter::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CPointGamestatsCounter", "m_bDisabled");
}
void GCPointGamestatsCounter::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CPointGamestatsCounter", "m_bDisabled", false, value);
}
std::string GCPointGamestatsCounter::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointGamestatsCounter::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCPointGamestatsCounter::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCPointGamestatsCounter::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointGamestatsCounter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointGamestatsCounter>("CPointGamestatsCounter")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StrStatisticName", &GCPointGamestatsCounter::GetStrStatisticName, &GCPointGamestatsCounter::SetStrStatisticName)
        .addProperty("Disabled", &GCPointGamestatsCounter::GetDisabled, &GCPointGamestatsCounter::SetDisabled)
        .addProperty("Parent", &GCPointGamestatsCounter::GetParent, &GCPointGamestatsCounter::SetParent)
        .addFunction("ToPtr", &GCPointGamestatsCounter::ToPtr)
        .addFunction("IsValid", &GCPointGamestatsCounter::IsValid)
        .endClass();
}