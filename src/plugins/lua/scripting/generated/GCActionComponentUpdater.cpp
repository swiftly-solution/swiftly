#include "../../../core/scripting/generated/classes/GCActionComponentUpdater.h"
#include "../core.h"

void SetupLuaClassGCActionComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCActionComponentUpdater>("CActionComponentUpdater")

        .endClass();
}