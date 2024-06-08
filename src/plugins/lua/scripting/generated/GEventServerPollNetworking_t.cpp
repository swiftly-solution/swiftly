#include "../../../core/scripting/generated/classes/GEventServerPollNetworking_t.h"
#include "../core.h"

void SetupLuaClassGEventServerPollNetworking_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventServerPollNetworking_t>("EventServerPollNetworking_t")

        .endClass();
}