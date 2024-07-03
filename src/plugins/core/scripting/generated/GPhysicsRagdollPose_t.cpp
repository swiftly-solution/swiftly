#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GPhysicsRagdollPose_t::GPhysicsRagdollPose_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GPhysicsRagdollPose_t::GPhysicsRagdollPose_t(void *ptr) {
    m_ptr = ptr;
}
GCNetworkVarChainer GPhysicsRagdollPose_t::Get__pChainEntity() const {
    GCNetworkVarChainer value(GetSchemaPtr(m_ptr, "PhysicsRagdollPose_t", "__m_pChainEntity"));
    return value;
}
void GPhysicsRagdollPose_t::Set__pChainEntity(GCNetworkVarChainer value) {
    SetSchemaValue(m_ptr, "PhysicsRagdollPose_t", "__m_pChainEntity", true, value);
}
GCBaseEntity GPhysicsRagdollPose_t::GetOwner() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "PhysicsRagdollPose_t", "m_hOwner"));
    return value;
}
void GPhysicsRagdollPose_t::SetOwner(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Owner' is not possible.\n");
}
std::string GPhysicsRagdollPose_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GPhysicsRagdollPose_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassPhysicsRagdollPose_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPhysicsRagdollPose_t>("PhysicsRagdollPose_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("__pChainEntity", &GPhysicsRagdollPose_t::Get__pChainEntity, &GPhysicsRagdollPose_t::Set__pChainEntity)
        .addProperty("Owner", &GPhysicsRagdollPose_t::GetOwner, &GPhysicsRagdollPose_t::SetOwner)
        .addFunction("ToPtr", &GPhysicsRagdollPose_t::ToPtr)
        .addFunction("IsValid", &GPhysicsRagdollPose_t::IsValid)
        .endClass();
}