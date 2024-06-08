#include "../../../core/scripting/generated/classes/GFeTaperedCapsuleRigid_t.h"
#include "../core.h"

void SetupLuaClassGFeTaperedCapsuleRigid_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeTaperedCapsuleRigid_t>("FeTaperedCapsuleRigid_t")
        .addProperty("Sphere", &GFeTaperedCapsuleRigid_t::GetSphere, &GFeTaperedCapsuleRigid_t::SetSphere)
        .addProperty("Node", &GFeTaperedCapsuleRigid_t::GetNode, &GFeTaperedCapsuleRigid_t::SetNode)
        .addProperty("CollisionMask", &GFeTaperedCapsuleRigid_t::GetCollisionMask, &GFeTaperedCapsuleRigid_t::SetCollisionMask)
        .addProperty("VertexMapIndex", &GFeTaperedCapsuleRigid_t::GetVertexMapIndex, &GFeTaperedCapsuleRigid_t::SetVertexMapIndex)
        .addProperty("Flags", &GFeTaperedCapsuleRigid_t::GetFlags, &GFeTaperedCapsuleRigid_t::SetFlags)
        .endClass();
}