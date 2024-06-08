class GCBaseAnimGraphController;

#ifndef _gccbaseanimgraphcontroller_h
#define _gccbaseanimgraphcontroller_h

#include "../../../scripting.h"

#include "../types/GAnimLoopMode_t.h"
#include "../types/GSequenceFinishNotifyState_t.h"
#include "GCAnimGraphNetworkedVariables.h"

class GCBaseAnimGraphController
{
private:
    void *m_ptr;

public:
    GCBaseAnimGraphController() {}
    GCBaseAnimGraphController(void *ptr) : m_ptr(ptr) {}

    GCAnimGraphNetworkedVariables GetAnimGraphNetworkedVars() const { return GetSchemaValue<GCAnimGraphNetworkedVariables>(m_ptr, "CBaseAnimGraphController", "m_animGraphNetworkedVars"); }
    void SetAnimGraphNetworkedVars(GCAnimGraphNetworkedVariables value) { SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_animGraphNetworkedVars", false, value); }
    bool GetSequenceFinished() const { return GetSchemaValue<bool>(m_ptr, "CBaseAnimGraphController", "m_bSequenceFinished"); }
    void SetSequenceFinished(bool value) { SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_bSequenceFinished", false, value); }
    float GetSoundSyncTime() const { return GetSchemaValue<float>(m_ptr, "CBaseAnimGraphController", "m_flSoundSyncTime"); }
    void SetSoundSyncTime(float value) { SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_flSoundSyncTime", false, value); }
    uint32_t GetActiveIKChainMask() const { return GetSchemaValue<uint32_t>(m_ptr, "CBaseAnimGraphController", "m_nActiveIKChainMask"); }
    void SetActiveIKChainMask(uint32_t value) { SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_nActiveIKChainMask", false, value); }
    float GetSeqFixedCycle() const { return GetSchemaValue<float>(m_ptr, "CBaseAnimGraphController", "m_flSeqFixedCycle"); }
    void SetSeqFixedCycle(float value) { SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_flSeqFixedCycle", false, value); }
    AnimLoopMode_t GetAnimLoopMode() const { return GetSchemaValue<AnimLoopMode_t>(m_ptr, "CBaseAnimGraphController", "m_nAnimLoopMode"); }
    void SetAnimLoopMode(AnimLoopMode_t value) { SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_nAnimLoopMode", false, value); }
    float GetPlaybackRate() const { return GetSchemaValue<float>(m_ptr, "CBaseAnimGraphController", "m_flPlaybackRate"); }
    void SetPlaybackRate(float value) { SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_flPlaybackRate", false, value); }
    SequenceFinishNotifyState_t GetNotifyState() const { return GetSchemaValue<SequenceFinishNotifyState_t>(m_ptr, "CBaseAnimGraphController", "m_nNotifyState"); }
    void SetNotifyState(SequenceFinishNotifyState_t value) { SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_nNotifyState", false, value); }
    bool GetNetworkedAnimationInputsChanged() const { return GetSchemaValue<bool>(m_ptr, "CBaseAnimGraphController", "m_bNetworkedAnimationInputsChanged"); }
    void SetNetworkedAnimationInputsChanged(bool value) { SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_bNetworkedAnimationInputsChanged", false, value); }
    bool GetNetworkedSequenceChanged() const { return GetSchemaValue<bool>(m_ptr, "CBaseAnimGraphController", "m_bNetworkedSequenceChanged"); }
    void SetNetworkedSequenceChanged(bool value) { SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_bNetworkedSequenceChanged", false, value); }
    bool GetLastUpdateSkipped() const { return GetSchemaValue<bool>(m_ptr, "CBaseAnimGraphController", "m_bLastUpdateSkipped"); }
    void SetLastUpdateSkipped(bool value) { SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_bLastUpdateSkipped", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif