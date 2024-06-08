#include "../../../core/scripting/generated/classes/GC_OP_ReadFromNeighboringParticle.h"
#include "../core.h"

void SetupLuaClassGC_OP_ReadFromNeighboringParticle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ReadFromNeighboringParticle>("C_OP_ReadFromNeighboringParticle")
        .addProperty("FieldInput", &GC_OP_ReadFromNeighboringParticle::GetFieldInput, &GC_OP_ReadFromNeighboringParticle::SetFieldInput)
        .addProperty("FieldOutput", &GC_OP_ReadFromNeighboringParticle::GetFieldOutput, &GC_OP_ReadFromNeighboringParticle::SetFieldOutput)
        .addProperty("Increment", &GC_OP_ReadFromNeighboringParticle::GetIncrement, &GC_OP_ReadFromNeighboringParticle::SetIncrement)
        .addProperty("DistanceCheck", &GC_OP_ReadFromNeighboringParticle::GetDistanceCheck, &GC_OP_ReadFromNeighboringParticle::SetDistanceCheck)
        .addProperty("Interpolation", &GC_OP_ReadFromNeighboringParticle::GetInterpolation, &GC_OP_ReadFromNeighboringParticle::SetInterpolation)
        .endClass();
}