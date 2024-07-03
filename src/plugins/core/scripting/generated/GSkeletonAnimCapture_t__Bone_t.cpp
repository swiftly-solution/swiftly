#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSkeletonAnimCapture_t__Bone_t::GSkeletonAnimCapture_t__Bone_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSkeletonAnimCapture_t__Bone_t::GSkeletonAnimCapture_t__Bone_t(void *ptr) {
    m_ptr = ptr;
}
std::string GSkeletonAnimCapture_t__Bone_t::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "SkeletonAnimCapture_t__Bone_t", "m_Name").Get();
}
void GSkeletonAnimCapture_t__Bone_t::SetName(std::string value) {
    SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__Bone_t", "m_Name", true, CUtlString(value.c_str()));
}
int32_t GSkeletonAnimCapture_t__Bone_t::GetParent() const {
    return GetSchemaValue<int32_t>(m_ptr, "SkeletonAnimCapture_t__Bone_t", "m_nParent");
}
void GSkeletonAnimCapture_t__Bone_t::SetParent(int32_t value) {
    SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__Bone_t", "m_nParent", true, value);
}
std::string GSkeletonAnimCapture_t__Bone_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSkeletonAnimCapture_t__Bone_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSkeletonAnimCapture_t__Bone_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSkeletonAnimCapture_t__Bone_t>("SkeletonAnimCapture_t__Bone_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GSkeletonAnimCapture_t__Bone_t::GetName, &GSkeletonAnimCapture_t__Bone_t::SetName)
        .addProperty("Parent", &GSkeletonAnimCapture_t__Bone_t::GetParent, &GSkeletonAnimCapture_t__Bone_t::SetParent)
        .addFunction("ToPtr", &GSkeletonAnimCapture_t__Bone_t::ToPtr)
        .addFunction("IsValid", &GSkeletonAnimCapture_t__Bone_t::IsValid)
        .endClass();
}