#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncShatterglass::GCFuncShatterglass(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncShatterglass::GCFuncShatterglass(void *ptr) {
    m_ptr = ptr;
}
matrix3x4_t GCFuncShatterglass::GetMatPanelTransform() const {
    return GetSchemaValue<matrix3x4_t>(m_ptr, "CFuncShatterglass", "m_matPanelTransform");
}
void GCFuncShatterglass::SetMatPanelTransform(matrix3x4_t value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_matPanelTransform", false, value);
}
matrix3x4_t GCFuncShatterglass::GetMatPanelTransformWsTemp() const {
    return GetSchemaValue<matrix3x4_t>(m_ptr, "CFuncShatterglass", "m_matPanelTransformWsTemp");
}
void GCFuncShatterglass::SetMatPanelTransformWsTemp(matrix3x4_t value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_matPanelTransformWsTemp", false, value);
}
std::vector<uint32> GCFuncShatterglass::GetShatterGlassShards() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CFuncShatterglass", "m_vecShatterGlassShards"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFuncShatterglass::SetShatterGlassShards(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "CFuncShatterglass", "m_vecShatterGlassShards", false, value);
}
Vector2D GCFuncShatterglass::GetPanelSize() const {
    return GetSchemaValue<Vector2D>(m_ptr, "CFuncShatterglass", "m_PanelSize");
}
void GCFuncShatterglass::SetPanelSize(Vector2D value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_PanelSize", false, value);
}
Vector GCFuncShatterglass::GetPanelNormalWs() const {
    return GetSchemaValue<Vector>(m_ptr, "CFuncShatterglass", "m_vecPanelNormalWs");
}
void GCFuncShatterglass::SetPanelNormalWs(Vector value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_vecPanelNormalWs", false, value);
}
int32_t GCFuncShatterglass::GetNumShardsEverCreated() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFuncShatterglass", "m_nNumShardsEverCreated");
}
void GCFuncShatterglass::SetNumShardsEverCreated(int32_t value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_nNumShardsEverCreated", false, value);
}
float GCFuncShatterglass::GetLastShatterSoundEmitTime() const {
    return GetSchemaValue<float>(m_ptr, "CFuncShatterglass", "m_flLastShatterSoundEmitTime");
}
void GCFuncShatterglass::SetLastShatterSoundEmitTime(float value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_flLastShatterSoundEmitTime", false, value);
}
float GCFuncShatterglass::GetLastCleanupTime() const {
    return GetSchemaValue<float>(m_ptr, "CFuncShatterglass", "m_flLastCleanupTime");
}
void GCFuncShatterglass::SetLastCleanupTime(float value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_flLastCleanupTime", false, value);
}
float GCFuncShatterglass::GetInitAtTime() const {
    return GetSchemaValue<float>(m_ptr, "CFuncShatterglass", "m_flInitAtTime");
}
void GCFuncShatterglass::SetInitAtTime(float value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_flInitAtTime", false, value);
}
float GCFuncShatterglass::GetGlassThickness() const {
    return GetSchemaValue<float>(m_ptr, "CFuncShatterglass", "m_flGlassThickness");
}
void GCFuncShatterglass::SetGlassThickness(float value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_flGlassThickness", false, value);
}
float GCFuncShatterglass::GetSpawnInvulnerability() const {
    return GetSchemaValue<float>(m_ptr, "CFuncShatterglass", "m_flSpawnInvulnerability");
}
void GCFuncShatterglass::SetSpawnInvulnerability(float value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_flSpawnInvulnerability", false, value);
}
bool GCFuncShatterglass::GetBreakSilent() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncShatterglass", "m_bBreakSilent");
}
void GCFuncShatterglass::SetBreakSilent(bool value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_bBreakSilent", false, value);
}
bool GCFuncShatterglass::GetBreakShardless() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncShatterglass", "m_bBreakShardless");
}
void GCFuncShatterglass::SetBreakShardless(bool value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_bBreakShardless", false, value);
}
bool GCFuncShatterglass::GetBroken() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncShatterglass", "m_bBroken");
}
void GCFuncShatterglass::SetBroken(bool value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_bBroken", false, value);
}
bool GCFuncShatterglass::GetHasRateLimitedShards() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncShatterglass", "m_bHasRateLimitedShards");
}
void GCFuncShatterglass::SetHasRateLimitedShards(bool value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_bHasRateLimitedShards", false, value);
}
bool GCFuncShatterglass::GetGlassNavIgnore() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncShatterglass", "m_bGlassNavIgnore");
}
void GCFuncShatterglass::SetGlassNavIgnore(bool value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_bGlassNavIgnore", false, value);
}
bool GCFuncShatterglass::GetGlassInFrame() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncShatterglass", "m_bGlassInFrame");
}
void GCFuncShatterglass::SetGlassInFrame(bool value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_bGlassInFrame", false, value);
}
bool GCFuncShatterglass::GetStartBroken() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncShatterglass", "m_bStartBroken");
}
void GCFuncShatterglass::SetStartBroken(bool value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_bStartBroken", false, value);
}
uint8_t GCFuncShatterglass::GetInitialDamageType() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CFuncShatterglass", "m_iInitialDamageType");
}
void GCFuncShatterglass::SetInitialDamageType(uint8_t value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_iInitialDamageType", false, value);
}
std::string GCFuncShatterglass::GetDamagePositioningEntityName01() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncShatterglass", "m_szDamagePositioningEntityName01").String();
}
void GCFuncShatterglass::SetDamagePositioningEntityName01(std::string value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_szDamagePositioningEntityName01", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFuncShatterglass::GetDamagePositioningEntityName02() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncShatterglass", "m_szDamagePositioningEntityName02").String();
}
void GCFuncShatterglass::SetDamagePositioningEntityName02(std::string value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_szDamagePositioningEntityName02", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFuncShatterglass::GetDamagePositioningEntityName03() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncShatterglass", "m_szDamagePositioningEntityName03").String();
}
void GCFuncShatterglass::SetDamagePositioningEntityName03(std::string value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_szDamagePositioningEntityName03", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFuncShatterglass::GetDamagePositioningEntityName04() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncShatterglass", "m_szDamagePositioningEntityName04").String();
}
void GCFuncShatterglass::SetDamagePositioningEntityName04(std::string value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_szDamagePositioningEntityName04", false, CUtlSymbolLarge(value.c_str()));
}
std::vector<Vector> GCFuncShatterglass::GetInitialDamagePositions() const {
    CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CFuncShatterglass", "m_vInitialDamagePositions"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFuncShatterglass::SetInitialDamagePositions(std::vector<Vector> value) {
    SetSchemaValueCUtlVector<Vector>(m_ptr, "CFuncShatterglass", "m_vInitialDamagePositions", false, value);
}
std::vector<Vector> GCFuncShatterglass::GetExtraDamagePositions() const {
    CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CFuncShatterglass", "m_vExtraDamagePositions"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFuncShatterglass::SetExtraDamagePositions(std::vector<Vector> value) {
    SetSchemaValueCUtlVector<Vector>(m_ptr, "CFuncShatterglass", "m_vExtraDamagePositions", false, value);
}
GCEntityIOOutput GCFuncShatterglass::GetOnBroken() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CFuncShatterglass", "m_OnBroken"));
    return value;
}
void GCFuncShatterglass::SetOnBroken(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_OnBroken", false, value);
}
uint8_t GCFuncShatterglass::GetSurfaceType() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CFuncShatterglass", "m_iSurfaceType");
}
void GCFuncShatterglass::SetSurfaceType(uint8_t value) {
    SetSchemaValue(m_ptr, "CFuncShatterglass", "m_iSurfaceType", false, value);
}
std::string GCFuncShatterglass::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncShatterglass::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCFuncShatterglass::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCFuncShatterglass::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncShatterglass(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncShatterglass>("CFuncShatterglass")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MatPanelTransform", &GCFuncShatterglass::GetMatPanelTransform, &GCFuncShatterglass::SetMatPanelTransform)
        .addProperty("MatPanelTransformWsTemp", &GCFuncShatterglass::GetMatPanelTransformWsTemp, &GCFuncShatterglass::SetMatPanelTransformWsTemp)
        .addProperty("ShatterGlassShards", &GCFuncShatterglass::GetShatterGlassShards, &GCFuncShatterglass::SetShatterGlassShards)
        .addProperty("PanelSize", &GCFuncShatterglass::GetPanelSize, &GCFuncShatterglass::SetPanelSize)
        .addProperty("PanelNormalWs", &GCFuncShatterglass::GetPanelNormalWs, &GCFuncShatterglass::SetPanelNormalWs)
        .addProperty("NumShardsEverCreated", &GCFuncShatterglass::GetNumShardsEverCreated, &GCFuncShatterglass::SetNumShardsEverCreated)
        .addProperty("LastShatterSoundEmitTime", &GCFuncShatterglass::GetLastShatterSoundEmitTime, &GCFuncShatterglass::SetLastShatterSoundEmitTime)
        .addProperty("LastCleanupTime", &GCFuncShatterglass::GetLastCleanupTime, &GCFuncShatterglass::SetLastCleanupTime)
        .addProperty("InitAtTime", &GCFuncShatterglass::GetInitAtTime, &GCFuncShatterglass::SetInitAtTime)
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
        .addProperty("Parent", &GCFuncShatterglass::GetParent, &GCFuncShatterglass::SetParent)
        .addFunction("ToPtr", &GCFuncShatterglass::ToPtr)
        .addFunction("IsValid", &GCFuncShatterglass::IsValid)
        .endClass();
}