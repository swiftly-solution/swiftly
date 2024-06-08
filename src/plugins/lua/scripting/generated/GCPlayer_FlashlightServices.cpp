#include "../../../core/scripting/generated/classes/GCPlayer_FlashlightServices.h"
#include "../core.h"

void SetupLuaClassGCPlayer_FlashlightServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_FlashlightServices>("CPlayer_FlashlightServices")

        .endClass();
}