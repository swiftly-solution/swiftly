#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBoneConstraintDotToMorph::GCBoneConstraintDotToMorph(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBoneConstraintDotToMorph::GCBoneConstraintDotToMorph(void *ptr) {
    m_ptr = ptr;
}
std::string GCBoneConstraintDotToMorph::GetBoneName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CBoneConstraintDotToMorph", "m_sBoneName").Get();
}
void GCBoneConstraintDotToMorph::SetBoneName(std::string value) {
    SetSchemaValue(m_ptr, "CBoneConstraintDotToMorph", "m_sBoneName", false, CUtlString(value.c_str()));
}
std::string GCBoneConstraintDotToMorph::GetTargetBoneName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CBoneConstraintDotToMorph", "m_sTargetBoneName").Get();
}
void GCBoneConstraintDotToMorph::SetTargetBoneName(std::string value) {
    SetSchemaValue(m_ptr, "CBoneConstraintDotToMorph", "m_sTargetBoneName", false, CUtlString(value.c_str()));
}
std::string GCBoneConstraintDotToMorph::GetMorphChannelName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CBoneConstraintDotToMorph", "m_sMorphChannelName").Get();
}
void GCBoneConstraintDotToMorph::SetMorphChannelName(std::string value) {
    SetSchemaValue(m_ptr, "CBoneConstraintDotToMorph", "m_sMorphChannelName", false, CUtlString(value.c_str()));
}
std::vector<float> GCBoneConstraintDotToMorph::GetRemap() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CBoneConstraintDotToMorph", "m_flRemap"); std::vector<float> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCBoneConstraintDotToMorph::SetRemap(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CBoneConstraintDotToMorph", "m_flRemap"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CBoneConstraintDotToMorph", "m_flRemap", false, outValue);
}
std::string GCBoneConstraintDotToMorph::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBoneConstraintDotToMorph::IsValid() {
    return (m_ptr != nullptr);
}
GCBoneConstraintBase GCBoneConstraintDotToMorph::GetParent() const {
    GCBoneConstraintBase value(m_ptr);
    return value;
}
void GCBoneConstraintDotToMorph::SetParent(GCBoneConstraintBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBoneConstraintDotToMorph(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBoneConstraintDotToMorph>("CBoneConstraintDotToMorph")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BoneName", &GCBoneConstraintDotToMorph::GetBoneName, &GCBoneConstraintDotToMorph::SetBoneName)
        .addProperty("TargetBoneName", &GCBoneConstraintDotToMorph::GetTargetBoneName, &GCBoneConstraintDotToMorph::SetTargetBoneName)
        .addProperty("MorphChannelName", &GCBoneConstraintDotToMorph::GetMorphChannelName, &GCBoneConstraintDotToMorph::SetMorphChannelName)
        .addProperty("Remap", &GCBoneConstraintDotToMorph::GetRemap, &GCBoneConstraintDotToMorph::SetRemap)
        .addProperty("Parent", &GCBoneConstraintDotToMorph::GetParent, &GCBoneConstraintDotToMorph::SetParent)
        .addFunction("ToPtr", &GCBoneConstraintDotToMorph::ToPtr)
        .addFunction("IsValid", &GCBoneConstraintDotToMorph::IsValid)
        .endClass();
}