#include "../../../core/scripting/generated/classes/GC_OP_IntraParticleForce.h"
#include "../core.h"

void SetupLuaClassGC_OP_IntraParticleForce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_IntraParticleForce>("C_OP_IntraParticleForce")
        .addProperty("AttractionMinDistance", &GC_OP_IntraParticleForce::GetAttractionMinDistance, &GC_OP_IntraParticleForce::SetAttractionMinDistance)
        .addProperty("AttractionMaxDistance", &GC_OP_IntraParticleForce::GetAttractionMaxDistance, &GC_OP_IntraParticleForce::SetAttractionMaxDistance)
        .addProperty("AttractionMaxStrength", &GC_OP_IntraParticleForce::GetAttractionMaxStrength, &GC_OP_IntraParticleForce::SetAttractionMaxStrength)
        .addProperty("RepulsionMinDistance", &GC_OP_IntraParticleForce::GetRepulsionMinDistance, &GC_OP_IntraParticleForce::SetRepulsionMinDistance)
        .addProperty("RepulsionMaxDistance", &GC_OP_IntraParticleForce::GetRepulsionMaxDistance, &GC_OP_IntraParticleForce::SetRepulsionMaxDistance)
        .addProperty("RepulsionMaxStrength", &GC_OP_IntraParticleForce::GetRepulsionMaxStrength, &GC_OP_IntraParticleForce::SetRepulsionMaxStrength)
        .addProperty("UseAABB", &GC_OP_IntraParticleForce::GetUseAABB, &GC_OP_IntraParticleForce::SetUseAABB)
        .addProperty("ThreadIt", &GC_OP_IntraParticleForce::GetThreadIt, &GC_OP_IntraParticleForce::SetThreadIt)
        .endClass();
}