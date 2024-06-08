#include "../../../core/scripting/generated/classes/GC_OP_TurbulenceForce.h"
#include "../core.h"

void SetupLuaClassGC_OP_TurbulenceForce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_TurbulenceForce>("C_OP_TurbulenceForce")
        .addProperty("NoiseCoordScale0", &GC_OP_TurbulenceForce::GetNoiseCoordScale0, &GC_OP_TurbulenceForce::SetNoiseCoordScale0)
        .addProperty("NoiseCoordScale1", &GC_OP_TurbulenceForce::GetNoiseCoordScale1, &GC_OP_TurbulenceForce::SetNoiseCoordScale1)
        .addProperty("NoiseCoordScale2", &GC_OP_TurbulenceForce::GetNoiseCoordScale2, &GC_OP_TurbulenceForce::SetNoiseCoordScale2)
        .addProperty("NoiseCoordScale3", &GC_OP_TurbulenceForce::GetNoiseCoordScale3, &GC_OP_TurbulenceForce::SetNoiseCoordScale3)
        .addProperty("NoiseAmount0", &GC_OP_TurbulenceForce::GetNoiseAmount0, &GC_OP_TurbulenceForce::SetNoiseAmount0)
        .addProperty("NoiseAmount1", &GC_OP_TurbulenceForce::GetNoiseAmount1, &GC_OP_TurbulenceForce::SetNoiseAmount1)
        .addProperty("NoiseAmount2", &GC_OP_TurbulenceForce::GetNoiseAmount2, &GC_OP_TurbulenceForce::SetNoiseAmount2)
        .addProperty("NoiseAmount3", &GC_OP_TurbulenceForce::GetNoiseAmount3, &GC_OP_TurbulenceForce::SetNoiseAmount3)
        .endClass();
}