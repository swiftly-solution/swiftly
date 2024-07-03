#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GModelBoneFlexDriver_t::GModelBoneFlexDriver_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GModelBoneFlexDriver_t::GModelBoneFlexDriver_t(void *ptr) {
    m_ptr = ptr;
}
std::string GModelBoneFlexDriver_t::GetBoneName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "ModelBoneFlexDriver_t", "m_boneName").Get();
}
void GModelBoneFlexDriver_t::SetBoneName(std::string value) {
    SetSchemaValue(m_ptr, "ModelBoneFlexDriver_t", "m_boneName", true, CUtlString(value.c_str()));
}
uint32_t GModelBoneFlexDriver_t::GetBoneNameToken() const {
    return GetSchemaValue<uint32_t>(m_ptr, "ModelBoneFlexDriver_t", "m_boneNameToken");
}
void GModelBoneFlexDriver_t::SetBoneNameToken(uint32_t value) {
    SetSchemaValue(m_ptr, "ModelBoneFlexDriver_t", "m_boneNameToken", true, value);
}
std::vector<GModelBoneFlexDriverControl_t> GModelBoneFlexDriver_t::GetControls() const {
    CUtlVector<GModelBoneFlexDriverControl_t>* vec = GetSchemaValue<CUtlVector<GModelBoneFlexDriverControl_t>*>(m_ptr, "ModelBoneFlexDriver_t", "m_controls"); std::vector<GModelBoneFlexDriverControl_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GModelBoneFlexDriver_t::SetControls(std::vector<GModelBoneFlexDriverControl_t> value) {
    SetSchemaValueCUtlVector<GModelBoneFlexDriverControl_t>(m_ptr, "ModelBoneFlexDriver_t", "m_controls", true, value);
}
std::string GModelBoneFlexDriver_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GModelBoneFlexDriver_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassModelBoneFlexDriver_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GModelBoneFlexDriver_t>("ModelBoneFlexDriver_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BoneName", &GModelBoneFlexDriver_t::GetBoneName, &GModelBoneFlexDriver_t::SetBoneName)
        .addProperty("BoneNameToken", &GModelBoneFlexDriver_t::GetBoneNameToken, &GModelBoneFlexDriver_t::SetBoneNameToken)
        .addProperty("Controls", &GModelBoneFlexDriver_t::GetControls, &GModelBoneFlexDriver_t::SetControls)
        .addFunction("ToPtr", &GModelBoneFlexDriver_t::ToPtr)
        .addFunction("IsValid", &GModelBoneFlexDriver_t::IsValid)
        .endClass();
}