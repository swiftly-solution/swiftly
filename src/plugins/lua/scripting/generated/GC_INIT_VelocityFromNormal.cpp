#include "../../../core/scripting/generated/classes/GC_INIT_VelocityFromNormal.h"
#include "../core.h"

void SetupLuaClassGC_INIT_VelocityFromNormal(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_VelocityFromNormal>("C_INIT_VelocityFromNormal")
        .addProperty("SpeedMin", &GC_INIT_VelocityFromNormal::GetSpeedMin, &GC_INIT_VelocityFromNormal::SetSpeedMin)
        .addProperty("SpeedMax", &GC_INIT_VelocityFromNormal::GetSpeedMax, &GC_INIT_VelocityFromNormal::SetSpeedMax)
        .addProperty("IgnoreDt", &GC_INIT_VelocityFromNormal::GetIgnoreDt, &GC_INIT_VelocityFromNormal::SetIgnoreDt)
        .endClass();
}