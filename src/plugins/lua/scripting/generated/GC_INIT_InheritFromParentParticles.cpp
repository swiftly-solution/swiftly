#include "../../../core/scripting/generated/classes/GC_INIT_InheritFromParentParticles.h"
#include "../core.h"

void SetupLuaClassGC_INIT_InheritFromParentParticles(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_InheritFromParentParticles>("C_INIT_InheritFromParentParticles")
        .addProperty("Scale", &GC_INIT_InheritFromParentParticles::GetScale, &GC_INIT_InheritFromParentParticles::SetScale)
        .addProperty("FieldOutput", &GC_INIT_InheritFromParentParticles::GetFieldOutput, &GC_INIT_InheritFromParentParticles::SetFieldOutput)
        .addProperty("Increment", &GC_INIT_InheritFromParentParticles::GetIncrement, &GC_INIT_InheritFromParentParticles::SetIncrement)
        .addProperty("RandomDistribution", &GC_INIT_InheritFromParentParticles::GetRandomDistribution, &GC_INIT_InheritFromParentParticles::SetRandomDistribution)
        .addProperty("RandomSeed", &GC_INIT_InheritFromParentParticles::GetRandomSeed, &GC_INIT_InheritFromParentParticles::SetRandomSeed)
        .endClass();
}