#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncTrackTrain::GCFuncTrackTrain(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncTrackTrain::GCFuncTrackTrain(void *ptr) {
    m_ptr = ptr;
}
GCPathTrack GCFuncTrackTrain::GetPpath() const {
    GCPathTrack value(*GetSchemaValuePtr<void*>(m_ptr, "CFuncTrackTrain", "m_ppath"));
    return value;
}
void GCFuncTrackTrain::SetPpath(GCPathTrack* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Ppath' is not possible.\n");
}
float GCFuncTrackTrain::GetLength() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_length");
}
void GCFuncTrackTrain::SetLength(float value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_length", false, value);
}
Vector GCFuncTrackTrain::GetPosPrev() const {
    return GetSchemaValue<Vector>(m_ptr, "CFuncTrackTrain", "m_vPosPrev");
}
void GCFuncTrackTrain::SetPosPrev(Vector value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_vPosPrev", false, value);
}
QAngle GCFuncTrackTrain::GetPrev() const {
    return GetSchemaValue<QAngle>(m_ptr, "CFuncTrackTrain", "m_angPrev");
}
void GCFuncTrackTrain::SetPrev(QAngle value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_angPrev", false, value);
}
Vector GCFuncTrackTrain::GetControlMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CFuncTrackTrain", "m_controlMins");
}
void GCFuncTrackTrain::SetControlMins(Vector value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_controlMins", false, value);
}
Vector GCFuncTrackTrain::GetControlMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CFuncTrackTrain", "m_controlMaxs");
}
void GCFuncTrackTrain::SetControlMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_controlMaxs", false, value);
}
Vector GCFuncTrackTrain::GetLastBlockPos() const {
    return GetSchemaValue<Vector>(m_ptr, "CFuncTrackTrain", "m_lastBlockPos");
}
void GCFuncTrackTrain::SetLastBlockPos(Vector value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_lastBlockPos", false, value);
}
int32_t GCFuncTrackTrain::GetLastBlockTick() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFuncTrackTrain", "m_lastBlockTick");
}
void GCFuncTrackTrain::SetLastBlockTick(int32_t value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_lastBlockTick", false, value);
}
float GCFuncTrackTrain::GetVolume() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flVolume");
}
void GCFuncTrackTrain::SetVolume(float value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flVolume", false, value);
}
float GCFuncTrackTrain::GetBank() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flBank");
}
void GCFuncTrackTrain::SetBank(float value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flBank", false, value);
}
float GCFuncTrackTrain::GetOldSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_oldSpeed");
}
void GCFuncTrackTrain::SetOldSpeed(float value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_oldSpeed", false, value);
}
float GCFuncTrackTrain::GetBlockDamage() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flBlockDamage");
}
void GCFuncTrackTrain::SetBlockDamage(float value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flBlockDamage", false, value);
}
float GCFuncTrackTrain::GetHeight() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_height");
}
void GCFuncTrackTrain::SetHeight(float value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_height", false, value);
}
float GCFuncTrackTrain::GetMaxSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_maxSpeed");
}
void GCFuncTrackTrain::SetMaxSpeed(float value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_maxSpeed", false, value);
}
float GCFuncTrackTrain::GetDir() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_dir");
}
void GCFuncTrackTrain::SetDir(float value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_dir", false, value);
}
std::string GCFuncTrackTrain::GetSoundMove() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncTrackTrain", "m_iszSoundMove").String();
}
void GCFuncTrackTrain::SetSoundMove(std::string value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_iszSoundMove", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFuncTrackTrain::GetSoundMovePing() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncTrackTrain", "m_iszSoundMovePing").String();
}
void GCFuncTrackTrain::SetSoundMovePing(std::string value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_iszSoundMovePing", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFuncTrackTrain::GetSoundStart() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncTrackTrain", "m_iszSoundStart").String();
}
void GCFuncTrackTrain::SetSoundStart(std::string value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_iszSoundStart", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFuncTrackTrain::GetSoundStop() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncTrackTrain", "m_iszSoundStop").String();
}
void GCFuncTrackTrain::SetSoundStop(std::string value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_iszSoundStop", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFuncTrackTrain::GetStrPathTarget() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncTrackTrain", "m_strPathTarget").String();
}
void GCFuncTrackTrain::SetStrPathTarget(std::string value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_strPathTarget", false, CUtlSymbolLarge(value.c_str()));
}
float GCFuncTrackTrain::GetMoveSoundMinDuration() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flMoveSoundMinDuration");
}
void GCFuncTrackTrain::SetMoveSoundMinDuration(float value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flMoveSoundMinDuration", false, value);
}
float GCFuncTrackTrain::GetMoveSoundMaxDuration() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flMoveSoundMaxDuration");
}
void GCFuncTrackTrain::SetMoveSoundMaxDuration(float value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flMoveSoundMaxDuration", false, value);
}
float GCFuncTrackTrain::GetNextMoveSoundTime() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flNextMoveSoundTime");
}
void GCFuncTrackTrain::SetNextMoveSoundTime(float value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flNextMoveSoundTime", false, value);
}
float GCFuncTrackTrain::GetMoveSoundMinPitch() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flMoveSoundMinPitch");
}
void GCFuncTrackTrain::SetMoveSoundMinPitch(float value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flMoveSoundMinPitch", false, value);
}
float GCFuncTrackTrain::GetMoveSoundMaxPitch() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flMoveSoundMaxPitch");
}
void GCFuncTrackTrain::SetMoveSoundMaxPitch(float value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flMoveSoundMaxPitch", false, value);
}
uint64_t GCFuncTrackTrain::GetOrientationType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CFuncTrackTrain", "m_eOrientationType");
}
void GCFuncTrackTrain::SetOrientationType(uint64_t value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_eOrientationType", false, value);
}
uint64_t GCFuncTrackTrain::GetVelocityType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CFuncTrackTrain", "m_eVelocityType");
}
void GCFuncTrackTrain::SetVelocityType(uint64_t value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_eVelocityType", false, value);
}
GCEntityIOOutput GCFuncTrackTrain::GetOnStart() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CFuncTrackTrain", "m_OnStart"));
    return value;
}
void GCFuncTrackTrain::SetOnStart(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_OnStart", false, value);
}
GCEntityIOOutput GCFuncTrackTrain::GetOnNext() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CFuncTrackTrain", "m_OnNext"));
    return value;
}
void GCFuncTrackTrain::SetOnNext(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_OnNext", false, value);
}
GCEntityIOOutput GCFuncTrackTrain::GetOnArrivedAtDestinationNode() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CFuncTrackTrain", "m_OnArrivedAtDestinationNode"));
    return value;
}
void GCFuncTrackTrain::SetOnArrivedAtDestinationNode(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_OnArrivedAtDestinationNode", false, value);
}
bool GCFuncTrackTrain::GetManualSpeedChanges() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncTrackTrain", "m_bManualSpeedChanges");
}
void GCFuncTrackTrain::SetManualSpeedChanges(bool value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_bManualSpeedChanges", false, value);
}
float GCFuncTrackTrain::GetDesiredSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flDesiredSpeed");
}
void GCFuncTrackTrain::SetDesiredSpeed(float value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flDesiredSpeed", false, value);
}
float GCFuncTrackTrain::GetSpeedChangeTime() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flSpeedChangeTime");
}
void GCFuncTrackTrain::SetSpeedChangeTime(float value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flSpeedChangeTime", false, value);
}
float GCFuncTrackTrain::GetAccelSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flAccelSpeed");
}
void GCFuncTrackTrain::SetAccelSpeed(float value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flAccelSpeed", false, value);
}
float GCFuncTrackTrain::GetDecelSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flDecelSpeed");
}
void GCFuncTrackTrain::SetDecelSpeed(float value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flDecelSpeed", false, value);
}
bool GCFuncTrackTrain::GetAccelToSpeed() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncTrackTrain", "m_bAccelToSpeed");
}
void GCFuncTrackTrain::SetAccelToSpeed(bool value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_bAccelToSpeed", false, value);
}
float GCFuncTrackTrain::GetNextMPSoundTime() const {
    return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flNextMPSoundTime");
}
void GCFuncTrackTrain::SetNextMPSoundTime(float value) {
    SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flNextMPSoundTime", false, value);
}
std::string GCFuncTrackTrain::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncTrackTrain::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCFuncTrackTrain::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCFuncTrackTrain::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncTrackTrain(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncTrackTrain>("CFuncTrackTrain")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Ppath", &GCFuncTrackTrain::GetPpath, &GCFuncTrackTrain::SetPpath)
        .addProperty("Length", &GCFuncTrackTrain::GetLength, &GCFuncTrackTrain::SetLength)
        .addProperty("PosPrev", &GCFuncTrackTrain::GetPosPrev, &GCFuncTrackTrain::SetPosPrev)
        .addProperty("Prev", &GCFuncTrackTrain::GetPrev, &GCFuncTrackTrain::SetPrev)
        .addProperty("ControlMins", &GCFuncTrackTrain::GetControlMins, &GCFuncTrackTrain::SetControlMins)
        .addProperty("ControlMaxs", &GCFuncTrackTrain::GetControlMaxs, &GCFuncTrackTrain::SetControlMaxs)
        .addProperty("LastBlockPos", &GCFuncTrackTrain::GetLastBlockPos, &GCFuncTrackTrain::SetLastBlockPos)
        .addProperty("LastBlockTick", &GCFuncTrackTrain::GetLastBlockTick, &GCFuncTrackTrain::SetLastBlockTick)
        .addProperty("Volume", &GCFuncTrackTrain::GetVolume, &GCFuncTrackTrain::SetVolume)
        .addProperty("Bank", &GCFuncTrackTrain::GetBank, &GCFuncTrackTrain::SetBank)
        .addProperty("OldSpeed", &GCFuncTrackTrain::GetOldSpeed, &GCFuncTrackTrain::SetOldSpeed)
        .addProperty("BlockDamage", &GCFuncTrackTrain::GetBlockDamage, &GCFuncTrackTrain::SetBlockDamage)
        .addProperty("Height", &GCFuncTrackTrain::GetHeight, &GCFuncTrackTrain::SetHeight)
        .addProperty("MaxSpeed", &GCFuncTrackTrain::GetMaxSpeed, &GCFuncTrackTrain::SetMaxSpeed)
        .addProperty("Dir", &GCFuncTrackTrain::GetDir, &GCFuncTrackTrain::SetDir)
        .addProperty("SoundMove", &GCFuncTrackTrain::GetSoundMove, &GCFuncTrackTrain::SetSoundMove)
        .addProperty("SoundMovePing", &GCFuncTrackTrain::GetSoundMovePing, &GCFuncTrackTrain::SetSoundMovePing)
        .addProperty("SoundStart", &GCFuncTrackTrain::GetSoundStart, &GCFuncTrackTrain::SetSoundStart)
        .addProperty("SoundStop", &GCFuncTrackTrain::GetSoundStop, &GCFuncTrackTrain::SetSoundStop)
        .addProperty("StrPathTarget", &GCFuncTrackTrain::GetStrPathTarget, &GCFuncTrackTrain::SetStrPathTarget)
        .addProperty("MoveSoundMinDuration", &GCFuncTrackTrain::GetMoveSoundMinDuration, &GCFuncTrackTrain::SetMoveSoundMinDuration)
        .addProperty("MoveSoundMaxDuration", &GCFuncTrackTrain::GetMoveSoundMaxDuration, &GCFuncTrackTrain::SetMoveSoundMaxDuration)
        .addProperty("NextMoveSoundTime", &GCFuncTrackTrain::GetNextMoveSoundTime, &GCFuncTrackTrain::SetNextMoveSoundTime)
        .addProperty("MoveSoundMinPitch", &GCFuncTrackTrain::GetMoveSoundMinPitch, &GCFuncTrackTrain::SetMoveSoundMinPitch)
        .addProperty("MoveSoundMaxPitch", &GCFuncTrackTrain::GetMoveSoundMaxPitch, &GCFuncTrackTrain::SetMoveSoundMaxPitch)
        .addProperty("OrientationType", &GCFuncTrackTrain::GetOrientationType, &GCFuncTrackTrain::SetOrientationType)
        .addProperty("VelocityType", &GCFuncTrackTrain::GetVelocityType, &GCFuncTrackTrain::SetVelocityType)
        .addProperty("OnStart", &GCFuncTrackTrain::GetOnStart, &GCFuncTrackTrain::SetOnStart)
        .addProperty("OnNext", &GCFuncTrackTrain::GetOnNext, &GCFuncTrackTrain::SetOnNext)
        .addProperty("OnArrivedAtDestinationNode", &GCFuncTrackTrain::GetOnArrivedAtDestinationNode, &GCFuncTrackTrain::SetOnArrivedAtDestinationNode)
        .addProperty("ManualSpeedChanges", &GCFuncTrackTrain::GetManualSpeedChanges, &GCFuncTrackTrain::SetManualSpeedChanges)
        .addProperty("DesiredSpeed", &GCFuncTrackTrain::GetDesiredSpeed, &GCFuncTrackTrain::SetDesiredSpeed)
        .addProperty("SpeedChangeTime", &GCFuncTrackTrain::GetSpeedChangeTime, &GCFuncTrackTrain::SetSpeedChangeTime)
        .addProperty("AccelSpeed", &GCFuncTrackTrain::GetAccelSpeed, &GCFuncTrackTrain::SetAccelSpeed)
        .addProperty("DecelSpeed", &GCFuncTrackTrain::GetDecelSpeed, &GCFuncTrackTrain::SetDecelSpeed)
        .addProperty("AccelToSpeed", &GCFuncTrackTrain::GetAccelToSpeed, &GCFuncTrackTrain::SetAccelToSpeed)
        .addProperty("NextMPSoundTime", &GCFuncTrackTrain::GetNextMPSoundTime, &GCFuncTrackTrain::SetNextMPSoundTime)
        .addProperty("Parent", &GCFuncTrackTrain::GetParent, &GCFuncTrackTrain::SetParent)
        .addFunction("ToPtr", &GCFuncTrackTrain::ToPtr)
        .addFunction("IsValid", &GCFuncTrackTrain::IsValid)
        .endClass();
}