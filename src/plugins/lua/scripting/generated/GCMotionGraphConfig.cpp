#include "../../../core/scripting/generated/classes/GCMotionGraphConfig.h"
#include "../core.h"

void SetupLuaClassGCMotionGraphConfig(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionGraphConfig>("CMotionGraphConfig")
        .addProperty("ParamValues", &GCMotionGraphConfig::GetParamValues, &GCMotionGraphConfig::SetParamValues)
        .addProperty("Duration", &GCMotionGraphConfig::GetDuration, &GCMotionGraphConfig::SetDuration)
        .addProperty("MotionIndex", &GCMotionGraphConfig::GetMotionIndex, &GCMotionGraphConfig::SetMotionIndex)
        .addProperty("SampleStart", &GCMotionGraphConfig::GetSampleStart, &GCMotionGraphConfig::SetSampleStart)
        .addProperty("SampleCount", &GCMotionGraphConfig::GetSampleCount, &GCMotionGraphConfig::SetSampleCount)
        .endClass();
}