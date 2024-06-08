#include "../../../core/scripting/generated/classes/GCFuncWater.h"
#include "../core.h"

void SetupLuaClassGCFuncWater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncWater>("CFuncWater")
        .addProperty("BuoyancyHelper", &GCFuncWater::GetBuoyancyHelper, &GCFuncWater::SetBuoyancyHelper)
        .endClass();
}