#include "../../../core/scripting/generated/classes/GC_OP_LightningSnapshotGenerator.h"
#include "../core.h"

void SetupLuaClassGC_OP_LightningSnapshotGenerator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_LightningSnapshotGenerator>("C_OP_LightningSnapshotGenerator")
        .addProperty("CPSnapshot", &GC_OP_LightningSnapshotGenerator::GetCPSnapshot, &GC_OP_LightningSnapshotGenerator::SetCPSnapshot)
        .addProperty("CPStartPnt", &GC_OP_LightningSnapshotGenerator::GetCPStartPnt, &GC_OP_LightningSnapshotGenerator::SetCPStartPnt)
        .addProperty("CPEndPnt", &GC_OP_LightningSnapshotGenerator::GetCPEndPnt, &GC_OP_LightningSnapshotGenerator::SetCPEndPnt)
        .addProperty("Segments", &GC_OP_LightningSnapshotGenerator::GetSegments, &GC_OP_LightningSnapshotGenerator::SetSegments)
        .addProperty("Offset", &GC_OP_LightningSnapshotGenerator::GetOffset, &GC_OP_LightningSnapshotGenerator::SetOffset)
        .addProperty("OffsetDecay", &GC_OP_LightningSnapshotGenerator::GetOffsetDecay, &GC_OP_LightningSnapshotGenerator::SetOffsetDecay)
        .addProperty("RecalcRate", &GC_OP_LightningSnapshotGenerator::GetRecalcRate, &GC_OP_LightningSnapshotGenerator::SetRecalcRate)
        .addProperty("UVScale", &GC_OP_LightningSnapshotGenerator::GetUVScale, &GC_OP_LightningSnapshotGenerator::SetUVScale)
        .addProperty("UVOffset", &GC_OP_LightningSnapshotGenerator::GetUVOffset, &GC_OP_LightningSnapshotGenerator::SetUVOffset)
        .addProperty("SplitRate", &GC_OP_LightningSnapshotGenerator::GetSplitRate, &GC_OP_LightningSnapshotGenerator::SetSplitRate)
        .addProperty("BranchTwist", &GC_OP_LightningSnapshotGenerator::GetBranchTwist, &GC_OP_LightningSnapshotGenerator::SetBranchTwist)
        .addProperty("BranchBehavior", &GC_OP_LightningSnapshotGenerator::GetBranchBehavior, &GC_OP_LightningSnapshotGenerator::SetBranchBehavior)
        .addProperty("RadiusStart", &GC_OP_LightningSnapshotGenerator::GetRadiusStart, &GC_OP_LightningSnapshotGenerator::SetRadiusStart)
        .addProperty("RadiusEnd", &GC_OP_LightningSnapshotGenerator::GetRadiusEnd, &GC_OP_LightningSnapshotGenerator::SetRadiusEnd)
        .addProperty("DedicatedPool", &GC_OP_LightningSnapshotGenerator::GetDedicatedPool, &GC_OP_LightningSnapshotGenerator::SetDedicatedPool)
        .endClass();
}