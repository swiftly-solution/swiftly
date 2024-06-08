#include "../../../core/scripting/generated/classes/GCFeMorphLayer.h"
#include "../core.h"

void SetupLuaClassGCFeMorphLayer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFeMorphLayer>("CFeMorphLayer")
        .addProperty("Name", &GCFeMorphLayer::GetName, &GCFeMorphLayer::SetName)
        .addProperty("NameHash", &GCFeMorphLayer::GetNameHash, &GCFeMorphLayer::SetNameHash)
        .addProperty("Nodes", &GCFeMorphLayer::GetNodes, &GCFeMorphLayer::SetNodes)
        .addProperty("InitPos", &GCFeMorphLayer::GetInitPos, &GCFeMorphLayer::SetInitPos)
        .addProperty("Gravity", &GCFeMorphLayer::GetGravity, &GCFeMorphLayer::SetGravity)
        .addProperty("GoalStrength", &GCFeMorphLayer::GetGoalStrength, &GCFeMorphLayer::SetGoalStrength)
        .addProperty("GoalDamping", &GCFeMorphLayer::GetGoalDamping, &GCFeMorphLayer::SetGoalDamping)
        .endClass();
}