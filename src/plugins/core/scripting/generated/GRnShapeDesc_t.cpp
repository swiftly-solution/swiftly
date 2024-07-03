#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRnShapeDesc_t::GRnShapeDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRnShapeDesc_t::GRnShapeDesc_t(void *ptr) {
    m_ptr = ptr;
}
uint32_t GRnShapeDesc_t::GetCollisionAttributeIndex() const {
    return GetSchemaValue<uint32_t>(m_ptr, "RnShapeDesc_t", "m_nCollisionAttributeIndex");
}
void GRnShapeDesc_t::SetCollisionAttributeIndex(uint32_t value) {
    SetSchemaValue(m_ptr, "RnShapeDesc_t", "m_nCollisionAttributeIndex", true, value);
}
uint32_t GRnShapeDesc_t::GetSurfacePropertyIndex() const {
    return GetSchemaValue<uint32_t>(m_ptr, "RnShapeDesc_t", "m_nSurfacePropertyIndex");
}
void GRnShapeDesc_t::SetSurfacePropertyIndex(uint32_t value) {
    SetSchemaValue(m_ptr, "RnShapeDesc_t", "m_nSurfacePropertyIndex", true, value);
}
std::string GRnShapeDesc_t::GetUserFriendlyName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "RnShapeDesc_t", "m_UserFriendlyName").Get();
}
void GRnShapeDesc_t::SetUserFriendlyName(std::string value) {
    SetSchemaValue(m_ptr, "RnShapeDesc_t", "m_UserFriendlyName", true, CUtlString(value.c_str()));
}
std::string GRnShapeDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRnShapeDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRnShapeDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnShapeDesc_t>("RnShapeDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CollisionAttributeIndex", &GRnShapeDesc_t::GetCollisionAttributeIndex, &GRnShapeDesc_t::SetCollisionAttributeIndex)
        .addProperty("SurfacePropertyIndex", &GRnShapeDesc_t::GetSurfacePropertyIndex, &GRnShapeDesc_t::SetSurfacePropertyIndex)
        .addProperty("UserFriendlyName", &GRnShapeDesc_t::GetUserFriendlyName, &GRnShapeDesc_t::SetUserFriendlyName)
        .addFunction("ToPtr", &GRnShapeDesc_t::ToPtr)
        .addFunction("IsValid", &GRnShapeDesc_t::IsValid)
        .endClass();
}