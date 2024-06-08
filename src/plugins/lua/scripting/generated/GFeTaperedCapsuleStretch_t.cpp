#include "../../../core/scripting/generated/classes/GFeTaperedCapsuleStretch_t.h"
#include "../core.h"

void SetupLuaClassGFeTaperedCapsuleStretch_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeTaperedCapsuleStretch_t>("FeTaperedCapsuleStretch_t")
        .addProperty("Node", &GFeTaperedCapsuleStretch_t::GetNode, &GFeTaperedCapsuleStretch_t::SetNode)
        .addProperty("CollisionMask", &GFeTaperedCapsuleStretch_t::GetCollisionMask, &GFeTaperedCapsuleStretch_t::SetCollisionMask)
        .addProperty("Dummy", &GFeTaperedCapsuleStretch_t::GetDummy, &GFeTaperedCapsuleStretch_t::SetDummy)
        .addProperty("Radius", &GFeTaperedCapsuleStretch_t::GetRadius, &GFeTaperedCapsuleStretch_t::SetRadius)
        .endClass();
}