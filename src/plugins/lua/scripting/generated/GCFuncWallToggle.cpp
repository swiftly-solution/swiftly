#include "../../../core/scripting/generated/classes/GCFuncWallToggle.h"
#include "../core.h"

void SetupLuaClassGCFuncWallToggle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncWallToggle>("CFuncWallToggle")

        .endClass();
}