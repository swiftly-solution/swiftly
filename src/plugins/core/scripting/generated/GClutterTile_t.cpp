#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GClutterTile_t::GClutterTile_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GClutterTile_t::GClutterTile_t(void *ptr) {
    m_ptr = ptr;
}
uint32_t GClutterTile_t::GetFirstInstance() const {
    return GetSchemaValue<uint32_t>(m_ptr, "ClutterTile_t", "m_nFirstInstance");
}
void GClutterTile_t::SetFirstInstance(uint32_t value) {
    SetSchemaValue(m_ptr, "ClutterTile_t", "m_nFirstInstance", true, value);
}
uint32_t GClutterTile_t::GetLastInstance() const {
    return GetSchemaValue<uint32_t>(m_ptr, "ClutterTile_t", "m_nLastInstance");
}
void GClutterTile_t::SetLastInstance(uint32_t value) {
    SetSchemaValue(m_ptr, "ClutterTile_t", "m_nLastInstance", true, value);
}
GAABB_t GClutterTile_t::GetBoundsWs() const {
    GAABB_t value(GetSchemaPtr(m_ptr, "ClutterTile_t", "m_BoundsWs"));
    return value;
}
void GClutterTile_t::SetBoundsWs(GAABB_t value) {
    SetSchemaValue(m_ptr, "ClutterTile_t", "m_BoundsWs", true, value);
}
std::string GClutterTile_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GClutterTile_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassClutterTile_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GClutterTile_t>("ClutterTile_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FirstInstance", &GClutterTile_t::GetFirstInstance, &GClutterTile_t::SetFirstInstance)
        .addProperty("LastInstance", &GClutterTile_t::GetLastInstance, &GClutterTile_t::SetLastInstance)
        .addProperty("BoundsWs", &GClutterTile_t::GetBoundsWs, &GClutterTile_t::SetBoundsWs)
        .addFunction("ToPtr", &GClutterTile_t::ToPtr)
        .addFunction("IsValid", &GClutterTile_t::IsValid)
        .endClass();
}