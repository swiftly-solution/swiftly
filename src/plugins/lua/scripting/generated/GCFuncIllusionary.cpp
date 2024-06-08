#include "../../../core/scripting/generated/classes/GCFuncIllusionary.h"
#include "../core.h"

void SetupLuaClassGCFuncIllusionary(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncIllusionary>("CFuncIllusionary")

        .endClass();
}