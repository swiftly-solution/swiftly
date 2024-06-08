#include "../../../core/scripting/generated/classes/GEventClientPreSimulate_t.h"
#include "../core.h"

void SetupLuaClassGEventClientPreSimulate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientPreSimulate_t>("EventClientPreSimulate_t")

        .endClass();
}