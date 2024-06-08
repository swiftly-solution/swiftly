#include "../../../core/scripting/generated/classes/GFeMorphLayerDepr_t.h"
#include "../core.h"

void SetupLuaClassGFeMorphLayerDepr_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeMorphLayerDepr_t>("FeMorphLayerDepr_t")
        .addProperty("Name", &GFeMorphLayerDepr_t::GetName, &GFeMorphLayerDepr_t::SetName)
        .addProperty("NameHash", &GFeMorphLayerDepr_t::GetNameHash, &GFeMorphLayerDepr_t::SetNameHash)
        .addProperty("Nodes", &GFeMorphLayerDepr_t::GetNodes, &GFeMorphLayerDepr_t::SetNodes)
        .addProperty("InitPos", &GFeMorphLayerDepr_t::GetInitPos, &GFeMorphLayerDepr_t::SetInitPos)
        .addProperty("Gravity", &GFeMorphLayerDepr_t::GetGravity, &GFeMorphLayerDepr_t::SetGravity)
        .addProperty("GoalStrength", &GFeMorphLayerDepr_t::GetGoalStrength, &GFeMorphLayerDepr_t::SetGoalStrength)
        .addProperty("GoalDamping", &GFeMorphLayerDepr_t::GetGoalDamping, &GFeMorphLayerDepr_t::SetGoalDamping)
        .addProperty("Flags", &GFeMorphLayerDepr_t::GetFlags, &GFeMorphLayerDepr_t::SetFlags)
        .endClass();
}