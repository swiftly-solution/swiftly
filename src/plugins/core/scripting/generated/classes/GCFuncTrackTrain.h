class GCFuncTrackTrain;

#ifndef _gccfunctracktrain_h
#define _gccfunctracktrain_h

#include "../../../scripting.h"

#include "../types/GTrainOrientationType_t.h"
#include "../types/GTrainVelocityType_t.h"
#include "GCPathTrack.h"
#include "GCEntityIOOutput.h"

class GCFuncTrackTrain
{
private:
    void *m_ptr;

public:
    GCFuncTrackTrain() {}
    GCFuncTrackTrain(void *ptr) : m_ptr(ptr) {}

    GCPathTrack* GetPpath() const { return GetSchemaValue<GCPathTrack*>(m_ptr, "CFuncTrackTrain", "m_ppath"); }
    void SetPpath(GCPathTrack* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Ppath' is not possible.\n"); }
    float GetLength() const { return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_length"); }
    void SetLength(float value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_length", false, value); }
    Vector GetPosPrev() const { return GetSchemaValue<Vector>(m_ptr, "CFuncTrackTrain", "m_vPosPrev"); }
    void SetPosPrev(Vector value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_vPosPrev", false, value); }
    QAngle GetPrev() const { return GetSchemaValue<QAngle>(m_ptr, "CFuncTrackTrain", "m_angPrev"); }
    void SetPrev(QAngle value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_angPrev", false, value); }
    Vector GetControlMins() const { return GetSchemaValue<Vector>(m_ptr, "CFuncTrackTrain", "m_controlMins"); }
    void SetControlMins(Vector value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_controlMins", false, value); }
    Vector GetControlMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CFuncTrackTrain", "m_controlMaxs"); }
    void SetControlMaxs(Vector value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_controlMaxs", false, value); }
    Vector GetLastBlockPos() const { return GetSchemaValue<Vector>(m_ptr, "CFuncTrackTrain", "m_lastBlockPos"); }
    void SetLastBlockPos(Vector value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_lastBlockPos", false, value); }
    int32_t GetLastBlockTick() const { return GetSchemaValue<int32_t>(m_ptr, "CFuncTrackTrain", "m_lastBlockTick"); }
    void SetLastBlockTick(int32_t value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_lastBlockTick", false, value); }
    float GetVolume() const { return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flVolume"); }
    void SetVolume(float value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flVolume", false, value); }
    float GetBank() const { return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flBank"); }
    void SetBank(float value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flBank", false, value); }
    float GetOldSpeed() const { return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_oldSpeed"); }
    void SetOldSpeed(float value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_oldSpeed", false, value); }
    float GetBlockDamage() const { return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flBlockDamage"); }
    void SetBlockDamage(float value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flBlockDamage", false, value); }
    float GetHeight() const { return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_height"); }
    void SetHeight(float value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_height", false, value); }
    float GetMaxSpeed() const { return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_maxSpeed"); }
    void SetMaxSpeed(float value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_maxSpeed", false, value); }
    float GetDir() const { return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_dir"); }
    void SetDir(float value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_dir", false, value); }
    CUtlSymbolLarge GetSoundMove() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncTrackTrain", "m_iszSoundMove"); }
    void SetSoundMove(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_iszSoundMove", false, value); }
    CUtlSymbolLarge GetSoundMovePing() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncTrackTrain", "m_iszSoundMovePing"); }
    void SetSoundMovePing(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_iszSoundMovePing", false, value); }
    CUtlSymbolLarge GetSoundStart() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncTrackTrain", "m_iszSoundStart"); }
    void SetSoundStart(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_iszSoundStart", false, value); }
    CUtlSymbolLarge GetSoundStop() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncTrackTrain", "m_iszSoundStop"); }
    void SetSoundStop(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_iszSoundStop", false, value); }
    CUtlSymbolLarge GetStrPathTarget() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncTrackTrain", "m_strPathTarget"); }
    void SetStrPathTarget(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_strPathTarget", false, value); }
    float GetMoveSoundMinDuration() const { return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flMoveSoundMinDuration"); }
    void SetMoveSoundMinDuration(float value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flMoveSoundMinDuration", false, value); }
    float GetMoveSoundMaxDuration() const { return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flMoveSoundMaxDuration"); }
    void SetMoveSoundMaxDuration(float value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flMoveSoundMaxDuration", false, value); }
    float GetMoveSoundMinPitch() const { return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flMoveSoundMinPitch"); }
    void SetMoveSoundMinPitch(float value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flMoveSoundMinPitch", false, value); }
    float GetMoveSoundMaxPitch() const { return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flMoveSoundMaxPitch"); }
    void SetMoveSoundMaxPitch(float value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flMoveSoundMaxPitch", false, value); }
    TrainOrientationType_t GetOrientationType() const { return GetSchemaValue<TrainOrientationType_t>(m_ptr, "CFuncTrackTrain", "m_eOrientationType"); }
    void SetOrientationType(TrainOrientationType_t value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_eOrientationType", false, value); }
    TrainVelocityType_t GetVelocityType() const { return GetSchemaValue<TrainVelocityType_t>(m_ptr, "CFuncTrackTrain", "m_eVelocityType"); }
    void SetVelocityType(TrainVelocityType_t value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_eVelocityType", false, value); }
    GCEntityIOOutput GetOnStart() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CFuncTrackTrain", "m_OnStart"); }
    void SetOnStart(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_OnStart", false, value); }
    GCEntityIOOutput GetOnNext() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CFuncTrackTrain", "m_OnNext"); }
    void SetOnNext(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_OnNext", false, value); }
    GCEntityIOOutput GetOnArrivedAtDestinationNode() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CFuncTrackTrain", "m_OnArrivedAtDestinationNode"); }
    void SetOnArrivedAtDestinationNode(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_OnArrivedAtDestinationNode", false, value); }
    bool GetManualSpeedChanges() const { return GetSchemaValue<bool>(m_ptr, "CFuncTrackTrain", "m_bManualSpeedChanges"); }
    void SetManualSpeedChanges(bool value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_bManualSpeedChanges", false, value); }
    float GetDesiredSpeed() const { return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flDesiredSpeed"); }
    void SetDesiredSpeed(float value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flDesiredSpeed", false, value); }
    float GetAccelSpeed() const { return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flAccelSpeed"); }
    void SetAccelSpeed(float value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flAccelSpeed", false, value); }
    float GetDecelSpeed() const { return GetSchemaValue<float>(m_ptr, "CFuncTrackTrain", "m_flDecelSpeed"); }
    void SetDecelSpeed(float value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_flDecelSpeed", false, value); }
    bool GetAccelToSpeed() const { return GetSchemaValue<bool>(m_ptr, "CFuncTrackTrain", "m_bAccelToSpeed"); }
    void SetAccelToSpeed(bool value) { SetSchemaValue(m_ptr, "CFuncTrackTrain", "m_bAccelToSpeed", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif