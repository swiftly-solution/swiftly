#include "../../../core/scripting/generated/classes/GVPhysXCollisionAttributes_t.h"
#include "../core.h"

void SetupLuaClassGVPhysXCollisionAttributes_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVPhysXCollisionAttributes_t>("VPhysXCollisionAttributes_t")
        .addProperty("CollisionGroup", &GVPhysXCollisionAttributes_t::GetCollisionGroup, &GVPhysXCollisionAttributes_t::SetCollisionGroup)
        .addProperty("InteractAs", &GVPhysXCollisionAttributes_t::GetInteractAs, &GVPhysXCollisionAttributes_t::SetInteractAs)
        .addProperty("InteractWith", &GVPhysXCollisionAttributes_t::GetInteractWith, &GVPhysXCollisionAttributes_t::SetInteractWith)
        .addProperty("InteractExclude", &GVPhysXCollisionAttributes_t::GetInteractExclude, &GVPhysXCollisionAttributes_t::SetInteractExclude)
        .addProperty("CollisionGroupString", &GVPhysXCollisionAttributes_t::GetCollisionGroupString, &GVPhysXCollisionAttributes_t::SetCollisionGroupString)
        .addProperty("InteractAsStrings", &GVPhysXCollisionAttributes_t::GetInteractAsStrings, &GVPhysXCollisionAttributes_t::SetInteractAsStrings)
        .addProperty("InteractWithStrings", &GVPhysXCollisionAttributes_t::GetInteractWithStrings, &GVPhysXCollisionAttributes_t::SetInteractWithStrings)
        .addProperty("InteractExcludeStrings", &GVPhysXCollisionAttributes_t::GetInteractExcludeStrings, &GVPhysXCollisionAttributes_t::SetInteractExcludeStrings)
        .endClass();
}