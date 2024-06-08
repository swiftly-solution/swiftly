#include "../../../core/scripting/generated/classes/GC_OP_CPOffsetToPercentageBetweenCPs.h"
#include "../core.h"

void SetupLuaClassGC_OP_CPOffsetToPercentageBetweenCPs(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_CPOffsetToPercentageBetweenCPs>("C_OP_CPOffsetToPercentageBetweenCPs")
        .addProperty("InputMin", &GC_OP_CPOffsetToPercentageBetweenCPs::GetInputMin, &GC_OP_CPOffsetToPercentageBetweenCPs::SetInputMin)
        .addProperty("InputMax", &GC_OP_CPOffsetToPercentageBetweenCPs::GetInputMax, &GC_OP_CPOffsetToPercentageBetweenCPs::SetInputMax)
        .addProperty("InputBias", &GC_OP_CPOffsetToPercentageBetweenCPs::GetInputBias, &GC_OP_CPOffsetToPercentageBetweenCPs::SetInputBias)
        .addProperty("StartCP", &GC_OP_CPOffsetToPercentageBetweenCPs::GetStartCP, &GC_OP_CPOffsetToPercentageBetweenCPs::SetStartCP)
        .addProperty("EndCP", &GC_OP_CPOffsetToPercentageBetweenCPs::GetEndCP, &GC_OP_CPOffsetToPercentageBetweenCPs::SetEndCP)
        .addProperty("OffsetCP", &GC_OP_CPOffsetToPercentageBetweenCPs::GetOffsetCP, &GC_OP_CPOffsetToPercentageBetweenCPs::SetOffsetCP)
        .addProperty("OuputCP", &GC_OP_CPOffsetToPercentageBetweenCPs::GetOuputCP, &GC_OP_CPOffsetToPercentageBetweenCPs::SetOuputCP)
        .addProperty("InputCP", &GC_OP_CPOffsetToPercentageBetweenCPs::GetInputCP, &GC_OP_CPOffsetToPercentageBetweenCPs::SetInputCP)
        .addProperty("RadialCheck", &GC_OP_CPOffsetToPercentageBetweenCPs::GetRadialCheck, &GC_OP_CPOffsetToPercentageBetweenCPs::SetRadialCheck)
        .addProperty("ScaleOffset", &GC_OP_CPOffsetToPercentageBetweenCPs::GetScaleOffset, &GC_OP_CPOffsetToPercentageBetweenCPs::SetScaleOffset)
        .addProperty("Offset", &GC_OP_CPOffsetToPercentageBetweenCPs::GetOffset, &GC_OP_CPOffsetToPercentageBetweenCPs::SetOffset)
        .endClass();
}