#include "../../../core/scripting/generated/classes/GCFuncShatterglass.h"
#include "../core.h"

void SetupLuaClassGCFuncShatterglass(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncShatterglass>("CFuncShatterglass")
        .addProperty("MatPanelTransform", &GCFuncShatterglass::GetMatPanelTransform, &GCFuncShatterglass::SetMatPanelTransform)
        .addProperty("MatPanelTransformWsTemp", &GCFuncShatterglass::GetMatPanelTransformWsTemp, &GCFuncShatterglass::SetMatPanelTransformWsTemp)
        .addProperty("ShatterGlassShards", &GCFuncShatterglass::GetShatterGlassShards, &GCFuncShatterglass::SetShatterGlassShards)
        .addProperty("PanelSize", &GCFuncShatterglass::GetPanelSize, &GCFuncShatterglass::SetPanelSize)
        .addProperty("PanelNormalWs", &GCFuncShatterglass::GetPanelNormalWs, &GCFuncShatterglass::SetPanelNormalWs)
        .addProperty("NumShardsEverCreated", &GCFuncShatterglass::GetNumShardsEverCreated, &GCFuncShatterglass::SetNumShardsEverCreated)
        .addProperty("GlassThickness", &GCFuncShatterglass::GetGlassThickness, &GCFuncShatterglass::SetGlassThickness)
        .addProperty("SpawnInvulnerability", &GCFuncShatterglass::GetSpawnInvulnerability, &GCFuncShatterglass::SetSpawnInvulnerability)
        .addProperty("BreakSilent", &GCFuncShatterglass::GetBreakSilent, &GCFuncShatterglass::SetBreakSilent)
        .addProperty("BreakShardless", &GCFuncShatterglass::GetBreakShardless, &GCFuncShatterglass::SetBreakShardless)
        .addProperty("Broken", &GCFuncShatterglass::GetBroken, &GCFuncShatterglass::SetBroken)
        .addProperty("HasRateLimitedShards", &GCFuncShatterglass::GetHasRateLimitedShards, &GCFuncShatterglass::SetHasRateLimitedShards)
        .addProperty("GlassNavIgnore", &GCFuncShatterglass::GetGlassNavIgnore, &GCFuncShatterglass::SetGlassNavIgnore)
        .addProperty("GlassInFrame", &GCFuncShatterglass::GetGlassInFrame, &GCFuncShatterglass::SetGlassInFrame)
        .addProperty("StartBroken", &GCFuncShatterglass::GetStartBroken, &GCFuncShatterglass::SetStartBroken)
        .addProperty("InitialDamageType", &GCFuncShatterglass::GetInitialDamageType, &GCFuncShatterglass::SetInitialDamageType)
        .addProperty("DamagePositioningEntityName01", &GCFuncShatterglass::GetDamagePositioningEntityName01, &GCFuncShatterglass::SetDamagePositioningEntityName01)
        .addProperty("DamagePositioningEntityName02", &GCFuncShatterglass::GetDamagePositioningEntityName02, &GCFuncShatterglass::SetDamagePositioningEntityName02)
        .addProperty("DamagePositioningEntityName03", &GCFuncShatterglass::GetDamagePositioningEntityName03, &GCFuncShatterglass::SetDamagePositioningEntityName03)
        .addProperty("DamagePositioningEntityName04", &GCFuncShatterglass::GetDamagePositioningEntityName04, &GCFuncShatterglass::SetDamagePositioningEntityName04)
        .addProperty("InitialDamagePositions", &GCFuncShatterglass::GetInitialDamagePositions, &GCFuncShatterglass::SetInitialDamagePositions)
        .addProperty("ExtraDamagePositions", &GCFuncShatterglass::GetExtraDamagePositions, &GCFuncShatterglass::SetExtraDamagePositions)
        .addProperty("OnBroken", &GCFuncShatterglass::GetOnBroken, &GCFuncShatterglass::SetOnBroken)
        .addProperty("SurfaceType", &GCFuncShatterglass::GetSurfaceType, &GCFuncShatterglass::SetSurfaceType)
        .endClass();
}