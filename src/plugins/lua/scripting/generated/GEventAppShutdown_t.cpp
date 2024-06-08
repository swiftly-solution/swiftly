#include "../../../core/scripting/generated/classes/GEventAppShutdown_t.h"
#include "../core.h"

void SetupLuaClassGEventAppShutdown_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventAppShutdown_t>("EventAppShutdown_t")
        .addProperty("Dummy0", &GEventAppShutdown_t::GetDummy0, &GEventAppShutdown_t::SetDummy0)
        .endClass();
}