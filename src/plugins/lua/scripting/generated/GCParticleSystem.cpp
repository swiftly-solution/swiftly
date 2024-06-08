#include "../../../core/scripting/generated/classes/GCParticleSystem.h"
#include "../core.h"

void SetupLuaClassGCParticleSystem(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleSystem>("CParticleSystem")
        .addProperty("SnapshotFileName", &GCParticleSystem::GetSnapshotFileName, &GCParticleSystem::SetSnapshotFileName)
        .addProperty("Active", &GCParticleSystem::GetActive, &GCParticleSystem::SetActive)
        .addProperty("Frozen", &GCParticleSystem::GetFrozen, &GCParticleSystem::SetFrozen)
        .addProperty("FreezeTransitionDuration", &GCParticleSystem::GetFreezeTransitionDuration, &GCParticleSystem::SetFreezeTransitionDuration)
        .addProperty("StopType", &GCParticleSystem::GetStopType, &GCParticleSystem::SetStopType)
        .addProperty("AnimateDuringGameplayPause", &GCParticleSystem::GetAnimateDuringGameplayPause, &GCParticleSystem::SetAnimateDuringGameplayPause)
        .addProperty("PreSimTime", &GCParticleSystem::GetPreSimTime, &GCParticleSystem::SetPreSimTime)
        .addProperty("ServerControlPoints", &GCParticleSystem::GetServerControlPoints, &GCParticleSystem::SetServerControlPoints)
        .addProperty("ServerControlPointAssignments", &GCParticleSystem::GetServerControlPointAssignments, &GCParticleSystem::SetServerControlPointAssignments)
        .addProperty("ControlPointEnts", &GCParticleSystem::GetControlPointEnts, &GCParticleSystem::SetControlPointEnts)
        .addProperty("NoSave", &GCParticleSystem::GetNoSave, &GCParticleSystem::SetNoSave)
        .addProperty("NoFreeze", &GCParticleSystem::GetNoFreeze, &GCParticleSystem::SetNoFreeze)
        .addProperty("NoRamp", &GCParticleSystem::GetNoRamp, &GCParticleSystem::SetNoRamp)
        .addProperty("StartActive", &GCParticleSystem::GetStartActive, &GCParticleSystem::SetStartActive)
        .addProperty("EffectName", &GCParticleSystem::GetEffectName, &GCParticleSystem::SetEffectName)
        .addProperty("ControlPointNames", &GCParticleSystem::GetControlPointNames, &GCParticleSystem::SetControlPointNames)
        .addProperty("DataCP", &GCParticleSystem::GetDataCP, &GCParticleSystem::SetDataCP)
        .addProperty("DataCPValue", &GCParticleSystem::GetDataCPValue, &GCParticleSystem::SetDataCPValue)
        .addProperty("TintCP", &GCParticleSystem::GetTintCP, &GCParticleSystem::SetTintCP)
        .addProperty("Tint", &GCParticleSystem::GetTint, &GCParticleSystem::SetTint)
        .endClass();
}