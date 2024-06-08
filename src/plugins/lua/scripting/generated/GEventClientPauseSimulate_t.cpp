#include "../../../core/scripting/generated/classes/GEventClientPauseSimulate_t.h"
#include "../core.h"

void SetupLuaClassGEventClientPauseSimulate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientPauseSimulate_t>("EventClientPauseSimulate_t")

        .endClass();
}