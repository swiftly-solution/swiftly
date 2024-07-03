#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSkeletonInstance::GCSkeletonInstance(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSkeletonInstance::GCSkeletonInstance(void *ptr) {
    m_ptr = ptr;
}
GCModelState GCSkeletonInstance::GetModelState() const {
    GCModelState value(GetSchemaPtr(m_ptr, "CSkeletonInstance", "m_modelState"));
    return value;
}
void GCSkeletonInstance::SetModelState(GCModelState value) {
    SetSchemaValue(m_ptr, "CSkeletonInstance", "m_modelState", false, value);
}
bool GCSkeletonInstance::GetIsAnimationEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CSkeletonInstance", "m_bIsAnimationEnabled");
}
void GCSkeletonInstance::SetIsAnimationEnabled(bool value) {
    SetSchemaValue(m_ptr, "CSkeletonInstance", "m_bIsAnimationEnabled", false, value);
}
bool GCSkeletonInstance::GetUseParentRenderBounds() const {
    return GetSchemaValue<bool>(m_ptr, "CSkeletonInstance", "m_bUseParentRenderBounds");
}
void GCSkeletonInstance::SetUseParentRenderBounds(bool value) {
    SetSchemaValue(m_ptr, "CSkeletonInstance", "m_bUseParentRenderBounds", false, value);
}
bool GCSkeletonInstance::GetDisableSolidCollisionsForHierarchy() const {
    return GetSchemaValue<bool>(m_ptr, "CSkeletonInstance", "m_bDisableSolidCollisionsForHierarchy");
}
void GCSkeletonInstance::SetDisableSolidCollisionsForHierarchy(bool value) {
    SetSchemaValue(m_ptr, "CSkeletonInstance", "m_bDisableSolidCollisionsForHierarchy", false, value);
}
CUtlStringToken GCSkeletonInstance::GetMaterialGroup() const {
    return GetSchemaValue<CUtlStringToken>(m_ptr, "CSkeletonInstance", "m_materialGroup");
}
void GCSkeletonInstance::SetMaterialGroup(CUtlStringToken value) {
    SetSchemaValue(m_ptr, "CSkeletonInstance", "m_materialGroup", false, value);
}
uint8_t GCSkeletonInstance::GetHitboxSet() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CSkeletonInstance", "m_nHitboxSet");
}
void GCSkeletonInstance::SetHitboxSet(uint8_t value) {
    SetSchemaValue(m_ptr, "CSkeletonInstance", "m_nHitboxSet", false, value);
}
std::string GCSkeletonInstance::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSkeletonInstance::IsValid() {
    return (m_ptr != nullptr);
}
GCGameSceneNode GCSkeletonInstance::GetParent() const {
    GCGameSceneNode value(m_ptr);
    return value;
}
void GCSkeletonInstance::SetParent(GCGameSceneNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSkeletonInstance(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSkeletonInstance>("CSkeletonInstance")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ModelState", &GCSkeletonInstance::GetModelState, &GCSkeletonInstance::SetModelState)
        .addProperty("IsAnimationEnabled", &GCSkeletonInstance::GetIsAnimationEnabled, &GCSkeletonInstance::SetIsAnimationEnabled)
        .addProperty("UseParentRenderBounds", &GCSkeletonInstance::GetUseParentRenderBounds, &GCSkeletonInstance::SetUseParentRenderBounds)
        .addProperty("DisableSolidCollisionsForHierarchy", &GCSkeletonInstance::GetDisableSolidCollisionsForHierarchy, &GCSkeletonInstance::SetDisableSolidCollisionsForHierarchy)
        .addProperty("MaterialGroup", &GCSkeletonInstance::GetMaterialGroup, &GCSkeletonInstance::SetMaterialGroup)
        .addProperty("HitboxSet", &GCSkeletonInstance::GetHitboxSet, &GCSkeletonInstance::SetHitboxSet)
        .addProperty("Parent", &GCSkeletonInstance::GetParent, &GCSkeletonInstance::SetParent)
        .addFunction("ToPtr", &GCSkeletonInstance::ToPtr)
        .addFunction("IsValid", &GCSkeletonInstance::IsValid)
        .endClass();
}