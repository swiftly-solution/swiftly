#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GModelBoneFlexDriverControl_t::GModelBoneFlexDriverControl_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GModelBoneFlexDriverControl_t::GModelBoneFlexDriverControl_t(void *ptr) {
    m_ptr = ptr;
}
uint64_t GModelBoneFlexDriverControl_t::GetBoneComponent() const {
    return GetSchemaValue<uint64_t>(m_ptr, "ModelBoneFlexDriverControl_t", "m_nBoneComponent");
}
void GModelBoneFlexDriverControl_t::SetBoneComponent(uint64_t value) {
    SetSchemaValue(m_ptr, "ModelBoneFlexDriverControl_t", "m_nBoneComponent", true, value);
}
std::string GModelBoneFlexDriverControl_t::GetFlexController() const {
    return GetSchemaValue<CUtlString>(m_ptr, "ModelBoneFlexDriverControl_t", "m_flexController").Get();
}
void GModelBoneFlexDriverControl_t::SetFlexController(std::string value) {
    SetSchemaValue(m_ptr, "ModelBoneFlexDriverControl_t", "m_flexController", true, CUtlString(value.c_str()));
}
uint32_t GModelBoneFlexDriverControl_t::GetFlexControllerToken() const {
    return GetSchemaValue<uint32_t>(m_ptr, "ModelBoneFlexDriverControl_t", "m_flexControllerToken");
}
void GModelBoneFlexDriverControl_t::SetFlexControllerToken(uint32_t value) {
    SetSchemaValue(m_ptr, "ModelBoneFlexDriverControl_t", "m_flexControllerToken", true, value);
}
float GModelBoneFlexDriverControl_t::GetMin() const {
    return GetSchemaValue<float>(m_ptr, "ModelBoneFlexDriverControl_t", "m_flMin");
}
void GModelBoneFlexDriverControl_t::SetMin(float value) {
    SetSchemaValue(m_ptr, "ModelBoneFlexDriverControl_t", "m_flMin", true, value);
}
float GModelBoneFlexDriverControl_t::GetMax() const {
    return GetSchemaValue<float>(m_ptr, "ModelBoneFlexDriverControl_t", "m_flMax");
}
void GModelBoneFlexDriverControl_t::SetMax(float value) {
    SetSchemaValue(m_ptr, "ModelBoneFlexDriverControl_t", "m_flMax", true, value);
}
std::string GModelBoneFlexDriverControl_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GModelBoneFlexDriverControl_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassModelBoneFlexDriverControl_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GModelBoneFlexDriverControl_t>("ModelBoneFlexDriverControl_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BoneComponent", &GModelBoneFlexDriverControl_t::GetBoneComponent, &GModelBoneFlexDriverControl_t::SetBoneComponent)
        .addProperty("FlexController", &GModelBoneFlexDriverControl_t::GetFlexController, &GModelBoneFlexDriverControl_t::SetFlexController)
        .addProperty("FlexControllerToken", &GModelBoneFlexDriverControl_t::GetFlexControllerToken, &GModelBoneFlexDriverControl_t::SetFlexControllerToken)
        .addProperty("Min", &GModelBoneFlexDriverControl_t::GetMin, &GModelBoneFlexDriverControl_t::SetMin)
        .addProperty("Max", &GModelBoneFlexDriverControl_t::GetMax, &GModelBoneFlexDriverControl_t::SetMax)
        .addFunction("ToPtr", &GModelBoneFlexDriverControl_t::ToPtr)
        .addFunction("IsValid", &GModelBoneFlexDriverControl_t::IsValid)
        .endClass();
}