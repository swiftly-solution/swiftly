#include "../../../core/scripting/generated/classes/GC_OP_MovementRotateParticleAroundAxis.h"
#include "../core.h"

void SetupLuaClassGC_OP_MovementRotateParticleAroundAxis(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_MovementRotateParticleAroundAxis>("C_OP_MovementRotateParticleAroundAxis")
        .addProperty("RotRate", &GC_OP_MovementRotateParticleAroundAxis::GetRotRate, &GC_OP_MovementRotateParticleAroundAxis::SetRotRate)
        .addProperty("TransformInput", &GC_OP_MovementRotateParticleAroundAxis::GetTransformInput, &GC_OP_MovementRotateParticleAroundAxis::SetTransformInput)
        .addProperty("LocalSpace", &GC_OP_MovementRotateParticleAroundAxis::GetLocalSpace, &GC_OP_MovementRotateParticleAroundAxis::SetLocalSpace)
        .endClass();
}