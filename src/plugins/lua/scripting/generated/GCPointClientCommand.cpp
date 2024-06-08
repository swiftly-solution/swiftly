#include "../../../core/scripting/generated/classes/GCPointClientCommand.h"
#include "../core.h"

void SetupLuaClassGCPointClientCommand(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointClientCommand>("CPointClientCommand")

        .endClass();
}