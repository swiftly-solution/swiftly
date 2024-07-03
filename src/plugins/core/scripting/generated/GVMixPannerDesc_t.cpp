#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixPannerDesc_t::GVMixPannerDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixPannerDesc_t::GVMixPannerDesc_t(void *ptr) {
    m_ptr = ptr;
}
uint64_t GVMixPannerDesc_t::GetType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "VMixPannerDesc_t", "m_type");
}
void GVMixPannerDesc_t::SetType(uint64_t value) {
    SetSchemaValue(m_ptr, "VMixPannerDesc_t", "m_type", true, value);
}
float GVMixPannerDesc_t::GetStrength() const {
    return GetSchemaValue<float>(m_ptr, "VMixPannerDesc_t", "m_flStrength");
}
void GVMixPannerDesc_t::SetStrength(float value) {
    SetSchemaValue(m_ptr, "VMixPannerDesc_t", "m_flStrength", true, value);
}
std::string GVMixPannerDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixPannerDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixPannerDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixPannerDesc_t>("VMixPannerDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Type", &GVMixPannerDesc_t::GetType, &GVMixPannerDesc_t::SetType)
        .addProperty("Strength", &GVMixPannerDesc_t::GetStrength, &GVMixPannerDesc_t::SetStrength)
        .addFunction("ToPtr", &GVMixPannerDesc_t::ToPtr)
        .addFunction("IsValid", &GVMixPannerDesc_t::IsValid)
        .endClass();
}