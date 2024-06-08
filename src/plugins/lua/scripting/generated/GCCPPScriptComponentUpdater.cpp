#include "../../../core/scripting/generated/classes/GCCPPScriptComponentUpdater.h"
#include "../core.h"

void SetupLuaClassGCCPPScriptComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCPPScriptComponentUpdater>("CCPPScriptComponentUpdater")

        .endClass();
}