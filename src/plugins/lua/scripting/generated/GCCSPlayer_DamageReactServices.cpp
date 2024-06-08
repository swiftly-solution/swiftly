#include "../../../core/scripting/generated/classes/GCCSPlayer_DamageReactServices.h"
#include "../core.h"

void SetupLuaClassGCCSPlayer_DamageReactServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_DamageReactServices>("CCSPlayer_DamageReactServices")

        .endClass();
}