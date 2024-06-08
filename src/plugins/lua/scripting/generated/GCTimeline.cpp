#include "../../../core/scripting/generated/classes/GCTimeline.h"
#include "../core.h"

void SetupLuaClassGCTimeline(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTimeline>("CTimeline")
        .addProperty("Values", &GCTimeline::GetValues, &GCTimeline::SetValues)
        .addProperty("ValueCounts", &GCTimeline::GetValueCounts, &GCTimeline::SetValueCounts)
        .addProperty("BucketCount", &GCTimeline::GetBucketCount, &GCTimeline::SetBucketCount)
        .addProperty("Interval", &GCTimeline::GetInterval, &GCTimeline::SetInterval)
        .addProperty("FinalValue", &GCTimeline::GetFinalValue, &GCTimeline::SetFinalValue)
        .addProperty("CompressionType", &GCTimeline::GetCompressionType, &GCTimeline::SetCompressionType)
        .addProperty("Stopped", &GCTimeline::GetStopped, &GCTimeline::SetStopped)
        .endClass();
}