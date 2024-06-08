#include "../../../core/scripting/generated/classes/GC_OP_InheritFromParentParticles.h"
#include "../core.h"

void SetupLuaClassGC_OP_InheritFromParentParticles(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_InheritFromParentParticles>("C_OP_InheritFromParentParticles")
        .addProperty("Scale", &GC_OP_InheritFromParentParticles::GetScale, &GC_OP_InheritFromParentParticles::SetScale)
        .addProperty("FieldOutput", &GC_OP_InheritFromParentParticles::GetFieldOutput, &GC_OP_InheritFromParentParticles::SetFieldOutput)
        .addProperty("Increment", &GC_OP_InheritFromParentParticles::GetIncrement, &GC_OP_InheritFromParentParticles::SetIncrement)
        .addProperty("RandomDistribution", &GC_OP_InheritFromParentParticles::GetRandomDistribution, &GC_OP_InheritFromParentParticles::SetRandomDistribution)
        .endClass();
}