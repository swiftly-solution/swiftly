class GCFuncTrackChange;

#ifndef _gccfunctrackchange_h
#define _gccfunctrackchange_h

#include "../../../scripting.h"

#include "../types/GTRAIN_CODE.h"
#include "GCPathTrack.h"
#include "GCFuncTrackTrain.h"

class GCFuncTrackChange
{
private:
    void *m_ptr;

public:
    GCFuncTrackChange() {}
    GCFuncTrackChange(void *ptr) : m_ptr(ptr) {}

    GCPathTrack* GetTrackTop() const { return GetSchemaValue<GCPathTrack*>(m_ptr, "CFuncTrackChange", "m_trackTop"); }
    void SetTrackTop(GCPathTrack* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'TrackTop' is not possible.\n"); }
    GCPathTrack* GetTrackBottom() const { return GetSchemaValue<GCPathTrack*>(m_ptr, "CFuncTrackChange", "m_trackBottom"); }
    void SetTrackBottom(GCPathTrack* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'TrackBottom' is not possible.\n"); }
    GCFuncTrackTrain* GetTrain() const { return GetSchemaValue<GCFuncTrackTrain*>(m_ptr, "CFuncTrackChange", "m_train"); }
    void SetTrain(GCFuncTrackTrain* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Train' is not possible.\n"); }
    CUtlSymbolLarge GetTrackTopName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncTrackChange", "m_trackTopName"); }
    void SetTrackTopName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncTrackChange", "m_trackTopName", false, value); }
    CUtlSymbolLarge GetTrackBottomName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncTrackChange", "m_trackBottomName"); }
    void SetTrackBottomName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncTrackChange", "m_trackBottomName", false, value); }
    CUtlSymbolLarge GetTrainName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncTrackChange", "m_trainName"); }
    void SetTrainName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncTrackChange", "m_trainName", false, value); }
    TRAIN_CODE GetCode() const { return GetSchemaValue<TRAIN_CODE>(m_ptr, "CFuncTrackChange", "m_code"); }
    void SetCode(TRAIN_CODE value) { SetSchemaValue(m_ptr, "CFuncTrackChange", "m_code", false, value); }
    int32_t GetTargetState() const { return GetSchemaValue<int32_t>(m_ptr, "CFuncTrackChange", "m_targetState"); }
    void SetTargetState(int32_t value) { SetSchemaValue(m_ptr, "CFuncTrackChange", "m_targetState", false, value); }
    int32_t GetUse() const { return GetSchemaValue<int32_t>(m_ptr, "CFuncTrackChange", "m_use"); }
    void SetUse(int32_t value) { SetSchemaValue(m_ptr, "CFuncTrackChange", "m_use", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif