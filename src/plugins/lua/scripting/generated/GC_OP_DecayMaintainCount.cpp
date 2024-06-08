#include "../../../core/scripting/generated/classes/GC_OP_DecayMaintainCount.h"
#include "../core.h"

void SetupLuaClassGC_OP_DecayMaintainCount(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_DecayMaintainCount>("C_OP_DecayMaintainCount")
        .addProperty("ParticlesToMaintain", &GC_OP_DecayMaintainCount::GetParticlesToMaintain, &GC_OP_DecayMaintainCount::SetParticlesToMaintain)
        .addProperty("DecayDelay", &GC_OP_DecayMaintainCount::GetDecayDelay, &GC_OP_DecayMaintainCount::SetDecayDelay)
        .addProperty("SnapshotControlPoint", &GC_OP_DecayMaintainCount::GetSnapshotControlPoint, &GC_OP_DecayMaintainCount::SetSnapshotControlPoint)
        .addProperty("LifespanDecay", &GC_OP_DecayMaintainCount::GetLifespanDecay, &GC_OP_DecayMaintainCount::SetLifespanDecay)
        .addProperty("Scale", &GC_OP_DecayMaintainCount::GetScale, &GC_OP_DecayMaintainCount::SetScale)
        .addProperty("KillNewest", &GC_OP_DecayMaintainCount::GetKillNewest, &GC_OP_DecayMaintainCount::SetKillNewest)
        .endClass();
}