#include "../../../core/scripting/generated/classes/GCAnimTagManagerUpdater.h"
#include "../core.h"

void SetupLuaClassGCAnimTagManagerUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimTagManagerUpdater>("CAnimTagManagerUpdater")

        .endClass();
}