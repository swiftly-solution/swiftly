#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GAABB_t::GAABB_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GAABB_t::GAABB_t(void *ptr) {
    m_ptr = ptr;
}
Vector GAABB_t::GetMinBounds() const {
    return GetSchemaValue<Vector>(m_ptr, "AABB_t", "m_vMinBounds");
}
void GAABB_t::SetMinBounds(Vector value) {
    SetSchemaValue(m_ptr, "AABB_t", "m_vMinBounds", true, value);
}
Vector GAABB_t::GetMaxBounds() const {
    return GetSchemaValue<Vector>(m_ptr, "AABB_t", "m_vMaxBounds");
}
void GAABB_t::SetMaxBounds(Vector value) {
    SetSchemaValue(m_ptr, "AABB_t", "m_vMaxBounds", true, value);
}
std::string GAABB_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GAABB_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassAABB_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAABB_t>("AABB_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MinBounds", &GAABB_t::GetMinBounds, &GAABB_t::SetMinBounds)
        .addProperty("MaxBounds", &GAABB_t::GetMaxBounds, &GAABB_t::SetMaxBounds)
        .addFunction("ToPtr", &GAABB_t::ToPtr)
        .addFunction("IsValid", &GAABB_t::IsValid)
        .endClass();
}