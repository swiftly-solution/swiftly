#include "../../../core/scripting/generated/classes/GCTonemapController2Alias_env_tonemap_controller2.h"
#include "../core.h"

void SetupLuaClassGCTonemapController2Alias_env_tonemap_controller2(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTonemapController2Alias_env_tonemap_controller2>("CTonemapController2Alias_env_tonemap_controller2")

        .endClass();
}