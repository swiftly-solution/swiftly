#include "../../../core/scripting/generated/classes/GCEnvSpark.h"
#include "../core.h"

void SetupLuaClassGCEnvSpark(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvSpark>("CEnvSpark")
        .addProperty("Delay", &GCEnvSpark::GetDelay, &GCEnvSpark::SetDelay)
        .addProperty("Magnitude", &GCEnvSpark::GetMagnitude, &GCEnvSpark::SetMagnitude)
        .addProperty("TrailLength", &GCEnvSpark::GetTrailLength, &GCEnvSpark::SetTrailLength)
        .addProperty("Type", &GCEnvSpark::GetType, &GCEnvSpark::SetType)
        .addProperty("OnSpark", &GCEnvSpark::GetOnSpark, &GCEnvSpark::SetOnSpark)
        .endClass();
}