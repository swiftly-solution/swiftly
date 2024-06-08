#include "../../../core/scripting/generated/classes/GC_OP_InterpolateRadius.h"
#include "../core.h"

void SetupLuaClassGC_OP_InterpolateRadius(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_InterpolateRadius>("C_OP_InterpolateRadius")
        .addProperty("StartTime", &GC_OP_InterpolateRadius::GetStartTime, &GC_OP_InterpolateRadius::SetStartTime)
        .addProperty("EndTime", &GC_OP_InterpolateRadius::GetEndTime, &GC_OP_InterpolateRadius::SetEndTime)
        .addProperty("StartScale", &GC_OP_InterpolateRadius::GetStartScale, &GC_OP_InterpolateRadius::SetStartScale)
        .addProperty("EndScale", &GC_OP_InterpolateRadius::GetEndScale, &GC_OP_InterpolateRadius::SetEndScale)
        .addProperty("EaseInAndOut", &GC_OP_InterpolateRadius::GetEaseInAndOut, &GC_OP_InterpolateRadius::SetEaseInAndOut)
        .addProperty("Bias", &GC_OP_InterpolateRadius::GetBias, &GC_OP_InterpolateRadius::SetBias)
        .endClass();
}