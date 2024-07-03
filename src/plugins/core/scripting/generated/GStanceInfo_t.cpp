#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GStanceInfo_t::GStanceInfo_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GStanceInfo_t::GStanceInfo_t(void *ptr) {
    m_ptr = ptr;
}
Vector GStanceInfo_t::GetPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "StanceInfo_t", "m_vPosition");
}
void GStanceInfo_t::SetPosition(Vector value) {
    SetSchemaValue(m_ptr, "StanceInfo_t", "m_vPosition", true, value);
}
float GStanceInfo_t::GetDirection() const {
    return GetSchemaValue<float>(m_ptr, "StanceInfo_t", "m_flDirection");
}
void GStanceInfo_t::SetDirection(float value) {
    SetSchemaValue(m_ptr, "StanceInfo_t", "m_flDirection", true, value);
}
std::string GStanceInfo_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GStanceInfo_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassStanceInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GStanceInfo_t>("StanceInfo_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Position", &GStanceInfo_t::GetPosition, &GStanceInfo_t::SetPosition)
        .addProperty("Direction", &GStanceInfo_t::GetDirection, &GStanceInfo_t::SetDirection)
        .addFunction("ToPtr", &GStanceInfo_t::ToPtr)
        .addFunction("IsValid", &GStanceInfo_t::IsValid)
        .endClass();
}