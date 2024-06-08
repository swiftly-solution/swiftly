#include "../../../core/scripting/generated/classes/GEventClientProcessNetworking_t.h"
#include "../core.h"

void SetupLuaClassGEventClientProcessNetworking_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientProcessNetworking_t>("EventClientProcessNetworking_t")

        .endClass();
}