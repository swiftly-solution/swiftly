#include "../../../core/scripting/generated/classes/GWeightList.h"
#include "../core.h"

void SetupLuaClassGWeightList(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GWeightList>("WeightList")
        .addProperty("Name", &GWeightList::GetName, &GWeightList::SetName)
        .addProperty("Weights", &GWeightList::GetWeights, &GWeightList::SetWeights)
        .endClass();
}