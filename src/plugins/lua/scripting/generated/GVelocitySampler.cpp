#include "../../../core/scripting/generated/classes/GVelocitySampler.h"
#include "../core.h"

void SetupLuaClassGVelocitySampler(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVelocitySampler>("VelocitySampler")
        .addProperty("PrevSample", &GVelocitySampler::GetPrevSample, &GVelocitySampler::SetPrevSample)
        .addProperty("IdealSampleRate", &GVelocitySampler::GetIdealSampleRate, &GVelocitySampler::SetIdealSampleRate)
        .endClass();
}