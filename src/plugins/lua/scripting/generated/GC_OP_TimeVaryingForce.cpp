#include "../../../core/scripting/generated/classes/GC_OP_TimeVaryingForce.h"
#include "../core.h"

void SetupLuaClassGC_OP_TimeVaryingForce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_TimeVaryingForce>("C_OP_TimeVaryingForce")
        .addProperty("StartLerpTime", &GC_OP_TimeVaryingForce::GetStartLerpTime, &GC_OP_TimeVaryingForce::SetStartLerpTime)
        .addProperty("StartingForce", &GC_OP_TimeVaryingForce::GetStartingForce, &GC_OP_TimeVaryingForce::SetStartingForce)
        .addProperty("EndLerpTime", &GC_OP_TimeVaryingForce::GetEndLerpTime, &GC_OP_TimeVaryingForce::SetEndLerpTime)
        .addProperty("EndingForce", &GC_OP_TimeVaryingForce::GetEndingForce, &GC_OP_TimeVaryingForce::SetEndingForce)
        .endClass();
}