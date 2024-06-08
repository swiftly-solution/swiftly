#include "../../../core/scripting/generated/classes/GCEnvShake.h"
#include "../core.h"

void SetupLuaClassGCEnvShake(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvShake>("CEnvShake")
        .addProperty("LimitToEntity", &GCEnvShake::GetLimitToEntity, &GCEnvShake::SetLimitToEntity)
        .addProperty("Amplitude", &GCEnvShake::GetAmplitude, &GCEnvShake::SetAmplitude)
        .addProperty("Frequency", &GCEnvShake::GetFrequency, &GCEnvShake::SetFrequency)
        .addProperty("Duration", &GCEnvShake::GetDuration, &GCEnvShake::SetDuration)
        .addProperty("Radius", &GCEnvShake::GetRadius, &GCEnvShake::SetRadius)
        .addProperty("CurrentAmp", &GCEnvShake::GetCurrentAmp, &GCEnvShake::SetCurrentAmp)
        .addProperty("MaxForce", &GCEnvShake::GetMaxForce, &GCEnvShake::SetMaxForce)
        .addProperty("ShakeCallback", &GCEnvShake::GetShakeCallback, &GCEnvShake::SetShakeCallback)
        .endClass();
}