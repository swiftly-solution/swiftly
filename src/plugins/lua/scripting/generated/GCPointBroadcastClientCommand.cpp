#include "../../../core/scripting/generated/classes/GCPointBroadcastClientCommand.h"
#include "../core.h"

void SetupLuaClassGCPointBroadcastClientCommand(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointBroadcastClientCommand>("CPointBroadcastClientCommand")

        .endClass();
}