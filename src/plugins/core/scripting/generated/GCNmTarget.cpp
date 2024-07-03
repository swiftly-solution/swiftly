#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmTarget::GCNmTarget(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmTarget::GCNmTarget(void *ptr) {
    m_ptr = ptr;
}
bool GCNmTarget::GetIsBoneTarget() const {
    return GetSchemaValue<bool>(m_ptr, "CNmTarget", "m_bIsBoneTarget");
}
void GCNmTarget::SetIsBoneTarget(bool value) {
    SetSchemaValue(m_ptr, "CNmTarget", "m_bIsBoneTarget", false, value);
}
bool GCNmTarget::GetIsUsingBoneSpaceOffsets() const {
    return GetSchemaValue<bool>(m_ptr, "CNmTarget", "m_bIsUsingBoneSpaceOffsets");
}
void GCNmTarget::SetIsUsingBoneSpaceOffsets(bool value) {
    SetSchemaValue(m_ptr, "CNmTarget", "m_bIsUsingBoneSpaceOffsets", false, value);
}
bool GCNmTarget::GetHasOffsets() const {
    return GetSchemaValue<bool>(m_ptr, "CNmTarget", "m_bHasOffsets");
}
void GCNmTarget::SetHasOffsets(bool value) {
    SetSchemaValue(m_ptr, "CNmTarget", "m_bHasOffsets", false, value);
}
bool GCNmTarget::GetIsSet() const {
    return GetSchemaValue<bool>(m_ptr, "CNmTarget", "m_bIsSet");
}
void GCNmTarget::SetIsSet(bool value) {
    SetSchemaValue(m_ptr, "CNmTarget", "m_bIsSet", false, value);
}
std::string GCNmTarget::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmTarget::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNmTarget(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmTarget>("CNmTarget")
        .addConstructor<void (*)(std::string)>()
        .addProperty("IsBoneTarget", &GCNmTarget::GetIsBoneTarget, &GCNmTarget::SetIsBoneTarget)
        .addProperty("IsUsingBoneSpaceOffsets", &GCNmTarget::GetIsUsingBoneSpaceOffsets, &GCNmTarget::SetIsUsingBoneSpaceOffsets)
        .addProperty("HasOffsets", &GCNmTarget::GetHasOffsets, &GCNmTarget::SetHasOffsets)
        .addProperty("IsSet", &GCNmTarget::GetIsSet, &GCNmTarget::SetIsSet)
        .addFunction("ToPtr", &GCNmTarget::ToPtr)
        .addFunction("IsValid", &GCNmTarget::IsValid)
        .endClass();
}