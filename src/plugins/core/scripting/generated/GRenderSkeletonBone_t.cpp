#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRenderSkeletonBone_t::GRenderSkeletonBone_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRenderSkeletonBone_t::GRenderSkeletonBone_t(void *ptr) {
    m_ptr = ptr;
}
std::string GRenderSkeletonBone_t::GetBoneName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "RenderSkeletonBone_t", "m_boneName").Get();
}
void GRenderSkeletonBone_t::SetBoneName(std::string value) {
    SetSchemaValue(m_ptr, "RenderSkeletonBone_t", "m_boneName", true, CUtlString(value.c_str()));
}
std::string GRenderSkeletonBone_t::GetParentName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "RenderSkeletonBone_t", "m_parentName").Get();
}
void GRenderSkeletonBone_t::SetParentName(std::string value) {
    SetSchemaValue(m_ptr, "RenderSkeletonBone_t", "m_parentName", true, CUtlString(value.c_str()));
}
matrix3x4_t GRenderSkeletonBone_t::GetInvBindPose() const {
    return GetSchemaValue<matrix3x4_t>(m_ptr, "RenderSkeletonBone_t", "m_invBindPose");
}
void GRenderSkeletonBone_t::SetInvBindPose(matrix3x4_t value) {
    SetSchemaValue(m_ptr, "RenderSkeletonBone_t", "m_invBindPose", true, value);
}
GSkeletonBoneBounds_t GRenderSkeletonBone_t::GetBbox() const {
    GSkeletonBoneBounds_t value(GetSchemaPtr(m_ptr, "RenderSkeletonBone_t", "m_bbox"));
    return value;
}
void GRenderSkeletonBone_t::SetBbox(GSkeletonBoneBounds_t value) {
    SetSchemaValue(m_ptr, "RenderSkeletonBone_t", "m_bbox", true, value);
}
float GRenderSkeletonBone_t::GetSphereRadius() const {
    return GetSchemaValue<float>(m_ptr, "RenderSkeletonBone_t", "m_flSphereRadius");
}
void GRenderSkeletonBone_t::SetSphereRadius(float value) {
    SetSchemaValue(m_ptr, "RenderSkeletonBone_t", "m_flSphereRadius", true, value);
}
std::string GRenderSkeletonBone_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRenderSkeletonBone_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRenderSkeletonBone_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRenderSkeletonBone_t>("RenderSkeletonBone_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BoneName", &GRenderSkeletonBone_t::GetBoneName, &GRenderSkeletonBone_t::SetBoneName)
        .addProperty("ParentName", &GRenderSkeletonBone_t::GetParentName, &GRenderSkeletonBone_t::SetParentName)
        .addProperty("InvBindPose", &GRenderSkeletonBone_t::GetInvBindPose, &GRenderSkeletonBone_t::SetInvBindPose)
        .addProperty("Bbox", &GRenderSkeletonBone_t::GetBbox, &GRenderSkeletonBone_t::SetBbox)
        .addProperty("SphereRadius", &GRenderSkeletonBone_t::GetSphereRadius, &GRenderSkeletonBone_t::SetSphereRadius)
        .addFunction("ToPtr", &GRenderSkeletonBone_t::ToPtr)
        .addFunction("IsValid", &GRenderSkeletonBone_t::IsValid)
        .endClass();
}