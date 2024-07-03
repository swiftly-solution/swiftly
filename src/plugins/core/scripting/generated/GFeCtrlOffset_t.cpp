#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeCtrlOffset_t::GFeCtrlOffset_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeCtrlOffset_t::GFeCtrlOffset_t(void *ptr) {
    m_ptr = ptr;
}
Vector GFeCtrlOffset_t::GetOffset() const {
    return GetSchemaValue<Vector>(m_ptr, "FeCtrlOffset_t", "vOffset");
}
void GFeCtrlOffset_t::SetOffset(Vector value) {
    SetSchemaValue(m_ptr, "FeCtrlOffset_t", "vOffset", true, value);
}
uint16_t GFeCtrlOffset_t::GetCtrlParent() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeCtrlOffset_t", "nCtrlParent");
}
void GFeCtrlOffset_t::SetCtrlParent(uint16_t value) {
    SetSchemaValue(m_ptr, "FeCtrlOffset_t", "nCtrlParent", true, value);
}
uint16_t GFeCtrlOffset_t::GetCtrlChild() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeCtrlOffset_t", "nCtrlChild");
}
void GFeCtrlOffset_t::SetCtrlChild(uint16_t value) {
    SetSchemaValue(m_ptr, "FeCtrlOffset_t", "nCtrlChild", true, value);
}
std::string GFeCtrlOffset_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeCtrlOffset_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeCtrlOffset_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeCtrlOffset_t>("FeCtrlOffset_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Offset", &GFeCtrlOffset_t::GetOffset, &GFeCtrlOffset_t::SetOffset)
        .addProperty("CtrlParent", &GFeCtrlOffset_t::GetCtrlParent, &GFeCtrlOffset_t::SetCtrlParent)
        .addProperty("CtrlChild", &GFeCtrlOffset_t::GetCtrlChild, &GFeCtrlOffset_t::SetCtrlChild)
        .addFunction("ToPtr", &GFeCtrlOffset_t::ToPtr)
        .addFunction("IsValid", &GFeCtrlOffset_t::IsValid)
        .endClass();
}