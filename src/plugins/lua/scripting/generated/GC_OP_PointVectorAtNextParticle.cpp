#include "../../../core/scripting/generated/classes/GC_OP_PointVectorAtNextParticle.h"
#include "../core.h"

void SetupLuaClassGC_OP_PointVectorAtNextParticle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_PointVectorAtNextParticle>("C_OP_PointVectorAtNextParticle")
        .addProperty("FieldOutput", &GC_OP_PointVectorAtNextParticle::GetFieldOutput, &GC_OP_PointVectorAtNextParticle::SetFieldOutput)
        .addProperty("Interpolation", &GC_OP_PointVectorAtNextParticle::GetInterpolation, &GC_OP_PointVectorAtNextParticle::SetInterpolation)
        .endClass();
}