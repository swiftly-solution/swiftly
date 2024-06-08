class GCNmTransitionNode;

#ifndef _gccnmtransitionnode_h
#define _gccnmtransitionnode_h

#include "../../../scripting.h"

#include "../types/GNmEasingOperation_t.h"
#include "../types/GNmRootMotionBlendMode_t.h"
#include "GNmPercent_t.h"
#include "GCNmTransitionNode.h"

class GCNmTransitionNode
{
private:
    void *m_ptr;

public:
    GCNmTransitionNode() {}
    GCNmTransitionNode(void *ptr) : m_ptr(ptr) {}

    int16_t GetTargetCNmStateNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmTransitionNode", "m_targetCNmStateNodeIdx"); }
    void SetTargetCNmStateNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmTransitionNode", "m_targetCNmStateNodeIdx", false, value); }
    int16_t GetDurationOverrideNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmTransitionNode", "m_durationOverrideNodeIdx"); }
    void SetDurationOverrideNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmTransitionNode", "m_durationOverrideNodeIdx", false, value); }
    int16_t GetSyncEventOffsetOverrideNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmTransitionNode", "m_syncEventOffsetOverrideNodeIdx"); }
    void SetSyncEventOffsetOverrideNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmTransitionNode", "m_syncEventOffsetOverrideNodeIdx", false, value); }
    int16_t GetStartBoneMaskNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmTransitionNode", "m_startBoneMaskNodeIdx"); }
    void SetStartBoneMaskNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmTransitionNode", "m_startBoneMaskNodeIdx", false, value); }
    float GetDuration() const { return GetSchemaValue<float>(m_ptr, "CNmTransitionNode", "m_flDuration"); }
    void SetDuration(float value) { SetSchemaValue(m_ptr, "CNmTransitionNode", "m_flDuration", false, value); }
    GNmPercent_t GetBoneMaskBlendInTimePercentage() const { return GetSchemaValue<GNmPercent_t>(m_ptr, "CNmTransitionNode", "m_boneMaskBlendInTimePercentage"); }
    void SetBoneMaskBlendInTimePercentage(GNmPercent_t value) { SetSchemaValue(m_ptr, "CNmTransitionNode", "m_boneMaskBlendInTimePercentage", false, value); }
    float GetSyncEventOffset() const { return GetSchemaValue<float>(m_ptr, "CNmTransitionNode", "m_syncEventOffset"); }
    void SetSyncEventOffset(float value) { SetSchemaValue(m_ptr, "CNmTransitionNode", "m_syncEventOffset", false, value); }
    GCNmTransitionNode GetTransitionOptions() const { return GetSchemaValue<GCNmTransitionNode>(m_ptr, "CNmTransitionNode", "m_transitionOptions"); }
    void SetTransitionOptions(GCNmTransitionNode value) { SetSchemaValue(m_ptr, "CNmTransitionNode", "m_transitionOptions", false, value); }
    int16_t GetTargetSyncIDNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmTransitionNode", "m_targetSyncIDNodeIdx"); }
    void SetTargetSyncIDNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmTransitionNode", "m_targetSyncIDNodeIdx", false, value); }
    NmEasingOperation_t GetBlendWeightEasing() const { return GetSchemaValue<NmEasingOperation_t>(m_ptr, "CNmTransitionNode", "m_blendWeightEasing"); }
    void SetBlendWeightEasing(NmEasingOperation_t value) { SetSchemaValue(m_ptr, "CNmTransitionNode", "m_blendWeightEasing", false, value); }
    NmRootMotionBlendMode_t GetRootMotionBlend() const { return GetSchemaValue<NmRootMotionBlendMode_t>(m_ptr, "CNmTransitionNode", "m_rootMotionBlend"); }
    void SetRootMotionBlend(NmRootMotionBlendMode_t value) { SetSchemaValue(m_ptr, "CNmTransitionNode", "m_rootMotionBlend", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif