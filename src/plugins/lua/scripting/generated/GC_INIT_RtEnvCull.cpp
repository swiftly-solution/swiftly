#include "../../../core/scripting/generated/classes/GC_INIT_RtEnvCull.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RtEnvCull(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RtEnvCull>("C_INIT_RtEnvCull")
        .addProperty("TestDir", &GC_INIT_RtEnvCull::GetTestDir, &GC_INIT_RtEnvCull::SetTestDir)
        .addProperty("TestNormal", &GC_INIT_RtEnvCull::GetTestNormal, &GC_INIT_RtEnvCull::SetTestNormal)
        .addProperty("UseVelocity", &GC_INIT_RtEnvCull::GetUseVelocity, &GC_INIT_RtEnvCull::SetUseVelocity)
        .addProperty("CullOnMiss", &GC_INIT_RtEnvCull::GetCullOnMiss, &GC_INIT_RtEnvCull::SetCullOnMiss)
        .addProperty("LifeAdjust", &GC_INIT_RtEnvCull::GetLifeAdjust, &GC_INIT_RtEnvCull::SetLifeAdjust)
        .addProperty("RtEnvName", &GC_INIT_RtEnvCull::GetRtEnvName, &GC_INIT_RtEnvCull::SetRtEnvName)
        .addProperty("RTEnvCP", &GC_INIT_RtEnvCull::GetRTEnvCP, &GC_INIT_RtEnvCull::SetRTEnvCP)
        .addProperty("Component", &GC_INIT_RtEnvCull::GetComponent, &GC_INIT_RtEnvCull::SetComponent)
        .endClass();
}