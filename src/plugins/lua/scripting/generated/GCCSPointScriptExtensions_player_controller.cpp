#include "../../../core/scripting/generated/classes/GCCSPointScriptExtensions_player_controller.h"
#include "../core.h"

void SetupLuaClassGCCSPointScriptExtensions_player_controller(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPointScriptExtensions_player_controller>("CCSPointScriptExtensions_player_controller")

        .endClass();
}