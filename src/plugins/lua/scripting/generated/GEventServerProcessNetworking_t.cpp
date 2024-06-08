#include "../../../core/scripting/generated/classes/GEventServerProcessNetworking_t.h"
#include "../core.h"

void SetupLuaClassGEventServerProcessNetworking_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventServerProcessNetworking_t>("EventServerProcessNetworking_t")

        .endClass();
}