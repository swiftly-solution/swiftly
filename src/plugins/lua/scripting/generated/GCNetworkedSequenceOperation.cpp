#include "../../../core/scripting/generated/classes/GCNetworkedSequenceOperation.h"
#include "../core.h"

void SetupLuaClassGCNetworkedSequenceOperation(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNetworkedSequenceOperation>("CNetworkedSequenceOperation")
        .addProperty("PrevCycle", &GCNetworkedSequenceOperation::GetPrevCycle, &GCNetworkedSequenceOperation::SetPrevCycle)
        .addProperty("Cycle", &GCNetworkedSequenceOperation::GetCycle, &GCNetworkedSequenceOperation::SetCycle)
        .addProperty("Weight", &GCNetworkedSequenceOperation::GetWeight, &GCNetworkedSequenceOperation::SetWeight)
        .addProperty("SequenceChangeNetworked", &GCNetworkedSequenceOperation::GetSequenceChangeNetworked, &GCNetworkedSequenceOperation::SetSequenceChangeNetworked)
        .addProperty("Discontinuity", &GCNetworkedSequenceOperation::GetDiscontinuity, &GCNetworkedSequenceOperation::SetDiscontinuity)
        .addProperty("PrevCycleFromDiscontinuity", &GCNetworkedSequenceOperation::GetPrevCycleFromDiscontinuity, &GCNetworkedSequenceOperation::SetPrevCycleFromDiscontinuity)
        .addProperty("PrevCycleForAnimEventDetection", &GCNetworkedSequenceOperation::GetPrevCycleForAnimEventDetection, &GCNetworkedSequenceOperation::SetPrevCycleForAnimEventDetection)
        .endClass();
}