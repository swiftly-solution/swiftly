#include "../../../core/scripting/generated/classes/GCFuncTankTrain.h"
#include "../core.h"

void SetupLuaClassGCFuncTankTrain(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncTankTrain>("CFuncTankTrain")
        .addProperty("OnDeath", &GCFuncTankTrain::GetOnDeath, &GCFuncTankTrain::SetOnDeath)
        .endClass();
}