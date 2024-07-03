#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleSystem::GCParticleSystem(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleSystem::GCParticleSystem(void *ptr) {
    m_ptr = ptr;
}
std::string GCParticleSystem::GetSnapshotFileName() const {
    return GetSchemaValuePtr<char>(m_ptr, "CParticleSystem", "m_szSnapshotFileName");
}
void GCParticleSystem::SetSnapshotFileName(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CParticleSystem", "m_szSnapshotFileName", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 512);
}
bool GCParticleSystem::GetActive() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleSystem", "m_bActive");
}
void GCParticleSystem::SetActive(bool value) {
    SetSchemaValue(m_ptr, "CParticleSystem", "m_bActive", false, value);
}
bool GCParticleSystem::GetFrozen() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleSystem", "m_bFrozen");
}
void GCParticleSystem::SetFrozen(bool value) {
    SetSchemaValue(m_ptr, "CParticleSystem", "m_bFrozen", false, value);
}
float GCParticleSystem::GetFreezeTransitionDuration() const {
    return GetSchemaValue<float>(m_ptr, "CParticleSystem", "m_flFreezeTransitionDuration");
}
void GCParticleSystem::SetFreezeTransitionDuration(float value) {
    SetSchemaValue(m_ptr, "CParticleSystem", "m_flFreezeTransitionDuration", false, value);
}
int32_t GCParticleSystem::GetStopType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleSystem", "m_nStopType");
}
void GCParticleSystem::SetStopType(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleSystem", "m_nStopType", false, value);
}
bool GCParticleSystem::GetAnimateDuringGameplayPause() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleSystem", "m_bAnimateDuringGameplayPause");
}
void GCParticleSystem::SetAnimateDuringGameplayPause(bool value) {
    SetSchemaValue(m_ptr, "CParticleSystem", "m_bAnimateDuringGameplayPause", false, value);
}
float GCParticleSystem::GetStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CParticleSystem", "m_flStartTime");
}
void GCParticleSystem::SetStartTime(float value) {
    SetSchemaValue(m_ptr, "CParticleSystem", "m_flStartTime", false, value);
}
float GCParticleSystem::GetPreSimTime() const {
    return GetSchemaValue<float>(m_ptr, "CParticleSystem", "m_flPreSimTime");
}
void GCParticleSystem::SetPreSimTime(float value) {
    SetSchemaValue(m_ptr, "CParticleSystem", "m_flPreSimTime", false, value);
}
std::vector<Vector> GCParticleSystem::GetServerControlPoints() const {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CParticleSystem", "m_vServerControlPoints"); std::vector<Vector> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCParticleSystem::SetServerControlPoints(std::vector<Vector> value) {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CParticleSystem", "m_vServerControlPoints"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CParticleSystem", "m_vServerControlPoints", false, outValue);
}
std::vector<uint8_t> GCParticleSystem::GetServerControlPointAssignments() const {
    uint8_t* outValue = GetSchemaValue<uint8_t*>(m_ptr, "CParticleSystem", "m_iServerControlPointAssignments"); std::vector<uint8_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCParticleSystem::SetServerControlPointAssignments(std::vector<uint8_t> value) {
    uint8_t* outValue = GetSchemaValue<uint8_t*>(m_ptr, "CParticleSystem", "m_iServerControlPointAssignments"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CParticleSystem", "m_iServerControlPointAssignments", false, outValue);
}
std::vector<GCBaseEntity*> GCParticleSystem::GetControlPointEnts() const {
    GCBaseEntity** outValue = GetSchemaValue<GCBaseEntity**>(m_ptr, "CParticleSystem", "m_hControlPointEnts"); std::vector<GCBaseEntity*> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCParticleSystem::SetControlPointEnts(std::vector<GCBaseEntity*> value) {
    GCBaseEntity** outValue = GetSchemaValue<GCBaseEntity**>(m_ptr, "CParticleSystem", "m_hControlPointEnts"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CParticleSystem", "m_hControlPointEnts", false, outValue);
}
bool GCParticleSystem::GetNoSave() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleSystem", "m_bNoSave");
}
void GCParticleSystem::SetNoSave(bool value) {
    SetSchemaValue(m_ptr, "CParticleSystem", "m_bNoSave", false, value);
}
bool GCParticleSystem::GetNoFreeze() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleSystem", "m_bNoFreeze");
}
void GCParticleSystem::SetNoFreeze(bool value) {
    SetSchemaValue(m_ptr, "CParticleSystem", "m_bNoFreeze", false, value);
}
bool GCParticleSystem::GetNoRamp() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleSystem", "m_bNoRamp");
}
void GCParticleSystem::SetNoRamp(bool value) {
    SetSchemaValue(m_ptr, "CParticleSystem", "m_bNoRamp", false, value);
}
bool GCParticleSystem::GetStartActive() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleSystem", "m_bStartActive");
}
void GCParticleSystem::SetStartActive(bool value) {
    SetSchemaValue(m_ptr, "CParticleSystem", "m_bStartActive", false, value);
}
std::string GCParticleSystem::GetEffectName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CParticleSystem", "m_iszEffectName").String();
}
void GCParticleSystem::SetEffectName(std::string value) {
    SetSchemaValue(m_ptr, "CParticleSystem", "m_iszEffectName", false, CUtlSymbolLarge(value.c_str()));
}
std::vector<CUtlSymbolLarge> GCParticleSystem::GetControlPointNames() const {
    CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CParticleSystem", "m_iszControlPointNames"); std::vector<CUtlSymbolLarge> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCParticleSystem::SetControlPointNames(std::vector<CUtlSymbolLarge> value) {
    CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CParticleSystem", "m_iszControlPointNames"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CParticleSystem", "m_iszControlPointNames", false, outValue);
}
int32_t GCParticleSystem::GetDataCP() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleSystem", "m_nDataCP");
}
void GCParticleSystem::SetDataCP(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleSystem", "m_nDataCP", false, value);
}
Vector GCParticleSystem::GetDataCPValue() const {
    return GetSchemaValue<Vector>(m_ptr, "CParticleSystem", "m_vecDataCPValue");
}
void GCParticleSystem::SetDataCPValue(Vector value) {
    SetSchemaValue(m_ptr, "CParticleSystem", "m_vecDataCPValue", false, value);
}
int32_t GCParticleSystem::GetTintCP() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleSystem", "m_nTintCP");
}
void GCParticleSystem::SetTintCP(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleSystem", "m_nTintCP", false, value);
}
Color GCParticleSystem::GetTint() const {
    return GetSchemaValue<Color>(m_ptr, "CParticleSystem", "m_clrTint");
}
void GCParticleSystem::SetTint(Color value) {
    SetSchemaValue(m_ptr, "CParticleSystem", "m_clrTint", false, value);
}
std::string GCParticleSystem::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleSystem::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCParticleSystem::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCParticleSystem::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCParticleSystem(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleSystem>("CParticleSystem")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SnapshotFileName", &GCParticleSystem::GetSnapshotFileName, &GCParticleSystem::SetSnapshotFileName)
        .addProperty("Active", &GCParticleSystem::GetActive, &GCParticleSystem::SetActive)
        .addProperty("Frozen", &GCParticleSystem::GetFrozen, &GCParticleSystem::SetFrozen)
        .addProperty("FreezeTransitionDuration", &GCParticleSystem::GetFreezeTransitionDuration, &GCParticleSystem::SetFreezeTransitionDuration)
        .addProperty("StopType", &GCParticleSystem::GetStopType, &GCParticleSystem::SetStopType)
        .addProperty("AnimateDuringGameplayPause", &GCParticleSystem::GetAnimateDuringGameplayPause, &GCParticleSystem::SetAnimateDuringGameplayPause)
        .addProperty("StartTime", &GCParticleSystem::GetStartTime, &GCParticleSystem::SetStartTime)
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
        .addProperty("Parent", &GCParticleSystem::GetParent, &GCParticleSystem::SetParent)
        .addFunction("ToPtr", &GCParticleSystem::ToPtr)
        .addFunction("IsValid", &GCParticleSystem::IsValid)
        .endClass();
}