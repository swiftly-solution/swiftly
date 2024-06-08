#include "../../../core/scripting/generated/classes/GFeRigidColliderIndices_t.h"
#include "../core.h"

void SetupLuaClassGFeRigidColliderIndices_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeRigidColliderIndices_t>("FeRigidColliderIndices_t")
        .addProperty("TaperedCapsuleRigidIndex", &GFeRigidColliderIndices_t::GetTaperedCapsuleRigidIndex, &GFeRigidColliderIndices_t::SetTaperedCapsuleRigidIndex)
        .addProperty("SphereRigidIndex", &GFeRigidColliderIndices_t::GetSphereRigidIndex, &GFeRigidColliderIndices_t::SetSphereRigidIndex)
        .addProperty("BoxRigidIndex", &GFeRigidColliderIndices_t::GetBoxRigidIndex, &GFeRigidColliderIndices_t::SetBoxRigidIndex)
        .addProperty("CollisionPlaneIndex", &GFeRigidColliderIndices_t::GetCollisionPlaneIndex, &GFeRigidColliderIndices_t::SetCollisionPlaneIndex)
        .endClass();
}