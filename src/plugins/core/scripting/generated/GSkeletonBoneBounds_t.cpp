#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSkeletonBoneBounds_t::GSkeletonBoneBounds_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSkeletonBoneBounds_t::GSkeletonBoneBounds_t(void *ptr) {
    m_ptr = ptr;
}
Vector GSkeletonBoneBounds_t::GetCenter() const {
    return GetSchemaValue<Vector>(m_ptr, "SkeletonBoneBounds_t", "m_vecCenter");
}
void GSkeletonBoneBounds_t::SetCenter(Vector value) {
    SetSchemaValue(m_ptr, "SkeletonBoneBounds_t", "m_vecCenter", true, value);
}
Vector GSkeletonBoneBounds_t::GetSize() const {
    return GetSchemaValue<Vector>(m_ptr, "SkeletonBoneBounds_t", "m_vecSize");
}
void GSkeletonBoneBounds_t::SetSize(Vector value) {
    SetSchemaValue(m_ptr, "SkeletonBoneBounds_t", "m_vecSize", true, value);
}
std::string GSkeletonBoneBounds_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSkeletonBoneBounds_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSkeletonBoneBounds_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSkeletonBoneBounds_t>("SkeletonBoneBounds_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Center", &GSkeletonBoneBounds_t::GetCenter, &GSkeletonBoneBounds_t::SetCenter)
        .addProperty("Size", &GSkeletonBoneBounds_t::GetSize, &GSkeletonBoneBounds_t::SetSize)
        .addFunction("ToPtr", &GSkeletonBoneBounds_t::ToPtr)
        .addFunction("IsValid", &GSkeletonBoneBounds_t::IsValid)
        .endClass();
}