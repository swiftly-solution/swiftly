class GCTimerEntity;

#ifndef _gcctimerentity_h
#define _gcctimerentity_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCTimerEntity
{
private:
    void *m_ptr;

public:
    GCTimerEntity() {}
    GCTimerEntity(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnTimer() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CTimerEntity", "m_OnTimer"); }
    void SetOnTimer(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CTimerEntity", "m_OnTimer", false, value); }
    GCEntityIOOutput GetOnTimerHigh() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CTimerEntity", "m_OnTimerHigh"); }
    void SetOnTimerHigh(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CTimerEntity", "m_OnTimerHigh", false, value); }
    GCEntityIOOutput GetOnTimerLow() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CTimerEntity", "m_OnTimerLow"); }
    void SetOnTimerLow(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CTimerEntity", "m_OnTimerLow", false, value); }
    int32_t GetDisabled() const { return GetSchemaValue<int32_t>(m_ptr, "CTimerEntity", "m_iDisabled"); }
    void SetDisabled(int32_t value) { SetSchemaValue(m_ptr, "CTimerEntity", "m_iDisabled", false, value); }
    float GetInitialDelay() const { return GetSchemaValue<float>(m_ptr, "CTimerEntity", "m_flInitialDelay"); }
    void SetInitialDelay(float value) { SetSchemaValue(m_ptr, "CTimerEntity", "m_flInitialDelay", false, value); }
    float GetRefireTime() const { return GetSchemaValue<float>(m_ptr, "CTimerEntity", "m_flRefireTime"); }
    void SetRefireTime(float value) { SetSchemaValue(m_ptr, "CTimerEntity", "m_flRefireTime", false, value); }
    bool GetUpDownState() const { return GetSchemaValue<bool>(m_ptr, "CTimerEntity", "m_bUpDownState"); }
    void SetUpDownState(bool value) { SetSchemaValue(m_ptr, "CTimerEntity", "m_bUpDownState", false, value); }
    int32_t GetUseRandomTime() const { return GetSchemaValue<int32_t>(m_ptr, "CTimerEntity", "m_iUseRandomTime"); }
    void SetUseRandomTime(int32_t value) { SetSchemaValue(m_ptr, "CTimerEntity", "m_iUseRandomTime", false, value); }
    bool GetPauseAfterFiring() const { return GetSchemaValue<bool>(m_ptr, "CTimerEntity", "m_bPauseAfterFiring"); }
    void SetPauseAfterFiring(bool value) { SetSchemaValue(m_ptr, "CTimerEntity", "m_bPauseAfterFiring", false, value); }
    float GetLowerRandomBound() const { return GetSchemaValue<float>(m_ptr, "CTimerEntity", "m_flLowerRandomBound"); }
    void SetLowerRandomBound(float value) { SetSchemaValue(m_ptr, "CTimerEntity", "m_flLowerRandomBound", false, value); }
    float GetUpperRandomBound() const { return GetSchemaValue<float>(m_ptr, "CTimerEntity", "m_flUpperRandomBound"); }
    void SetUpperRandomBound(float value) { SetSchemaValue(m_ptr, "CTimerEntity", "m_flUpperRandomBound", false, value); }
    float GetRemainingTime() const { return GetSchemaValue<float>(m_ptr, "CTimerEntity", "m_flRemainingTime"); }
    void SetRemainingTime(float value) { SetSchemaValue(m_ptr, "CTimerEntity", "m_flRemainingTime", false, value); }
    bool GetPaused() const { return GetSchemaValue<bool>(m_ptr, "CTimerEntity", "m_bPaused"); }
    void SetPaused(bool value) { SetSchemaValue(m_ptr, "CTimerEntity", "m_bPaused", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif