#include "../../../core/scripting/generated/classes/GCPlayer_WaterServices.h"
#include "../core.h"

void SetupLuaClassGCPlayer_WaterServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_WaterServices>("CPlayer_WaterServices")

        .endClass();
}