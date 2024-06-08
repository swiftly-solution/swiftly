#include "../../../core/scripting/generated/classes/GCPlayer_AutoaimServices.h"
#include "../core.h"

void SetupLuaClassGCPlayer_AutoaimServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_AutoaimServices>("CPlayer_AutoaimServices")

        .endClass();
}