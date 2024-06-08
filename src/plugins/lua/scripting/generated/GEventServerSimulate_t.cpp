#include "../../../core/scripting/generated/classes/GEventServerSimulate_t.h"
#include "../core.h"

void SetupLuaClassGEventServerSimulate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventServerSimulate_t>("EventServerSimulate_t")

        .endClass();
}