#include "../../../core/scripting/generated/classes/GC_OP_InheritFromParentParticlesV2.h"
#include "../core.h"

void SetupLuaClassGC_OP_InheritFromParentParticlesV2(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_InheritFromParentParticlesV2>("C_OP_InheritFromParentParticlesV2")
        .addProperty("Scale", &GC_OP_InheritFromParentParticlesV2::GetScale, &GC_OP_InheritFromParentParticlesV2::SetScale)
        .addProperty("FieldOutput", &GC_OP_InheritFromParentParticlesV2::GetFieldOutput, &GC_OP_InheritFromParentParticlesV2::SetFieldOutput)
        .addProperty("Increment", &GC_OP_InheritFromParentParticlesV2::GetIncrement, &GC_OP_InheritFromParentParticlesV2::SetIncrement)
        .addProperty("RandomDistribution", &GC_OP_InheritFromParentParticlesV2::GetRandomDistribution, &GC_OP_InheritFromParentParticlesV2::SetRandomDistribution)
        .addProperty("MissingParentBehavior", &GC_OP_InheritFromParentParticlesV2::GetMissingParentBehavior, &GC_OP_InheritFromParentParticlesV2::SetMissingParentBehavior)
        .endClass();
}