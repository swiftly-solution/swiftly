#include "../../../core/scripting/generated/classes/GCBaseAnimGraph.h"
#include "../core.h"

void SetupLuaClassGCBaseAnimGraph(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseAnimGraph>("CBaseAnimGraph")
        .addProperty("InitiallyPopulateInterpHistory", &GCBaseAnimGraph::GetInitiallyPopulateInterpHistory, &GCBaseAnimGraph::SetInitiallyPopulateInterpHistory)
        .addProperty("ChoreoServices", &GCBaseAnimGraph::GetChoreoServices, &GCBaseAnimGraph::SetChoreoServices)
        .addProperty("AnimGraphUpdateEnabled", &GCBaseAnimGraph::GetAnimGraphUpdateEnabled, &GCBaseAnimGraph::SetAnimGraphUpdateEnabled)
        .addProperty("MaxSlopeDistance", &GCBaseAnimGraph::GetMaxSlopeDistance, &GCBaseAnimGraph::SetMaxSlopeDistance)
        .addProperty("LastSlopeCheckPos", &GCBaseAnimGraph::GetLastSlopeCheckPos, &GCBaseAnimGraph::SetLastSlopeCheckPos)
        .addProperty("AnimationUpdateScheduled", &GCBaseAnimGraph::GetAnimationUpdateScheduled, &GCBaseAnimGraph::SetAnimationUpdateScheduled)
        .addProperty("Force", &GCBaseAnimGraph::GetForce, &GCBaseAnimGraph::SetForce)
        .addProperty("ForceBone", &GCBaseAnimGraph::GetForceBone, &GCBaseAnimGraph::SetForceBone)
        .addProperty("RagdollPose", &GCBaseAnimGraph::GetRagdollPose, &GCBaseAnimGraph::SetRagdollPose)
        .addProperty("RagdollClientSide", &GCBaseAnimGraph::GetRagdollClientSide, &GCBaseAnimGraph::SetRagdollClientSide)
        .endClass();
}