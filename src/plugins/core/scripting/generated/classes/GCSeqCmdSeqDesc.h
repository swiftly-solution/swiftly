class GCSeqCmdSeqDesc;

#ifndef _gccseqcmdseqdesc_h
#define _gccseqcmdseqdesc_h

#include "../../../scripting.h"


#include "GCSeqSeqDescFlag.h"
#include "GCSeqTransition.h"
#include "GCSeqCmdLayer.h"
#include "GCAnimEventDefinition.h"
#include "GCAnimActivity.h"
#include "GCSeqPoseSetting.h"

class GCSeqCmdSeqDesc
{
private:
    void *m_ptr;

public:
    GCSeqCmdSeqDesc() {}
    GCSeqCmdSeqDesc(void *ptr) : m_ptr(ptr) {}

    CBufferString GetName() const { return GetSchemaValue<CBufferString>(m_ptr, "CSeqCmdSeqDesc", "m_sName"); }
    void SetName(CBufferString value) { SetSchemaValue(m_ptr, "CSeqCmdSeqDesc", "m_sName", false, value); }
    GCSeqSeqDescFlag GetFlags() const { return GetSchemaValue<GCSeqSeqDescFlag>(m_ptr, "CSeqCmdSeqDesc", "m_flags"); }
    void SetFlags(GCSeqSeqDescFlag value) { SetSchemaValue(m_ptr, "CSeqCmdSeqDesc", "m_flags", false, value); }
    GCSeqTransition GetTransition() const { return GetSchemaValue<GCSeqTransition>(m_ptr, "CSeqCmdSeqDesc", "m_transition"); }
    void SetTransition(GCSeqTransition value) { SetSchemaValue(m_ptr, "CSeqCmdSeqDesc", "m_transition", false, value); }
    int16_t GetFrameRangeSequence() const { return GetSchemaValue<int16_t>(m_ptr, "CSeqCmdSeqDesc", "m_nFrameRangeSequence"); }
    void SetFrameRangeSequence(int16_t value) { SetSchemaValue(m_ptr, "CSeqCmdSeqDesc", "m_nFrameRangeSequence", false, value); }
    int16_t GetFrameCount() const { return GetSchemaValue<int16_t>(m_ptr, "CSeqCmdSeqDesc", "m_nFrameCount"); }
    void SetFrameCount(int16_t value) { SetSchemaValue(m_ptr, "CSeqCmdSeqDesc", "m_nFrameCount", false, value); }
    float GetFPS() const { return GetSchemaValue<float>(m_ptr, "CSeqCmdSeqDesc", "m_flFPS"); }
    void SetFPS(float value) { SetSchemaValue(m_ptr, "CSeqCmdSeqDesc", "m_flFPS", false, value); }
    int16_t GetSubCycles() const { return GetSchemaValue<int16_t>(m_ptr, "CSeqCmdSeqDesc", "m_nSubCycles"); }
    void SetSubCycles(int16_t value) { SetSchemaValue(m_ptr, "CSeqCmdSeqDesc", "m_nSubCycles", false, value); }
    int16_t GetNumLocalResults() const { return GetSchemaValue<int16_t>(m_ptr, "CSeqCmdSeqDesc", "m_numLocalResults"); }
    void SetNumLocalResults(int16_t value) { SetSchemaValue(m_ptr, "CSeqCmdSeqDesc", "m_numLocalResults", false, value); }
    std::vector<GCSeqCmdLayer> GetCmdLayerArray() const { CUtlVector<GCSeqCmdLayer>* vec = GetSchemaValue<CUtlVector<GCSeqCmdLayer>*>(m_ptr, "CSeqCmdSeqDesc", "m_cmdLayerArray"); std::vector<GCSeqCmdLayer> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCmdLayerArray(std::vector<GCSeqCmdLayer> value) { SetSchemaValueCUtlVector<GCSeqCmdLayer>(m_ptr, "CSeqCmdSeqDesc", "m_cmdLayerArray", false, value); }
    std::vector<GCAnimEventDefinition> GetEventArray() const { CUtlVector<GCAnimEventDefinition>* vec = GetSchemaValue<CUtlVector<GCAnimEventDefinition>*>(m_ptr, "CSeqCmdSeqDesc", "m_eventArray"); std::vector<GCAnimEventDefinition> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetEventArray(std::vector<GCAnimEventDefinition> value) { SetSchemaValueCUtlVector<GCAnimEventDefinition>(m_ptr, "CSeqCmdSeqDesc", "m_eventArray", false, value); }
    std::vector<GCAnimActivity> GetActivityArray() const { CUtlVector<GCAnimActivity>* vec = GetSchemaValue<CUtlVector<GCAnimActivity>*>(m_ptr, "CSeqCmdSeqDesc", "m_activityArray"); std::vector<GCAnimActivity> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetActivityArray(std::vector<GCAnimActivity> value) { SetSchemaValueCUtlVector<GCAnimActivity>(m_ptr, "CSeqCmdSeqDesc", "m_activityArray", false, value); }
    std::vector<GCSeqPoseSetting> GetPoseSettingArray() const { CUtlVector<GCSeqPoseSetting>* vec = GetSchemaValue<CUtlVector<GCSeqPoseSetting>*>(m_ptr, "CSeqCmdSeqDesc", "m_poseSettingArray"); std::vector<GCSeqPoseSetting> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPoseSettingArray(std::vector<GCSeqPoseSetting> value) { SetSchemaValueCUtlVector<GCSeqPoseSetting>(m_ptr, "CSeqCmdSeqDesc", "m_poseSettingArray", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif