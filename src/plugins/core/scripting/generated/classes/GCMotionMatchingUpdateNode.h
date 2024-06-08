class GCMotionMatchingUpdateNode;

#ifndef _gccmotionmatchingupdatenode_h
#define _gccmotionmatchingupdatenode_h

#include "../../../scripting.h"


#include "GCMotionDataSet.h"
#include "GCBlendCurve.h"
#include "GCAnimInputDamping.h"

class GCMotionMatchingUpdateNode
{
private:
    void *m_ptr;

public:
    GCMotionMatchingUpdateNode() {}
    GCMotionMatchingUpdateNode(void *ptr) : m_ptr(ptr) {}

    GCMotionDataSet GetDataSet() const { return GetSchemaValue<GCMotionDataSet>(m_ptr, "CMotionMatchingUpdateNode", "m_dataSet"); }
    void SetDataSet(GCMotionDataSet value) { SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_dataSet", false, value); }
    std::vector<float32> GetWeights() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CMotionMatchingUpdateNode", "m_weights"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetWeights(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CMotionMatchingUpdateNode", "m_weights", false, value); }
    bool GetSearchEveryTick() const { return GetSchemaValue<bool>(m_ptr, "CMotionMatchingUpdateNode", "m_bSearchEveryTick"); }
    void SetSearchEveryTick(bool value) { SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_bSearchEveryTick", false, value); }
    float GetSearchInterval() const { return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flSearchInterval"); }
    void SetSearchInterval(float value) { SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flSearchInterval", false, value); }
    bool GetSearchWhenClipEnds() const { return GetSchemaValue<bool>(m_ptr, "CMotionMatchingUpdateNode", "m_bSearchWhenClipEnds"); }
    void SetSearchWhenClipEnds(bool value) { SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_bSearchWhenClipEnds", false, value); }
    bool GetSearchWhenGoalChanges() const { return GetSchemaValue<bool>(m_ptr, "CMotionMatchingUpdateNode", "m_bSearchWhenGoalChanges"); }
    void SetSearchWhenGoalChanges(bool value) { SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_bSearchWhenGoalChanges", false, value); }
    GCBlendCurve GetBlendCurve() const { return GetSchemaValue<GCBlendCurve>(m_ptr, "CMotionMatchingUpdateNode", "m_blendCurve"); }
    void SetBlendCurve(GCBlendCurve value) { SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_blendCurve", false, value); }
    float GetSampleRate() const { return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flSampleRate"); }
    void SetSampleRate(float value) { SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flSampleRate", false, value); }
    float GetBlendTime() const { return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flBlendTime"); }
    void SetBlendTime(float value) { SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flBlendTime", false, value); }
    bool GetLockClipWhenWaning() const { return GetSchemaValue<bool>(m_ptr, "CMotionMatchingUpdateNode", "m_bLockClipWhenWaning"); }
    void SetLockClipWhenWaning(bool value) { SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_bLockClipWhenWaning", false, value); }
    float GetSelectionThreshold() const { return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flSelectionThreshold"); }
    void SetSelectionThreshold(float value) { SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flSelectionThreshold", false, value); }
    float GetReselectionTimeWindow() const { return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flReselectionTimeWindow"); }
    void SetReselectionTimeWindow(float value) { SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flReselectionTimeWindow", false, value); }
    bool GetEnableRotationCorrection() const { return GetSchemaValue<bool>(m_ptr, "CMotionMatchingUpdateNode", "m_bEnableRotationCorrection"); }
    void SetEnableRotationCorrection(bool value) { SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_bEnableRotationCorrection", false, value); }
    bool GetGoalAssist() const { return GetSchemaValue<bool>(m_ptr, "CMotionMatchingUpdateNode", "m_bGoalAssist"); }
    void SetGoalAssist(bool value) { SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_bGoalAssist", false, value); }
    float GetGoalAssistDistance() const { return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flGoalAssistDistance"); }
    void SetGoalAssistDistance(float value) { SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flGoalAssistDistance", false, value); }
    float GetGoalAssistTolerance() const { return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flGoalAssistTolerance"); }
    void SetGoalAssistTolerance(float value) { SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flGoalAssistTolerance", false, value); }
    GCAnimInputDamping GetDistanceScale_Damping() const { return GetSchemaValue<GCAnimInputDamping>(m_ptr, "CMotionMatchingUpdateNode", "m_distanceScale_Damping"); }
    void SetDistanceScale_Damping(GCAnimInputDamping value) { SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_distanceScale_Damping", false, value); }
    float GetDistanceScale_OuterRadius() const { return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flDistanceScale_OuterRadius"); }
    void SetDistanceScale_OuterRadius(float value) { SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flDistanceScale_OuterRadius", false, value); }
    float GetDistanceScale_InnerRadius() const { return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flDistanceScale_InnerRadius"); }
    void SetDistanceScale_InnerRadius(float value) { SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flDistanceScale_InnerRadius", false, value); }
    float GetDistanceScale_MaxScale() const { return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flDistanceScale_MaxScale"); }
    void SetDistanceScale_MaxScale(float value) { SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flDistanceScale_MaxScale", false, value); }
    float GetDistanceScale_MinScale() const { return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flDistanceScale_MinScale"); }
    void SetDistanceScale_MinScale(float value) { SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flDistanceScale_MinScale", false, value); }
    bool GetEnableDistanceScaling() const { return GetSchemaValue<bool>(m_ptr, "CMotionMatchingUpdateNode", "m_bEnableDistanceScaling"); }
    void SetEnableDistanceScaling(bool value) { SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_bEnableDistanceScaling", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif