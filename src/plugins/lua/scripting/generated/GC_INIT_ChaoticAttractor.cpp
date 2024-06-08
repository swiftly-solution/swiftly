#include "../../../core/scripting/generated/classes/GC_INIT_ChaoticAttractor.h"
#include "../core.h"

void SetupLuaClassGC_INIT_ChaoticAttractor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_ChaoticAttractor>("C_INIT_ChaoticAttractor")
        .addProperty("AParm", &GC_INIT_ChaoticAttractor::GetAParm, &GC_INIT_ChaoticAttractor::SetAParm)
        .addProperty("BParm", &GC_INIT_ChaoticAttractor::GetBParm, &GC_INIT_ChaoticAttractor::SetBParm)
        .addProperty("CParm", &GC_INIT_ChaoticAttractor::GetCParm, &GC_INIT_ChaoticAttractor::SetCParm)
        .addProperty("DParm", &GC_INIT_ChaoticAttractor::GetDParm, &GC_INIT_ChaoticAttractor::SetDParm)
        .addProperty("Scale", &GC_INIT_ChaoticAttractor::GetScale, &GC_INIT_ChaoticAttractor::SetScale)
        .addProperty("SpeedMin", &GC_INIT_ChaoticAttractor::GetSpeedMin, &GC_INIT_ChaoticAttractor::SetSpeedMin)
        .addProperty("SpeedMax", &GC_INIT_ChaoticAttractor::GetSpeedMax, &GC_INIT_ChaoticAttractor::SetSpeedMax)
        .addProperty("BaseCP", &GC_INIT_ChaoticAttractor::GetBaseCP, &GC_INIT_ChaoticAttractor::SetBaseCP)
        .addProperty("UniformSpeed", &GC_INIT_ChaoticAttractor::GetUniformSpeed, &GC_INIT_ChaoticAttractor::SetUniformSpeed)
        .endClass();
}