#include "../../../core/scripting/generated/classes/GCPointServerCommand.h"
#include "../core.h"

void SetupLuaClassGCPointServerCommand(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointServerCommand>("CPointServerCommand")

        .endClass();
}