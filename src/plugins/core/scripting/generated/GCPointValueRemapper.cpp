#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointValueRemapper::GCPointValueRemapper(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointValueRemapper::GCPointValueRemapper(void *ptr) {
    m_ptr = ptr;
}
bool GCPointValueRemapper::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CPointValueRemapper", "m_bDisabled");
}
void GCPointValueRemapper::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_bDisabled", false, value);
}
bool GCPointValueRemapper::GetUpdateOnClient() const {
    return GetSchemaValue<bool>(m_ptr, "CPointValueRemapper", "m_bUpdateOnClient");
}
void GCPointValueRemapper::SetUpdateOnClient(bool value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_bUpdateOnClient", false, value);
}
uint64_t GCPointValueRemapper::GetInputType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPointValueRemapper", "m_nInputType");
}
void GCPointValueRemapper::SetInputType(uint64_t value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_nInputType", false, value);
}
std::string GCPointValueRemapper::GetRemapLineStartName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszRemapLineStartName").String();
}
void GCPointValueRemapper::SetRemapLineStartName(std::string value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszRemapLineStartName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCPointValueRemapper::GetRemapLineEndName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszRemapLineEndName").String();
}
void GCPointValueRemapper::SetRemapLineEndName(std::string value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszRemapLineEndName", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseEntity GCPointValueRemapper::GetRemapLineStart() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPointValueRemapper", "m_hRemapLineStart"));
    return value;
}
void GCPointValueRemapper::SetRemapLineStart(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'RemapLineStart' is not possible.\n");
}
GCBaseEntity GCPointValueRemapper::GetRemapLineEnd() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPointValueRemapper", "m_hRemapLineEnd"));
    return value;
}
void GCPointValueRemapper::SetRemapLineEnd(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'RemapLineEnd' is not possible.\n");
}
float GCPointValueRemapper::GetMaximumChangePerSecond() const {
    return GetSchemaValue<float>(m_ptr, "CPointValueRemapper", "m_flMaximumChangePerSecond");
}
void GCPointValueRemapper::SetMaximumChangePerSecond(float value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_flMaximumChangePerSecond", false, value);
}
float GCPointValueRemapper::GetDisengageDistance() const {
    return GetSchemaValue<float>(m_ptr, "CPointValueRemapper", "m_flDisengageDistance");
}
void GCPointValueRemapper::SetDisengageDistance(float value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_flDisengageDistance", false, value);
}
float GCPointValueRemapper::GetEngageDistance() const {
    return GetSchemaValue<float>(m_ptr, "CPointValueRemapper", "m_flEngageDistance");
}
void GCPointValueRemapper::SetEngageDistance(float value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_flEngageDistance", false, value);
}
bool GCPointValueRemapper::GetRequiresUseKey() const {
    return GetSchemaValue<bool>(m_ptr, "CPointValueRemapper", "m_bRequiresUseKey");
}
void GCPointValueRemapper::SetRequiresUseKey(bool value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_bRequiresUseKey", false, value);
}
uint64_t GCPointValueRemapper::GetOutputType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPointValueRemapper", "m_nOutputType");
}
void GCPointValueRemapper::SetOutputType(uint64_t value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_nOutputType", false, value);
}
std::string GCPointValueRemapper::GetOutputEntityName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszOutputEntityName").String();
}
void GCPointValueRemapper::SetOutputEntityName(std::string value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszOutputEntityName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCPointValueRemapper::GetOutputEntity2Name() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszOutputEntity2Name").String();
}
void GCPointValueRemapper::SetOutputEntity2Name(std::string value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszOutputEntity2Name", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCPointValueRemapper::GetOutputEntity3Name() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszOutputEntity3Name").String();
}
void GCPointValueRemapper::SetOutputEntity3Name(std::string value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszOutputEntity3Name", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCPointValueRemapper::GetOutputEntity4Name() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszOutputEntity4Name").String();
}
void GCPointValueRemapper::SetOutputEntity4Name(std::string value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszOutputEntity4Name", false, CUtlSymbolLarge(value.c_str()));
}
std::vector<GCBaseEntity*> GCPointValueRemapper::GetOutputEntities() const {
    CUtlVector<GCBaseEntity*>* vec = GetSchemaValue<CUtlVector<GCBaseEntity*>*>(m_ptr, "CPointValueRemapper", "m_hOutputEntities"); std::vector<GCBaseEntity*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCPointValueRemapper::SetOutputEntities(std::vector<GCBaseEntity*> value) {
    SetSchemaValueCUtlVector<GCBaseEntity*>(m_ptr, "CPointValueRemapper", "m_hOutputEntities", false, value);
}
uint64_t GCPointValueRemapper::GetHapticsType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPointValueRemapper", "m_nHapticsType");
}
void GCPointValueRemapper::SetHapticsType(uint64_t value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_nHapticsType", false, value);
}
uint64_t GCPointValueRemapper::GetMomentumType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPointValueRemapper", "m_nMomentumType");
}
void GCPointValueRemapper::SetMomentumType(uint64_t value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_nMomentumType", false, value);
}
float GCPointValueRemapper::GetMomentumModifier() const {
    return GetSchemaValue<float>(m_ptr, "CPointValueRemapper", "m_flMomentumModifier");
}
void GCPointValueRemapper::SetMomentumModifier(float value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_flMomentumModifier", false, value);
}
float GCPointValueRemapper::GetSnapValue() const {
    return GetSchemaValue<float>(m_ptr, "CPointValueRemapper", "m_flSnapValue");
}
void GCPointValueRemapper::SetSnapValue(float value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_flSnapValue", false, value);
}
float GCPointValueRemapper::GetCurrentMomentum() const {
    return GetSchemaValue<float>(m_ptr, "CPointValueRemapper", "m_flCurrentMomentum");
}
void GCPointValueRemapper::SetCurrentMomentum(float value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_flCurrentMomentum", false, value);
}
uint64_t GCPointValueRemapper::GetRatchetType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPointValueRemapper", "m_nRatchetType");
}
void GCPointValueRemapper::SetRatchetType(uint64_t value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_nRatchetType", false, value);
}
float GCPointValueRemapper::GetRatchetOffset() const {
    return GetSchemaValue<float>(m_ptr, "CPointValueRemapper", "m_flRatchetOffset");
}
void GCPointValueRemapper::SetRatchetOffset(float value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_flRatchetOffset", false, value);
}
float GCPointValueRemapper::GetInputOffset() const {
    return GetSchemaValue<float>(m_ptr, "CPointValueRemapper", "m_flInputOffset");
}
void GCPointValueRemapper::SetInputOffset(float value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_flInputOffset", false, value);
}
bool GCPointValueRemapper::GetEngaged() const {
    return GetSchemaValue<bool>(m_ptr, "CPointValueRemapper", "m_bEngaged");
}
void GCPointValueRemapper::SetEngaged(bool value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_bEngaged", false, value);
}
bool GCPointValueRemapper::GetFirstUpdate() const {
    return GetSchemaValue<bool>(m_ptr, "CPointValueRemapper", "m_bFirstUpdate");
}
void GCPointValueRemapper::SetFirstUpdate(bool value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_bFirstUpdate", false, value);
}
float GCPointValueRemapper::GetPreviousValue() const {
    return GetSchemaValue<float>(m_ptr, "CPointValueRemapper", "m_flPreviousValue");
}
void GCPointValueRemapper::SetPreviousValue(float value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_flPreviousValue", false, value);
}
float GCPointValueRemapper::GetPreviousUpdateTickTime() const {
    return GetSchemaValue<float>(m_ptr, "CPointValueRemapper", "m_flPreviousUpdateTickTime");
}
void GCPointValueRemapper::SetPreviousUpdateTickTime(float value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_flPreviousUpdateTickTime", false, value);
}
Vector GCPointValueRemapper::GetPreviousTestPoint() const {
    return GetSchemaValue<Vector>(m_ptr, "CPointValueRemapper", "m_vecPreviousTestPoint");
}
void GCPointValueRemapper::SetPreviousTestPoint(Vector value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_vecPreviousTestPoint", false, value);
}
GCBasePlayerPawn GCPointValueRemapper::GetUsingPlayer() const {
    GCBasePlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CPointValueRemapper", "m_hUsingPlayer"));
    return value;
}
void GCPointValueRemapper::SetUsingPlayer(GCBasePlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'UsingPlayer' is not possible.\n");
}
float GCPointValueRemapper::GetCustomOutputValue() const {
    return GetSchemaValue<float>(m_ptr, "CPointValueRemapper", "m_flCustomOutputValue");
}
void GCPointValueRemapper::SetCustomOutputValue(float value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_flCustomOutputValue", false, value);
}
std::string GCPointValueRemapper::GetSoundEngage() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszSoundEngage").String();
}
void GCPointValueRemapper::SetSoundEngage(std::string value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszSoundEngage", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCPointValueRemapper::GetSoundDisengage() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszSoundDisengage").String();
}
void GCPointValueRemapper::SetSoundDisengage(std::string value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszSoundDisengage", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCPointValueRemapper::GetSoundReachedValueZero() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszSoundReachedValueZero").String();
}
void GCPointValueRemapper::SetSoundReachedValueZero(std::string value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszSoundReachedValueZero", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCPointValueRemapper::GetSoundReachedValueOne() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszSoundReachedValueOne").String();
}
void GCPointValueRemapper::SetSoundReachedValueOne(std::string value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszSoundReachedValueOne", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCPointValueRemapper::GetSoundMovingLoop() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointValueRemapper", "m_iszSoundMovingLoop").String();
}
void GCPointValueRemapper::SetSoundMovingLoop(std::string value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_iszSoundMovingLoop", false, CUtlSymbolLarge(value.c_str()));
}
GCEntityIOOutput GCPointValueRemapper::GetOnReachedValueZero() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPointValueRemapper", "m_OnReachedValueZero"));
    return value;
}
void GCPointValueRemapper::SetOnReachedValueZero(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_OnReachedValueZero", false, value);
}
GCEntityIOOutput GCPointValueRemapper::GetOnReachedValueOne() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPointValueRemapper", "m_OnReachedValueOne"));
    return value;
}
void GCPointValueRemapper::SetOnReachedValueOne(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_OnReachedValueOne", false, value);
}
GCEntityIOOutput GCPointValueRemapper::GetOnReachedValueCustom() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPointValueRemapper", "m_OnReachedValueCustom"));
    return value;
}
void GCPointValueRemapper::SetOnReachedValueCustom(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_OnReachedValueCustom", false, value);
}
GCEntityIOOutput GCPointValueRemapper::GetOnEngage() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPointValueRemapper", "m_OnEngage"));
    return value;
}
void GCPointValueRemapper::SetOnEngage(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_OnEngage", false, value);
}
GCEntityIOOutput GCPointValueRemapper::GetOnDisengage() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPointValueRemapper", "m_OnDisengage"));
    return value;
}
void GCPointValueRemapper::SetOnDisengage(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPointValueRemapper", "m_OnDisengage", false, value);
}
std::string GCPointValueRemapper::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointValueRemapper::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCPointValueRemapper::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCPointValueRemapper::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointValueRemapper(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointValueRemapper>("CPointValueRemapper")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Disabled", &GCPointValueRemapper::GetDisabled, &GCPointValueRemapper::SetDisabled)
        .addProperty("UpdateOnClient", &GCPointValueRemapper::GetUpdateOnClient, &GCPointValueRemapper::SetUpdateOnClient)
        .addProperty("InputType", &GCPointValueRemapper::GetInputType, &GCPointValueRemapper::SetInputType)
        .addProperty("RemapLineStartName", &GCPointValueRemapper::GetRemapLineStartName, &GCPointValueRemapper::SetRemapLineStartName)
        .addProperty("RemapLineEndName", &GCPointValueRemapper::GetRemapLineEndName, &GCPointValueRemapper::SetRemapLineEndName)
        .addProperty("RemapLineStart", &GCPointValueRemapper::GetRemapLineStart, &GCPointValueRemapper::SetRemapLineStart)
        .addProperty("RemapLineEnd", &GCPointValueRemapper::GetRemapLineEnd, &GCPointValueRemapper::SetRemapLineEnd)
        .addProperty("MaximumChangePerSecond", &GCPointValueRemapper::GetMaximumChangePerSecond, &GCPointValueRemapper::SetMaximumChangePerSecond)
        .addProperty("DisengageDistance", &GCPointValueRemapper::GetDisengageDistance, &GCPointValueRemapper::SetDisengageDistance)
        .addProperty("EngageDistance", &GCPointValueRemapper::GetEngageDistance, &GCPointValueRemapper::SetEngageDistance)
        .addProperty("RequiresUseKey", &GCPointValueRemapper::GetRequiresUseKey, &GCPointValueRemapper::SetRequiresUseKey)
        .addProperty("OutputType", &GCPointValueRemapper::GetOutputType, &GCPointValueRemapper::SetOutputType)
        .addProperty("OutputEntityName", &GCPointValueRemapper::GetOutputEntityName, &GCPointValueRemapper::SetOutputEntityName)
        .addProperty("OutputEntity2Name", &GCPointValueRemapper::GetOutputEntity2Name, &GCPointValueRemapper::SetOutputEntity2Name)
        .addProperty("OutputEntity3Name", &GCPointValueRemapper::GetOutputEntity3Name, &GCPointValueRemapper::SetOutputEntity3Name)
        .addProperty("OutputEntity4Name", &GCPointValueRemapper::GetOutputEntity4Name, &GCPointValueRemapper::SetOutputEntity4Name)
        .addProperty("OutputEntities", &GCPointValueRemapper::GetOutputEntities, &GCPointValueRemapper::SetOutputEntities)
        .addProperty("HapticsType", &GCPointValueRemapper::GetHapticsType, &GCPointValueRemapper::SetHapticsType)
        .addProperty("MomentumType", &GCPointValueRemapper::GetMomentumType, &GCPointValueRemapper::SetMomentumType)
        .addProperty("MomentumModifier", &GCPointValueRemapper::GetMomentumModifier, &GCPointValueRemapper::SetMomentumModifier)
        .addProperty("SnapValue", &GCPointValueRemapper::GetSnapValue, &GCPointValueRemapper::SetSnapValue)
        .addProperty("CurrentMomentum", &GCPointValueRemapper::GetCurrentMomentum, &GCPointValueRemapper::SetCurrentMomentum)
        .addProperty("RatchetType", &GCPointValueRemapper::GetRatchetType, &GCPointValueRemapper::SetRatchetType)
        .addProperty("RatchetOffset", &GCPointValueRemapper::GetRatchetOffset, &GCPointValueRemapper::SetRatchetOffset)
        .addProperty("InputOffset", &GCPointValueRemapper::GetInputOffset, &GCPointValueRemapper::SetInputOffset)
        .addProperty("Engaged", &GCPointValueRemapper::GetEngaged, &GCPointValueRemapper::SetEngaged)
        .addProperty("FirstUpdate", &GCPointValueRemapper::GetFirstUpdate, &GCPointValueRemapper::SetFirstUpdate)
        .addProperty("PreviousValue", &GCPointValueRemapper::GetPreviousValue, &GCPointValueRemapper::SetPreviousValue)
        .addProperty("PreviousUpdateTickTime", &GCPointValueRemapper::GetPreviousUpdateTickTime, &GCPointValueRemapper::SetPreviousUpdateTickTime)
        .addProperty("PreviousTestPoint", &GCPointValueRemapper::GetPreviousTestPoint, &GCPointValueRemapper::SetPreviousTestPoint)
        .addProperty("UsingPlayer", &GCPointValueRemapper::GetUsingPlayer, &GCPointValueRemapper::SetUsingPlayer)
        .addProperty("CustomOutputValue", &GCPointValueRemapper::GetCustomOutputValue, &GCPointValueRemapper::SetCustomOutputValue)
        .addProperty("SoundEngage", &GCPointValueRemapper::GetSoundEngage, &GCPointValueRemapper::SetSoundEngage)
        .addProperty("SoundDisengage", &GCPointValueRemapper::GetSoundDisengage, &GCPointValueRemapper::SetSoundDisengage)
        .addProperty("SoundReachedValueZero", &GCPointValueRemapper::GetSoundReachedValueZero, &GCPointValueRemapper::SetSoundReachedValueZero)
        .addProperty("SoundReachedValueOne", &GCPointValueRemapper::GetSoundReachedValueOne, &GCPointValueRemapper::SetSoundReachedValueOne)
        .addProperty("SoundMovingLoop", &GCPointValueRemapper::GetSoundMovingLoop, &GCPointValueRemapper::SetSoundMovingLoop)
        .addProperty("OnReachedValueZero", &GCPointValueRemapper::GetOnReachedValueZero, &GCPointValueRemapper::SetOnReachedValueZero)
        .addProperty("OnReachedValueOne", &GCPointValueRemapper::GetOnReachedValueOne, &GCPointValueRemapper::SetOnReachedValueOne)
        .addProperty("OnReachedValueCustom", &GCPointValueRemapper::GetOnReachedValueCustom, &GCPointValueRemapper::SetOnReachedValueCustom)
        .addProperty("OnEngage", &GCPointValueRemapper::GetOnEngage, &GCPointValueRemapper::SetOnEngage)
        .addProperty("OnDisengage", &GCPointValueRemapper::GetOnDisengage, &GCPointValueRemapper::SetOnDisengage)
        .addProperty("Parent", &GCPointValueRemapper::GetParent, &GCPointValueRemapper::SetParent)
        .addFunction("ToPtr", &GCPointValueRemapper::ToPtr)
        .addFunction("IsValid", &GCPointValueRemapper::IsValid)
        .endClass();
}