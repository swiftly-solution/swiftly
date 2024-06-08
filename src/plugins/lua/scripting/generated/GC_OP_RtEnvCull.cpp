#include "../../../core/scripting/generated/classes/GC_OP_RtEnvCull.h"
#include "../core.h"

void SetupLuaClassGC_OP_RtEnvCull(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RtEnvCull>("C_OP_RtEnvCull")
        .addProperty("TestDir", &GC_OP_RtEnvCull::GetTestDir, &GC_OP_RtEnvCull::SetTestDir)
        .addProperty("TestNormal", &GC_OP_RtEnvCull::GetTestNormal, &GC_OP_RtEnvCull::SetTestNormal)
        .addProperty("CullOnMiss", &GC_OP_RtEnvCull::GetCullOnMiss, &GC_OP_RtEnvCull::SetCullOnMiss)
        .addProperty("StickInsteadOfCull", &GC_OP_RtEnvCull::GetStickInsteadOfCull, &GC_OP_RtEnvCull::SetStickInsteadOfCull)
        .addProperty("RtEnvName", &GC_OP_RtEnvCull::GetRtEnvName, &GC_OP_RtEnvCull::SetRtEnvName)
        .addProperty("RTEnvCP", &GC_OP_RtEnvCull::GetRTEnvCP, &GC_OP_RtEnvCull::SetRTEnvCP)
        .addProperty("Component", &GC_OP_RtEnvCull::GetComponent, &GC_OP_RtEnvCull::SetComponent)
        .endClass();
}