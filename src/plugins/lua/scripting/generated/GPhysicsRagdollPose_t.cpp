#include "../../../core/scripting/generated/classes/GPhysicsRagdollPose_t.h"
#include "../core.h"

void SetupLuaClassGPhysicsRagdollPose_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPhysicsRagdollPose_t>("PhysicsRagdollPose_t")
        .addProperty("__pChainEntity", &GPhysicsRagdollPose_t::Get__pChainEntity, &GPhysicsRagdollPose_t::Set__pChainEntity)
        .addProperty("Owner", &GPhysicsRagdollPose_t::GetOwner, &GPhysicsRagdollPose_t::SetOwner)
        .endClass();
}