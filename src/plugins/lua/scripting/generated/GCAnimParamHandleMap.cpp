#include "../../../core/scripting/generated/classes/GCAnimParamHandleMap.h"
#include "../core.h"

void SetupLuaClassGCAnimParamHandleMap(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimParamHandleMap>("CAnimParamHandleMap")

        .endClass();
}