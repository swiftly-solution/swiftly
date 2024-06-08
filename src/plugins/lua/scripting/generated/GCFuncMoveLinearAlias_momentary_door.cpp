#include "../../../core/scripting/generated/classes/GCFuncMoveLinearAlias_momentary_door.h"
#include "../core.h"

void SetupLuaClassGCFuncMoveLinearAlias_momentary_door(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncMoveLinearAlias_momentary_door>("CFuncMoveLinearAlias_momentary_door")

        .endClass();
}