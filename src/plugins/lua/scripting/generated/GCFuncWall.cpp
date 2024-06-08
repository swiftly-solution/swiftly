#include "../../../core/scripting/generated/classes/GCFuncWall.h"
#include "../core.h"

void SetupLuaClassGCFuncWall(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncWall>("CFuncWall")
        .addProperty("State", &GCFuncWall::GetState, &GCFuncWall::SetState)
        .endClass();
}