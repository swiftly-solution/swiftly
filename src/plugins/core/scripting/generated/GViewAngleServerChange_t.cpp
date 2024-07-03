#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GViewAngleServerChange_t::GViewAngleServerChange_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GViewAngleServerChange_t::GViewAngleServerChange_t(void *ptr) {
    m_ptr = ptr;
}
uint64_t GViewAngleServerChange_t::GetType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "ViewAngleServerChange_t", "nType");
}
void GViewAngleServerChange_t::SetType(uint64_t value) {
    SetSchemaValue(m_ptr, "ViewAngleServerChange_t", "nType", true, value);
}
QAngle GViewAngleServerChange_t::GetAngle() const {
    return GetSchemaValue<QAngle>(m_ptr, "ViewAngleServerChange_t", "qAngle");
}
void GViewAngleServerChange_t::SetAngle(QAngle value) {
    SetSchemaValue(m_ptr, "ViewAngleServerChange_t", "qAngle", true, value);
}
uint32_t GViewAngleServerChange_t::GetIndex() const {
    return GetSchemaValue<uint32_t>(m_ptr, "ViewAngleServerChange_t", "nIndex");
}
void GViewAngleServerChange_t::SetIndex(uint32_t value) {
    SetSchemaValue(m_ptr, "ViewAngleServerChange_t", "nIndex", true, value);
}
std::string GViewAngleServerChange_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GViewAngleServerChange_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassViewAngleServerChange_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GViewAngleServerChange_t>("ViewAngleServerChange_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Type", &GViewAngleServerChange_t::GetType, &GViewAngleServerChange_t::SetType)
        .addProperty("Angle", &GViewAngleServerChange_t::GetAngle, &GViewAngleServerChange_t::SetAngle)
        .addProperty("Index", &GViewAngleServerChange_t::GetIndex, &GViewAngleServerChange_t::SetIndex)
        .addFunction("ToPtr", &GViewAngleServerChange_t::ToPtr)
        .addFunction("IsValid", &GViewAngleServerChange_t::IsValid)
        .endClass();
}