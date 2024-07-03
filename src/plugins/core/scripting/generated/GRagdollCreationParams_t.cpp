#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRagdollCreationParams_t::GRagdollCreationParams_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRagdollCreationParams_t::GRagdollCreationParams_t(void *ptr) {
    m_ptr = ptr;
}
Vector GRagdollCreationParams_t::GetForce() const {
    return GetSchemaValue<Vector>(m_ptr, "RagdollCreationParams_t", "m_vForce");
}
void GRagdollCreationParams_t::SetForce(Vector value) {
    SetSchemaValue(m_ptr, "RagdollCreationParams_t", "m_vForce", true, value);
}
int32_t GRagdollCreationParams_t::GetForceBone() const {
    return GetSchemaValue<int32_t>(m_ptr, "RagdollCreationParams_t", "m_nForceBone");
}
void GRagdollCreationParams_t::SetForceBone(int32_t value) {
    SetSchemaValue(m_ptr, "RagdollCreationParams_t", "m_nForceBone", true, value);
}
bool GRagdollCreationParams_t::GetForceCurrentWorldTransform() const {
    return GetSchemaValue<bool>(m_ptr, "RagdollCreationParams_t", "m_bForceCurrentWorldTransform");
}
void GRagdollCreationParams_t::SetForceCurrentWorldTransform(bool value) {
    SetSchemaValue(m_ptr, "RagdollCreationParams_t", "m_bForceCurrentWorldTransform", true, value);
}
std::string GRagdollCreationParams_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRagdollCreationParams_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRagdollCreationParams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRagdollCreationParams_t>("RagdollCreationParams_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Force", &GRagdollCreationParams_t::GetForce, &GRagdollCreationParams_t::SetForce)
        .addProperty("ForceBone", &GRagdollCreationParams_t::GetForceBone, &GRagdollCreationParams_t::SetForceBone)
        .addProperty("ForceCurrentWorldTransform", &GRagdollCreationParams_t::GetForceCurrentWorldTransform, &GRagdollCreationParams_t::SetForceCurrentWorldTransform)
        .addFunction("ToPtr", &GRagdollCreationParams_t::ToPtr)
        .addFunction("IsValid", &GRagdollCreationParams_t::IsValid)
        .endClass();
}