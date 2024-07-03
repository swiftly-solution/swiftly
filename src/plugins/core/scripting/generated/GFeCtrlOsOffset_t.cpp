#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeCtrlOsOffset_t::GFeCtrlOsOffset_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeCtrlOsOffset_t::GFeCtrlOsOffset_t(void *ptr) {
    m_ptr = ptr;
}
uint16_t GFeCtrlOsOffset_t::GetCtrlParent() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeCtrlOsOffset_t", "nCtrlParent");
}
void GFeCtrlOsOffset_t::SetCtrlParent(uint16_t value) {
    SetSchemaValue(m_ptr, "FeCtrlOsOffset_t", "nCtrlParent", true, value);
}
uint16_t GFeCtrlOsOffset_t::GetCtrlChild() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeCtrlOsOffset_t", "nCtrlChild");
}
void GFeCtrlOsOffset_t::SetCtrlChild(uint16_t value) {
    SetSchemaValue(m_ptr, "FeCtrlOsOffset_t", "nCtrlChild", true, value);
}
std::string GFeCtrlOsOffset_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeCtrlOsOffset_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeCtrlOsOffset_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeCtrlOsOffset_t>("FeCtrlOsOffset_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CtrlParent", &GFeCtrlOsOffset_t::GetCtrlParent, &GFeCtrlOsOffset_t::SetCtrlParent)
        .addProperty("CtrlChild", &GFeCtrlOsOffset_t::GetCtrlChild, &GFeCtrlOsOffset_t::SetCtrlChild)
        .addFunction("ToPtr", &GFeCtrlOsOffset_t::ToPtr)
        .addFunction("IsValid", &GFeCtrlOsOffset_t::IsValid)
        .endClass();
}