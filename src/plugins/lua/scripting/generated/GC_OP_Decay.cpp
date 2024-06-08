#include "../../../core/scripting/generated/classes/GC_OP_Decay.h"
#include "../core.h"

void SetupLuaClassGC_OP_Decay(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_Decay>("C_OP_Decay")
        .addProperty("RopeDecay", &GC_OP_Decay::GetRopeDecay, &GC_OP_Decay::SetRopeDecay)
        .addProperty("ForcePreserveParticleOrder", &GC_OP_Decay::GetForcePreserveParticleOrder, &GC_OP_Decay::SetForcePreserveParticleOrder)
        .endClass();
}