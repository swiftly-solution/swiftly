#include "../../../core/scripting/generated/classes/GCAnimActionUpdater.h"
#include "../core.h"

void SetupLuaClassGCAnimActionUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimActionUpdater>("CAnimActionUpdater")

        .endClass();
}