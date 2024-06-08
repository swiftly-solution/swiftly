#include "../../../core/scripting/generated/classes/GCNmBoneMask.h"
#include "../core.h"

void SetupLuaClassGCNmBoneMask(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmBoneMask>("CNmBoneMask")
        .addProperty("WeightInfo", &GCNmBoneMask::GetWeightInfo, &GCNmBoneMask::SetWeightInfo)
        .addProperty("Weights", &GCNmBoneMask::GetWeights, &GCNmBoneMask::SetWeights)
        .endClass();
}