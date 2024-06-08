class GCTankTrainAI;

#ifndef _gcctanktrainai_h
#define _gcctanktrainai_h

#include "../../../scripting.h"


#include "GCFuncTrackTrain.h"
#include "GCBaseEntity.h"

class GCTankTrainAI
{
private:
    void *m_ptr;

public:
    GCTankTrainAI() {}
    GCTankTrainAI(void *ptr) : m_ptr(ptr) {}

    GCFuncTrackTrain* GetTrain() const { return GetSchemaValue<GCFuncTrackTrain*>(m_ptr, "CTankTrainAI", "m_hTrain"); }
    void SetTrain(GCFuncTrackTrain* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Train' is not possible.\n"); }
    GCBaseEntity* GetTargetEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CTankTrainAI", "m_hTargetEntity"); }
    void SetTargetEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetEntity' is not possible.\n"); }
    int32_t GetSoundPlaying() const { return GetSchemaValue<int32_t>(m_ptr, "CTankTrainAI", "m_soundPlaying"); }
    void SetSoundPlaying(int32_t value) { SetSchemaValue(m_ptr, "CTankTrainAI", "m_soundPlaying", false, value); }
    CUtlSymbolLarge GetStartSoundName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTankTrainAI", "m_startSoundName"); }
    void SetStartSoundName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CTankTrainAI", "m_startSoundName", false, value); }
    CUtlSymbolLarge GetEngineSoundName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTankTrainAI", "m_engineSoundName"); }
    void SetEngineSoundName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CTankTrainAI", "m_engineSoundName", false, value); }
    CUtlSymbolLarge GetMovementSoundName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTankTrainAI", "m_movementSoundName"); }
    void SetMovementSoundName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CTankTrainAI", "m_movementSoundName", false, value); }
    CUtlSymbolLarge GetTargetEntityName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTankTrainAI", "m_targetEntityName"); }
    void SetTargetEntityName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CTankTrainAI", "m_targetEntityName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif