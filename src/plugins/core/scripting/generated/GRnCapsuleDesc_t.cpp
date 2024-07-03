#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRnCapsuleDesc_t::GRnCapsuleDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRnCapsuleDesc_t::GRnCapsuleDesc_t(void *ptr) {
    m_ptr = ptr;
}
GRnCapsule_t GRnCapsuleDesc_t::GetCapsule() const {
    GRnCapsule_t value(GetSchemaPtr(m_ptr, "RnCapsuleDesc_t", "m_Capsule"));
    return value;
}
void GRnCapsuleDesc_t::SetCapsule(GRnCapsule_t value) {
    SetSchemaValue(m_ptr, "RnCapsuleDesc_t", "m_Capsule", true, value);
}
std::string GRnCapsuleDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRnCapsuleDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
GRnShapeDesc_t GRnCapsuleDesc_t::GetParent() const {
    GRnShapeDesc_t value(m_ptr);
    return value;
}
void GRnCapsuleDesc_t::SetParent(GRnShapeDesc_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassRnCapsuleDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnCapsuleDesc_t>("RnCapsuleDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Capsule", &GRnCapsuleDesc_t::GetCapsule, &GRnCapsuleDesc_t::SetCapsule)
        .addProperty("Parent", &GRnCapsuleDesc_t::GetParent, &GRnCapsuleDesc_t::SetParent)
        .addFunction("ToPtr", &GRnCapsuleDesc_t::ToPtr)
        .addFunction("IsValid", &GRnCapsuleDesc_t::IsValid)
        .endClass();
}