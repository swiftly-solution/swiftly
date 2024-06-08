#include "../../../core/scripting/generated/classes/GCMotionGraph.h"
#include "../core.h"

void SetupLuaClassGCMotionGraph(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionGraph>("CMotionGraph")
        .addProperty("ParamSpans", &GCMotionGraph::GetParamSpans, &GCMotionGraph::SetParamSpans)
        .addProperty("Tags", &GCMotionGraph::GetTags, &GCMotionGraph::SetTags)
        .addProperty("ParameterCount", &GCMotionGraph::GetParameterCount, &GCMotionGraph::SetParameterCount)
        .addProperty("ConfigStartIndex", &GCMotionGraph::GetConfigStartIndex, &GCMotionGraph::SetConfigStartIndex)
        .addProperty("ConfigCount", &GCMotionGraph::GetConfigCount, &GCMotionGraph::SetConfigCount)
        .addProperty("Loop", &GCMotionGraph::GetLoop, &GCMotionGraph::SetLoop)
        .endClass();
}