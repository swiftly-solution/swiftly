#include "../../../core/scripting/generated/classes/GVPhysicsCollisionAttribute_t.h"
#include "../core.h"

void SetupLuaClassGVPhysicsCollisionAttribute_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVPhysicsCollisionAttribute_t>("VPhysicsCollisionAttribute_t")
        .addProperty("InteractsAs", &GVPhysicsCollisionAttribute_t::GetInteractsAs, &GVPhysicsCollisionAttribute_t::SetInteractsAs)
        .addProperty("InteractsWith", &GVPhysicsCollisionAttribute_t::GetInteractsWith, &GVPhysicsCollisionAttribute_t::SetInteractsWith)
        .addProperty("InteractsExclude", &GVPhysicsCollisionAttribute_t::GetInteractsExclude, &GVPhysicsCollisionAttribute_t::SetInteractsExclude)
        .addProperty("EntityId", &GVPhysicsCollisionAttribute_t::GetEntityId, &GVPhysicsCollisionAttribute_t::SetEntityId)
        .addProperty("OwnerId", &GVPhysicsCollisionAttribute_t::GetOwnerId, &GVPhysicsCollisionAttribute_t::SetOwnerId)
        .addProperty("HierarchyId", &GVPhysicsCollisionAttribute_t::GetHierarchyId, &GVPhysicsCollisionAttribute_t::SetHierarchyId)
        .addProperty("CollisionGroup", &GVPhysicsCollisionAttribute_t::GetCollisionGroup, &GVPhysicsCollisionAttribute_t::SetCollisionGroup)
        .addProperty("CollisionFunctionMask", &GVPhysicsCollisionAttribute_t::GetCollisionFunctionMask, &GVPhysicsCollisionAttribute_t::SetCollisionFunctionMask)
        .endClass();
}