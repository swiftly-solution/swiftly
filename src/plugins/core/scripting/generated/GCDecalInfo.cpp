#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDecalInfo::GCDecalInfo(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDecalInfo::GCDecalInfo(void *ptr) {
    m_ptr = ptr;
}
float GCDecalInfo::GetAnimationScale() const {
    return GetSchemaValue<float>(m_ptr, "CDecalInfo", "m_flAnimationScale");
}
void GCDecalInfo::SetAnimationScale(float value) {
    SetSchemaValue(m_ptr, "CDecalInfo", "m_flAnimationScale", false, value);
}
float GCDecalInfo::GetAnimationLifeSpan() const {
    return GetSchemaValue<float>(m_ptr, "CDecalInfo", "m_flAnimationLifeSpan");
}
void GCDecalInfo::SetAnimationLifeSpan(float value) {
    SetSchemaValue(m_ptr, "CDecalInfo", "m_flAnimationLifeSpan", false, value);
}
float GCDecalInfo::GetPlaceTime() const {
    return GetSchemaValue<float>(m_ptr, "CDecalInfo", "m_flPlaceTime");
}
void GCDecalInfo::SetPlaceTime(float value) {
    SetSchemaValue(m_ptr, "CDecalInfo", "m_flPlaceTime", false, value);
}
float GCDecalInfo::GetFadeStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CDecalInfo", "m_flFadeStartTime");
}
void GCDecalInfo::SetFadeStartTime(float value) {
    SetSchemaValue(m_ptr, "CDecalInfo", "m_flFadeStartTime", false, value);
}
float GCDecalInfo::GetFadeDuration() const {
    return GetSchemaValue<float>(m_ptr, "CDecalInfo", "m_flFadeDuration");
}
void GCDecalInfo::SetFadeDuration(float value) {
    SetSchemaValue(m_ptr, "CDecalInfo", "m_flFadeDuration", false, value);
}
int32_t GCDecalInfo::GetVBSlot() const {
    return GetSchemaValue<int32_t>(m_ptr, "CDecalInfo", "m_nVBSlot");
}
void GCDecalInfo::SetVBSlot(int32_t value) {
    SetSchemaValue(m_ptr, "CDecalInfo", "m_nVBSlot", false, value);
}
int32_t GCDecalInfo::GetBoneIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CDecalInfo", "m_nBoneIndex");
}
void GCDecalInfo::SetBoneIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CDecalInfo", "m_nBoneIndex", false, value);
}
Vector GCDecalInfo::GetPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CDecalInfo", "m_vPosition");
}
void GCDecalInfo::SetPosition(Vector value) {
    SetSchemaValue(m_ptr, "CDecalInfo", "m_vPosition", false, value);
}
float GCDecalInfo::GetBoundingRadiusSqr() const {
    return GetSchemaValue<float>(m_ptr, "CDecalInfo", "m_flBoundingRadiusSqr");
}
void GCDecalInfo::SetBoundingRadiusSqr(float value) {
    SetSchemaValue(m_ptr, "CDecalInfo", "m_flBoundingRadiusSqr", false, value);
}
GCDecalInfo GCDecalInfo::GetNext() const {
    GCDecalInfo value(*GetSchemaValuePtr<void*>(m_ptr, "CDecalInfo", "m_pNext"));
    return value;
}
void GCDecalInfo::SetNext(GCDecalInfo* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Next' is not possible.\n");
}
GCDecalInfo GCDecalInfo::GetPrev() const {
    GCDecalInfo value(*GetSchemaValuePtr<void*>(m_ptr, "CDecalInfo", "m_pPrev"));
    return value;
}
void GCDecalInfo::SetPrev(GCDecalInfo* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Prev' is not possible.\n");
}
int32_t GCDecalInfo::GetDecalMaterialIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CDecalInfo", "m_nDecalMaterialIndex");
}
void GCDecalInfo::SetDecalMaterialIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CDecalInfo", "m_nDecalMaterialIndex", false, value);
}
std::string GCDecalInfo::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDecalInfo::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCDecalInfo(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDecalInfo>("CDecalInfo")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AnimationScale", &GCDecalInfo::GetAnimationScale, &GCDecalInfo::SetAnimationScale)
        .addProperty("AnimationLifeSpan", &GCDecalInfo::GetAnimationLifeSpan, &GCDecalInfo::SetAnimationLifeSpan)
        .addProperty("PlaceTime", &GCDecalInfo::GetPlaceTime, &GCDecalInfo::SetPlaceTime)
        .addProperty("FadeStartTime", &GCDecalInfo::GetFadeStartTime, &GCDecalInfo::SetFadeStartTime)
        .addProperty("FadeDuration", &GCDecalInfo::GetFadeDuration, &GCDecalInfo::SetFadeDuration)
        .addProperty("VBSlot", &GCDecalInfo::GetVBSlot, &GCDecalInfo::SetVBSlot)
        .addProperty("BoneIndex", &GCDecalInfo::GetBoneIndex, &GCDecalInfo::SetBoneIndex)
        .addProperty("Position", &GCDecalInfo::GetPosition, &GCDecalInfo::SetPosition)
        .addProperty("BoundingRadiusSqr", &GCDecalInfo::GetBoundingRadiusSqr, &GCDecalInfo::SetBoundingRadiusSqr)
        .addProperty("Next", &GCDecalInfo::GetNext, &GCDecalInfo::SetNext)
        .addProperty("Prev", &GCDecalInfo::GetPrev, &GCDecalInfo::SetPrev)
        .addProperty("DecalMaterialIndex", &GCDecalInfo::GetDecalMaterialIndex, &GCDecalInfo::SetDecalMaterialIndex)
        .addFunction("ToPtr", &GCDecalInfo::ToPtr)
        .addFunction("IsValid", &GCDecalInfo::IsValid)
        .endClass();
}