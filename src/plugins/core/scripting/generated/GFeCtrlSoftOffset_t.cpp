#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeCtrlSoftOffset_t::GFeCtrlSoftOffset_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeCtrlSoftOffset_t::GFeCtrlSoftOffset_t(void *ptr) {
    m_ptr = ptr;
}
uint16_t GFeCtrlSoftOffset_t::GetCtrlParent() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeCtrlSoftOffset_t", "nCtrlParent");
}
void GFeCtrlSoftOffset_t::SetCtrlParent(uint16_t value) {
    SetSchemaValue(m_ptr, "FeCtrlSoftOffset_t", "nCtrlParent", true, value);
}
uint16_t GFeCtrlSoftOffset_t::GetCtrlChild() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeCtrlSoftOffset_t", "nCtrlChild");
}
void GFeCtrlSoftOffset_t::SetCtrlChild(uint16_t value) {
    SetSchemaValue(m_ptr, "FeCtrlSoftOffset_t", "nCtrlChild", true, value);
}
Vector GFeCtrlSoftOffset_t::GetOffset() const {
    return GetSchemaValue<Vector>(m_ptr, "FeCtrlSoftOffset_t", "vOffset");
}
void GFeCtrlSoftOffset_t::SetOffset(Vector value) {
    SetSchemaValue(m_ptr, "FeCtrlSoftOffset_t", "vOffset", true, value);
}
float GFeCtrlSoftOffset_t::GetAlpha() const {
    return GetSchemaValue<float>(m_ptr, "FeCtrlSoftOffset_t", "flAlpha");
}
void GFeCtrlSoftOffset_t::SetAlpha(float value) {
    SetSchemaValue(m_ptr, "FeCtrlSoftOffset_t", "flAlpha", true, value);
}
std::string GFeCtrlSoftOffset_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeCtrlSoftOffset_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeCtrlSoftOffset_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeCtrlSoftOffset_t>("FeCtrlSoftOffset_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CtrlParent", &GFeCtrlSoftOffset_t::GetCtrlParent, &GFeCtrlSoftOffset_t::SetCtrlParent)
        .addProperty("CtrlChild", &GFeCtrlSoftOffset_t::GetCtrlChild, &GFeCtrlSoftOffset_t::SetCtrlChild)
        .addProperty("Offset", &GFeCtrlSoftOffset_t::GetOffset, &GFeCtrlSoftOffset_t::SetOffset)
        .addProperty("Alpha", &GFeCtrlSoftOffset_t::GetAlpha, &GFeCtrlSoftOffset_t::SetAlpha)
        .addFunction("ToPtr", &GFeCtrlSoftOffset_t::ToPtr)
        .addFunction("IsValid", &GFeCtrlSoftOffset_t::IsValid)
        .endClass();
}