#include "../../../core/scripting/generated/classes/GCBasePlayerControllerAPI.h"
#include "../core.h"

void SetupLuaClassGCBasePlayerControllerAPI(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBasePlayerControllerAPI>("CBasePlayerControllerAPI")

        .endClass();
}