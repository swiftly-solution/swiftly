#include "../../../core/scripting/generated/classes/GCFuncLadderAlias_func_useableladder.h"
#include "../core.h"

void SetupLuaClassGCFuncLadderAlias_func_useableladder(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncLadderAlias_func_useableladder>("CFuncLadderAlias_func_useableladder")

        .endClass();
}