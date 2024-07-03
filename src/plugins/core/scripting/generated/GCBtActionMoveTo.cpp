#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBtActionMoveTo::GCBtActionMoveTo(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBtActionMoveTo::GCBtActionMoveTo(void *ptr) {
    m_ptr = ptr;
}
std::string GCBtActionMoveTo::GetDestinationInputKey() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CBtActionMoveTo", "m_szDestinationInputKey").Get();
}
void GCBtActionMoveTo::SetDestinationInputKey(std::string value) {
    SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_szDestinationInputKey", false, CUtlString(value.c_str()));
}
std::string GCBtActionMoveTo::GetHidingSpotInputKey() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CBtActionMoveTo", "m_szHidingSpotInputKey").Get();
}
void GCBtActionMoveTo::SetHidingSpotInputKey(std::string value) {
    SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_szHidingSpotInputKey", false, CUtlString(value.c_str()));
}
std::string GCBtActionMoveTo::GetThreatInputKey() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CBtActionMoveTo", "m_szThreatInputKey").Get();
}
void GCBtActionMoveTo::SetThreatInputKey(std::string value) {
    SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_szThreatInputKey", false, CUtlString(value.c_str()));
}
Vector GCBtActionMoveTo::GetDestination() const {
    return GetSchemaValue<Vector>(m_ptr, "CBtActionMoveTo", "m_vecDestination");
}
void GCBtActionMoveTo::SetDestination(Vector value) {
    SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_vecDestination", false, value);
}
bool GCBtActionMoveTo::GetAutoLookAdjust() const {
    return GetSchemaValue<bool>(m_ptr, "CBtActionMoveTo", "m_bAutoLookAdjust");
}
void GCBtActionMoveTo::SetAutoLookAdjust(bool value) {
    SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_bAutoLookAdjust", false, value);
}
bool GCBtActionMoveTo::GetComputePath() const {
    return GetSchemaValue<bool>(m_ptr, "CBtActionMoveTo", "m_bComputePath");
}
void GCBtActionMoveTo::SetComputePath(bool value) {
    SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_bComputePath", false, value);
}
float GCBtActionMoveTo::GetDamagingAreasPenaltyCost() const {
    return GetSchemaValue<float>(m_ptr, "CBtActionMoveTo", "m_flDamagingAreasPenaltyCost");
}
void GCBtActionMoveTo::SetDamagingAreasPenaltyCost(float value) {
    SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_flDamagingAreasPenaltyCost", false, value);
}
GCountdownTimer GCBtActionMoveTo::GetCheckApproximateCornersTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CBtActionMoveTo", "m_CheckApproximateCornersTimer"));
    return value;
}
void GCBtActionMoveTo::SetCheckApproximateCornersTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_CheckApproximateCornersTimer", false, value);
}
GCountdownTimer GCBtActionMoveTo::GetCheckHighPriorityItem() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CBtActionMoveTo", "m_CheckHighPriorityItem"));
    return value;
}
void GCBtActionMoveTo::SetCheckHighPriorityItem(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_CheckHighPriorityItem", false, value);
}
GCountdownTimer GCBtActionMoveTo::GetRepathTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CBtActionMoveTo", "m_RepathTimer"));
    return value;
}
void GCBtActionMoveTo::SetRepathTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_RepathTimer", false, value);
}
float GCBtActionMoveTo::GetArrivalEpsilon() const {
    return GetSchemaValue<float>(m_ptr, "CBtActionMoveTo", "m_flArrivalEpsilon");
}
void GCBtActionMoveTo::SetArrivalEpsilon(float value) {
    SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_flArrivalEpsilon", false, value);
}
float GCBtActionMoveTo::GetAdditionalArrivalEpsilon2D() const {
    return GetSchemaValue<float>(m_ptr, "CBtActionMoveTo", "m_flAdditionalArrivalEpsilon2D");
}
void GCBtActionMoveTo::SetAdditionalArrivalEpsilon2D(float value) {
    SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_flAdditionalArrivalEpsilon2D", false, value);
}
float GCBtActionMoveTo::GetHidingSpotCheckDistanceThreshold() const {
    return GetSchemaValue<float>(m_ptr, "CBtActionMoveTo", "m_flHidingSpotCheckDistanceThreshold");
}
void GCBtActionMoveTo::SetHidingSpotCheckDistanceThreshold(float value) {
    SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_flHidingSpotCheckDistanceThreshold", false, value);
}
float GCBtActionMoveTo::GetNearestAreaDistanceThreshold() const {
    return GetSchemaValue<float>(m_ptr, "CBtActionMoveTo", "m_flNearestAreaDistanceThreshold");
}
void GCBtActionMoveTo::SetNearestAreaDistanceThreshold(float value) {
    SetSchemaValue(m_ptr, "CBtActionMoveTo", "m_flNearestAreaDistanceThreshold", false, value);
}
std::string GCBtActionMoveTo::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBtActionMoveTo::IsValid() {
    return (m_ptr != nullptr);
}
GCBtNode GCBtActionMoveTo::GetParent() const {
    GCBtNode value(m_ptr);
    return value;
}
void GCBtActionMoveTo::SetParent(GCBtNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBtActionMoveTo(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBtActionMoveTo>("CBtActionMoveTo")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DestinationInputKey", &GCBtActionMoveTo::GetDestinationInputKey, &GCBtActionMoveTo::SetDestinationInputKey)
        .addProperty("HidingSpotInputKey", &GCBtActionMoveTo::GetHidingSpotInputKey, &GCBtActionMoveTo::SetHidingSpotInputKey)
        .addProperty("ThreatInputKey", &GCBtActionMoveTo::GetThreatInputKey, &GCBtActionMoveTo::SetThreatInputKey)
        .addProperty("Destination", &GCBtActionMoveTo::GetDestination, &GCBtActionMoveTo::SetDestination)
        .addProperty("AutoLookAdjust", &GCBtActionMoveTo::GetAutoLookAdjust, &GCBtActionMoveTo::SetAutoLookAdjust)
        .addProperty("ComputePath", &GCBtActionMoveTo::GetComputePath, &GCBtActionMoveTo::SetComputePath)
        .addProperty("DamagingAreasPenaltyCost", &GCBtActionMoveTo::GetDamagingAreasPenaltyCost, &GCBtActionMoveTo::SetDamagingAreasPenaltyCost)
        .addProperty("CheckApproximateCornersTimer", &GCBtActionMoveTo::GetCheckApproximateCornersTimer, &GCBtActionMoveTo::SetCheckApproximateCornersTimer)
        .addProperty("CheckHighPriorityItem", &GCBtActionMoveTo::GetCheckHighPriorityItem, &GCBtActionMoveTo::SetCheckHighPriorityItem)
        .addProperty("RepathTimer", &GCBtActionMoveTo::GetRepathTimer, &GCBtActionMoveTo::SetRepathTimer)
        .addProperty("ArrivalEpsilon", &GCBtActionMoveTo::GetArrivalEpsilon, &GCBtActionMoveTo::SetArrivalEpsilon)
        .addProperty("AdditionalArrivalEpsilon2D", &GCBtActionMoveTo::GetAdditionalArrivalEpsilon2D, &GCBtActionMoveTo::SetAdditionalArrivalEpsilon2D)
        .addProperty("HidingSpotCheckDistanceThreshold", &GCBtActionMoveTo::GetHidingSpotCheckDistanceThreshold, &GCBtActionMoveTo::SetHidingSpotCheckDistanceThreshold)
        .addProperty("NearestAreaDistanceThreshold", &GCBtActionMoveTo::GetNearestAreaDistanceThreshold, &GCBtActionMoveTo::SetNearestAreaDistanceThreshold)
        .addProperty("Parent", &GCBtActionMoveTo::GetParent, &GCBtActionMoveTo::SetParent)
        .addFunction("ToPtr", &GCBtActionMoveTo::ToPtr)
        .addFunction("IsValid", &GCBtActionMoveTo::IsValid)
        .endClass();
}