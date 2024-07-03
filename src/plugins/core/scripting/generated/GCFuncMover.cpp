#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncMover::GCFuncMover(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncMover::GCFuncMover(void *ptr) {
    m_ptr = ptr;
}
std::string GCFuncMover::GetPathName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncMover", "m_iszPathName").String();
}
void GCFuncMover::SetPathName(std::string value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_iszPathName", false, CUtlSymbolLarge(value.c_str()));
}
GCPathMover GCFuncMover::GetPathMover() const {
    GCPathMover value(*GetSchemaValuePtr<void*>(m_ptr, "CFuncMover", "m_hPathMover"));
    return value;
}
void GCFuncMover::SetPathMover(GCPathMover* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PathMover' is not possible.\n");
}
std::string GCFuncMover::GetPathNodeStart() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncMover", "m_iszPathNodeStart").String();
}
void GCFuncMover::SetPathNodeStart(std::string value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_iszPathNodeStart", false, CUtlSymbolLarge(value.c_str()));
}
GCFuncMover GCFuncMover::GetMoveType() const {
    GCFuncMover value(GetSchemaPtr(m_ptr, "CFuncMover", "m_eMoveType"));
    return value;
}
void GCFuncMover::SetMoveType(GCFuncMover value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_eMoveType", false, value);
}
bool GCFuncMover::GetIsReversing() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncMover", "m_bIsReversing");
}
void GCFuncMover::SetIsReversing(bool value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_bIsReversing", false, value);
}
Vector GCFuncMover::GetTarget() const {
    return GetSchemaValue<Vector>(m_ptr, "CFuncMover", "m_vTarget");
}
void GCFuncMover::SetTarget(Vector value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_vTarget", false, value);
}
float GCFuncMover::GetStartSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CFuncMover", "m_flStartSpeed");
}
void GCFuncMover::SetStartSpeed(float value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_flStartSpeed", false, value);
}
float GCFuncMover::GetPathLocation() const {
    return GetSchemaValue<float>(m_ptr, "CFuncMover", "m_flPathLocation");
}
void GCFuncMover::SetPathLocation(float value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_flPathLocation", false, value);
}
float GCFuncMover::GetT() const {
    return GetSchemaValue<float>(m_ptr, "CFuncMover", "m_flT");
}
void GCFuncMover::SetT(float value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_flT", false, value);
}
int32_t GCFuncMover::GetCurrentNodeIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFuncMover", "m_nCurrentNodeIndex");
}
void GCFuncMover::SetCurrentNodeIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_nCurrentNodeIndex", false, value);
}
int32_t GCFuncMover::GetPreviousNodeIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFuncMover", "m_nPreviousNodeIndex");
}
void GCFuncMover::SetPreviousNodeIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_nPreviousNodeIndex", false, value);
}
bool GCFuncMover::GetFixedOrientation() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncMover", "m_bFixedOrientation");
}
void GCFuncMover::SetFixedOrientation(bool value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_bFixedOrientation", false, value);
}
bool GCFuncMover::GetFixedPitch() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncMover", "m_bFixedPitch");
}
void GCFuncMover::SetFixedPitch(bool value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_bFixedPitch", false, value);
}
uint64_t GCFuncMover::GetSolidType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CFuncMover", "m_eSolidType");
}
void GCFuncMover::SetSolidType(uint64_t value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_eSolidType", false, value);
}
bool GCFuncMover::GetIsMoving() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncMover", "m_bIsMoving");
}
void GCFuncMover::SetIsMoving(bool value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_bIsMoving", false, value);
}
float GCFuncMover::GetTimeToReachMaxSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CFuncMover", "m_flTimeToReachMaxSpeed");
}
void GCFuncMover::SetTimeToReachMaxSpeed(float value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_flTimeToReachMaxSpeed", false, value);
}
float GCFuncMover::GetTimeToReachZeroSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CFuncMover", "m_flTimeToReachZeroSpeed");
}
void GCFuncMover::SetTimeToReachZeroSpeed(float value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_flTimeToReachZeroSpeed", false, value);
}
float GCFuncMover::GetTimeMovementStart() const {
    return GetSchemaValue<float>(m_ptr, "CFuncMover", "m_flTimeMovementStart");
}
void GCFuncMover::SetTimeMovementStart(float value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_flTimeMovementStart", false, value);
}
float GCFuncMover::GetTimeMovementStop() const {
    return GetSchemaValue<float>(m_ptr, "CFuncMover", "m_flTimeMovementStop");
}
void GCFuncMover::SetTimeMovementStop(float value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_flTimeMovementStop", false, value);
}
GCMoverPathNode GCFuncMover::GetStopAtNode() const {
    GCMoverPathNode value(*GetSchemaValuePtr<void*>(m_ptr, "CFuncMover", "m_hStopAtNode"));
    return value;
}
void GCFuncMover::SetStopAtNode(GCMoverPathNode* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'StopAtNode' is not possible.\n");
}
float GCFuncMover::GetPathLocationToBeginStop() const {
    return GetSchemaValue<float>(m_ptr, "CFuncMover", "m_flPathLocationToBeginStop");
}
void GCFuncMover::SetPathLocationToBeginStop(float value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_flPathLocationToBeginStop", false, value);
}
bool GCFuncMover::GetMatchPathNodeUp() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncMover", "m_bMatchPathNodeUp");
}
void GCFuncMover::SetMatchPathNodeUp(bool value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_bMatchPathNodeUp", false, value);
}
bool GCFuncMover::GetFacePlayer() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncMover", "m_bFacePlayer");
}
void GCFuncMover::SetFacePlayer(bool value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_bFacePlayer", false, value);
}
float GCFuncMover::GetTimeStartRoll() const {
    return GetSchemaValue<float>(m_ptr, "CFuncMover", "m_flTimeStartRoll");
}
void GCFuncMover::SetTimeStartRoll(float value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_flTimeStartRoll", false, value);
}
Vector GCFuncMover::GetOriginalUp() const {
    return GetSchemaValue<Vector>(m_ptr, "CFuncMover", "m_vOriginalUp");
}
void GCFuncMover::SetOriginalUp(Vector value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_vOriginalUp", false, value);
}
float GCFuncMover::GetTimeToRollToNewUp() const {
    return GetSchemaValue<float>(m_ptr, "CFuncMover", "m_flTimeToRollToNewUp");
}
void GCFuncMover::SetTimeToRollToNewUp(float value) {
    SetSchemaValue(m_ptr, "CFuncMover", "m_flTimeToRollToNewUp", false, value);
}
std::string GCFuncMover::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncMover::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCFuncMover::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCFuncMover::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncMover(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncMover>("CFuncMover")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PathName", &GCFuncMover::GetPathName, &GCFuncMover::SetPathName)
        .addProperty("PathMover", &GCFuncMover::GetPathMover, &GCFuncMover::SetPathMover)
        .addProperty("PathNodeStart", &GCFuncMover::GetPathNodeStart, &GCFuncMover::SetPathNodeStart)
        .addProperty("MoveType", &GCFuncMover::GetMoveType, &GCFuncMover::SetMoveType)
        .addProperty("IsReversing", &GCFuncMover::GetIsReversing, &GCFuncMover::SetIsReversing)
        .addProperty("Target", &GCFuncMover::GetTarget, &GCFuncMover::SetTarget)
        .addProperty("StartSpeed", &GCFuncMover::GetStartSpeed, &GCFuncMover::SetStartSpeed)
        .addProperty("PathLocation", &GCFuncMover::GetPathLocation, &GCFuncMover::SetPathLocation)
        .addProperty("T", &GCFuncMover::GetT, &GCFuncMover::SetT)
        .addProperty("CurrentNodeIndex", &GCFuncMover::GetCurrentNodeIndex, &GCFuncMover::SetCurrentNodeIndex)
        .addProperty("PreviousNodeIndex", &GCFuncMover::GetPreviousNodeIndex, &GCFuncMover::SetPreviousNodeIndex)
        .addProperty("FixedOrientation", &GCFuncMover::GetFixedOrientation, &GCFuncMover::SetFixedOrientation)
        .addProperty("FixedPitch", &GCFuncMover::GetFixedPitch, &GCFuncMover::SetFixedPitch)
        .addProperty("SolidType", &GCFuncMover::GetSolidType, &GCFuncMover::SetSolidType)
        .addProperty("IsMoving", &GCFuncMover::GetIsMoving, &GCFuncMover::SetIsMoving)
        .addProperty("TimeToReachMaxSpeed", &GCFuncMover::GetTimeToReachMaxSpeed, &GCFuncMover::SetTimeToReachMaxSpeed)
        .addProperty("TimeToReachZeroSpeed", &GCFuncMover::GetTimeToReachZeroSpeed, &GCFuncMover::SetTimeToReachZeroSpeed)
        .addProperty("TimeMovementStart", &GCFuncMover::GetTimeMovementStart, &GCFuncMover::SetTimeMovementStart)
        .addProperty("TimeMovementStop", &GCFuncMover::GetTimeMovementStop, &GCFuncMover::SetTimeMovementStop)
        .addProperty("StopAtNode", &GCFuncMover::GetStopAtNode, &GCFuncMover::SetStopAtNode)
        .addProperty("PathLocationToBeginStop", &GCFuncMover::GetPathLocationToBeginStop, &GCFuncMover::SetPathLocationToBeginStop)
        .addProperty("MatchPathNodeUp", &GCFuncMover::GetMatchPathNodeUp, &GCFuncMover::SetMatchPathNodeUp)
        .addProperty("FacePlayer", &GCFuncMover::GetFacePlayer, &GCFuncMover::SetFacePlayer)
        .addProperty("TimeStartRoll", &GCFuncMover::GetTimeStartRoll, &GCFuncMover::SetTimeStartRoll)
        .addProperty("OriginalUp", &GCFuncMover::GetOriginalUp, &GCFuncMover::SetOriginalUp)
        .addProperty("TimeToRollToNewUp", &GCFuncMover::GetTimeToRollToNewUp, &GCFuncMover::SetTimeToRollToNewUp)
        .addProperty("Parent", &GCFuncMover::GetParent, &GCFuncMover::SetParent)
        .addFunction("ToPtr", &GCFuncMover::ToPtr)
        .addFunction("IsValid", &GCFuncMover::IsValid)
        .endClass();
}