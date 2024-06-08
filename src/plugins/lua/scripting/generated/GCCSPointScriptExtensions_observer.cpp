#include "../../../core/scripting/generated/classes/GCCSPointScriptExtensions_observer.h"
#include "../core.h"

void SetupLuaClassGCCSPointScriptExtensions_observer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPointScriptExtensions_observer>("CCSPointScriptExtensions_observer")

        .endClass();
}