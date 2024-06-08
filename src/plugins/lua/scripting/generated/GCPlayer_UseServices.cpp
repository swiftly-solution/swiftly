#include "../../../core/scripting/generated/classes/GCPlayer_UseServices.h"
#include "../core.h"

void SetupLuaClassGCPlayer_UseServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_UseServices>("CPlayer_UseServices")

        .endClass();
}