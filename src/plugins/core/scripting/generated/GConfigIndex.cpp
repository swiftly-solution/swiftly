#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GConfigIndex::GConfigIndex(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GConfigIndex::GConfigIndex(void *ptr) {
    m_ptr = ptr;
}
uint16_t GConfigIndex::GetGroup() const {
    return GetSchemaValue<uint16_t>(m_ptr, "ConfigIndex", "m_nGroup");
}
void GConfigIndex::SetGroup(uint16_t value) {
    SetSchemaValue(m_ptr, "ConfigIndex", "m_nGroup", false, value);
}
uint16_t GConfigIndex::GetConfig() const {
    return GetSchemaValue<uint16_t>(m_ptr, "ConfigIndex", "m_nConfig");
}
void GConfigIndex::SetConfig(uint16_t value) {
    SetSchemaValue(m_ptr, "ConfigIndex", "m_nConfig", false, value);
}
std::string GConfigIndex::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GConfigIndex::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassConfigIndex(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GConfigIndex>("ConfigIndex")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Group", &GConfigIndex::GetGroup, &GConfigIndex::SetGroup)
        .addProperty("Config", &GConfigIndex::GetConfig, &GConfigIndex::SetConfig)
        .addFunction("ToPtr", &GConfigIndex::ToPtr)
        .addFunction("IsValid", &GConfigIndex::IsValid)
        .endClass();
}