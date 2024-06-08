#include "../../../core/scripting/generated/classes/GC_OP_CurlNoiseForce.h"
#include "../core.h"

void SetupLuaClassGC_OP_CurlNoiseForce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_CurlNoiseForce>("C_OP_CurlNoiseForce")
        .addProperty("NoiseType", &GC_OP_CurlNoiseForce::GetNoiseType, &GC_OP_CurlNoiseForce::SetNoiseType)
        .addProperty("NoiseFreq", &GC_OP_CurlNoiseForce::GetNoiseFreq, &GC_OP_CurlNoiseForce::SetNoiseFreq)
        .addProperty("NoiseScale", &GC_OP_CurlNoiseForce::GetNoiseScale, &GC_OP_CurlNoiseForce::SetNoiseScale)
        .addProperty("Offset", &GC_OP_CurlNoiseForce::GetOffset, &GC_OP_CurlNoiseForce::SetOffset)
        .addProperty("OffsetRate", &GC_OP_CurlNoiseForce::GetOffsetRate, &GC_OP_CurlNoiseForce::SetOffsetRate)
        .addProperty("WorleySeed", &GC_OP_CurlNoiseForce::GetWorleySeed, &GC_OP_CurlNoiseForce::SetWorleySeed)
        .addProperty("WorleyJitter", &GC_OP_CurlNoiseForce::GetWorleyJitter, &GC_OP_CurlNoiseForce::SetWorleyJitter)
        .endClass();
}