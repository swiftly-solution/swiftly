#include "../../../core/scripting/generated/classes/GCFuncTrain.h"
#include "../core.h"

void SetupLuaClassGCFuncTrain(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncTrain>("CFuncTrain")
        .addProperty("CurrentTarget", &GCFuncTrain::GetCurrentTarget, &GCFuncTrain::SetCurrentTarget)
        .addProperty("Activated", &GCFuncTrain::GetActivated, &GCFuncTrain::SetActivated)
        .addProperty("Enemy", &GCFuncTrain::GetEnemy, &GCFuncTrain::SetEnemy)
        .addProperty("BlockDamage", &GCFuncTrain::GetBlockDamage, &GCFuncTrain::SetBlockDamage)
        .addProperty("LastTarget", &GCFuncTrain::GetLastTarget, &GCFuncTrain::SetLastTarget)
        .endClass();
}