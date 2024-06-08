#include "../../../core/scripting/generated/classes/GCollisionGroupContext_t.h"
#include "../core.h"

void SetupLuaClassGCollisionGroupContext_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCollisionGroupContext_t>("CollisionGroupContext_t")
        .addProperty("CollisionGroupNumber", &GCollisionGroupContext_t::GetCollisionGroupNumber, &GCollisionGroupContext_t::SetCollisionGroupNumber)
        .endClass();
}