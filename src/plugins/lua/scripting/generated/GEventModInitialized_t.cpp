#include "../../../core/scripting/generated/classes/GEventModInitialized_t.h"
#include "../core.h"

void SetupLuaClassGEventModInitialized_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventModInitialized_t>("EventModInitialized_t")

        .endClass();
}