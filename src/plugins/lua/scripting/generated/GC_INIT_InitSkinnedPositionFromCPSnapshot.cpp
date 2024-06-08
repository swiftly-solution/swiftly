#include "../../../core/scripting/generated/classes/GC_INIT_InitSkinnedPositionFromCPSnapshot.h"
#include "../core.h"

void SetupLuaClassGC_INIT_InitSkinnedPositionFromCPSnapshot(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_InitSkinnedPositionFromCPSnapshot>("C_INIT_InitSkinnedPositionFromCPSnapshot")
        .addProperty("SnapshotControlPointNumber", &GC_INIT_InitSkinnedPositionFromCPSnapshot::GetSnapshotControlPointNumber, &GC_INIT_InitSkinnedPositionFromCPSnapshot::SetSnapshotControlPointNumber)
        .addProperty("ControlPointNumber", &GC_INIT_InitSkinnedPositionFromCPSnapshot::GetControlPointNumber, &GC_INIT_InitSkinnedPositionFromCPSnapshot::SetControlPointNumber)
        .addProperty("Random", &GC_INIT_InitSkinnedPositionFromCPSnapshot::GetRandom, &GC_INIT_InitSkinnedPositionFromCPSnapshot::SetRandom)
        .addProperty("RandomSeed", &GC_INIT_InitSkinnedPositionFromCPSnapshot::GetRandomSeed, &GC_INIT_InitSkinnedPositionFromCPSnapshot::SetRandomSeed)
        .addProperty("Rigid", &GC_INIT_InitSkinnedPositionFromCPSnapshot::GetRigid, &GC_INIT_InitSkinnedPositionFromCPSnapshot::SetRigid)
        .addProperty("SetNormal", &GC_INIT_InitSkinnedPositionFromCPSnapshot::GetSetNormal, &GC_INIT_InitSkinnedPositionFromCPSnapshot::SetSetNormal)
        .addProperty("IgnoreDt", &GC_INIT_InitSkinnedPositionFromCPSnapshot::GetIgnoreDt, &GC_INIT_InitSkinnedPositionFromCPSnapshot::SetIgnoreDt)
        .addProperty("MinNormalVelocity", &GC_INIT_InitSkinnedPositionFromCPSnapshot::GetMinNormalVelocity, &GC_INIT_InitSkinnedPositionFromCPSnapshot::SetMinNormalVelocity)
        .addProperty("MaxNormalVelocity", &GC_INIT_InitSkinnedPositionFromCPSnapshot::GetMaxNormalVelocity, &GC_INIT_InitSkinnedPositionFromCPSnapshot::SetMaxNormalVelocity)
        .addProperty("IndexType", &GC_INIT_InitSkinnedPositionFromCPSnapshot::GetIndexType, &GC_INIT_InitSkinnedPositionFromCPSnapshot::SetIndexType)
        .addProperty("ReadIndex", &GC_INIT_InitSkinnedPositionFromCPSnapshot::GetReadIndex, &GC_INIT_InitSkinnedPositionFromCPSnapshot::SetReadIndex)
        .addProperty("Increment", &GC_INIT_InitSkinnedPositionFromCPSnapshot::GetIncrement, &GC_INIT_InitSkinnedPositionFromCPSnapshot::SetIncrement)
        .addProperty("FullLoopIncrement", &GC_INIT_InitSkinnedPositionFromCPSnapshot::GetFullLoopIncrement, &GC_INIT_InitSkinnedPositionFromCPSnapshot::SetFullLoopIncrement)
        .addProperty("SnapShotStartPoint", &GC_INIT_InitSkinnedPositionFromCPSnapshot::GetSnapShotStartPoint, &GC_INIT_InitSkinnedPositionFromCPSnapshot::SetSnapShotStartPoint)
        .addProperty("BoneVelocity", &GC_INIT_InitSkinnedPositionFromCPSnapshot::GetBoneVelocity, &GC_INIT_InitSkinnedPositionFromCPSnapshot::SetBoneVelocity)
        .addProperty("BoneVelocityMax", &GC_INIT_InitSkinnedPositionFromCPSnapshot::GetBoneVelocityMax, &GC_INIT_InitSkinnedPositionFromCPSnapshot::SetBoneVelocityMax)
        .addProperty("CopyColor", &GC_INIT_InitSkinnedPositionFromCPSnapshot::GetCopyColor, &GC_INIT_InitSkinnedPositionFromCPSnapshot::SetCopyColor)
        .addProperty("CopyAlpha", &GC_INIT_InitSkinnedPositionFromCPSnapshot::GetCopyAlpha, &GC_INIT_InitSkinnedPositionFromCPSnapshot::SetCopyAlpha)
        .addProperty("SetRadius", &GC_INIT_InitSkinnedPositionFromCPSnapshot::GetSetRadius, &GC_INIT_InitSkinnedPositionFromCPSnapshot::SetSetRadius)
        .endClass();
}