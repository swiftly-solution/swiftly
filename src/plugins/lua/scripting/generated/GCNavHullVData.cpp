#include "../../../core/scripting/generated/classes/GCNavHullVData.h"
#include "../core.h"

void SetupLuaClassGCNavHullVData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavHullVData>("CNavHullVData")
        .addProperty("AgentEnabled", &GCNavHullVData::GetAgentEnabled, &GCNavHullVData::SetAgentEnabled)
        .addProperty("AgentRadius", &GCNavHullVData::GetAgentRadius, &GCNavHullVData::SetAgentRadius)
        .addProperty("AgentHeight", &GCNavHullVData::GetAgentHeight, &GCNavHullVData::SetAgentHeight)
        .addProperty("AgentShortHeightEnabled", &GCNavHullVData::GetAgentShortHeightEnabled, &GCNavHullVData::SetAgentShortHeightEnabled)
        .addProperty("AgentShortHeight", &GCNavHullVData::GetAgentShortHeight, &GCNavHullVData::SetAgentShortHeight)
        .addProperty("AgentMaxClimb", &GCNavHullVData::GetAgentMaxClimb, &GCNavHullVData::SetAgentMaxClimb)
        .addProperty("AgentMaxSlope", &GCNavHullVData::GetAgentMaxSlope, &GCNavHullVData::SetAgentMaxSlope)
        .addProperty("AgentMaxJumpDownDist", &GCNavHullVData::GetAgentMaxJumpDownDist, &GCNavHullVData::SetAgentMaxJumpDownDist)
        .addProperty("AgentMaxJumpHorizDistBase", &GCNavHullVData::GetAgentMaxJumpHorizDistBase, &GCNavHullVData::SetAgentMaxJumpHorizDistBase)
        .addProperty("AgentMaxJumpUpDist", &GCNavHullVData::GetAgentMaxJumpUpDist, &GCNavHullVData::SetAgentMaxJumpUpDist)
        .addProperty("AgentBorderErosion", &GCNavHullVData::GetAgentBorderErosion, &GCNavHullVData::SetAgentBorderErosion)
        .endClass();
}