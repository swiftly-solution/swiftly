#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GNavGravity_t::GNavGravity_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GNavGravity_t::GNavGravity_t(void *ptr) {
    m_ptr = ptr;
}
Vector GNavGravity_t::GetGravity() const {
    return GetSchemaValue<Vector>(m_ptr, "NavGravity_t", "m_vGravity");
}
void GNavGravity_t::SetGravity(Vector value) {
    SetSchemaValue(m_ptr, "NavGravity_t", "m_vGravity", true, value);
}
bool GNavGravity_t::GetDefault() const {
    return GetSchemaValue<bool>(m_ptr, "NavGravity_t", "m_bDefault");
}
void GNavGravity_t::SetDefault(bool value) {
    SetSchemaValue(m_ptr, "NavGravity_t", "m_bDefault", true, value);
}
std::string GNavGravity_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GNavGravity_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassNavGravity_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GNavGravity_t>("NavGravity_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Gravity", &GNavGravity_t::GetGravity, &GNavGravity_t::SetGravity)
        .addProperty("Default", &GNavGravity_t::GetDefault, &GNavGravity_t::SetDefault)
        .addFunction("ToPtr", &GNavGravity_t::ToPtr)
        .addFunction("IsValid", &GNavGravity_t::IsValid)
        .endClass();
}