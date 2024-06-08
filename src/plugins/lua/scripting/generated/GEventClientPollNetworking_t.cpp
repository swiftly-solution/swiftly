#include "../../../core/scripting/generated/classes/GEventClientPollNetworking_t.h"
#include "../core.h"

void SetupLuaClassGEventClientPollNetworking_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientPollNetworking_t>("EventClientPollNetworking_t")
        .addProperty("TickCount", &GEventClientPollNetworking_t::GetTickCount, &GEventClientPollNetworking_t::SetTickCount)
        .endClass();
}