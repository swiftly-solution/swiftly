class GCBaseMoveBehavior;

#ifndef _gccbasemovebehavior_h
#define _gccbasemovebehavior_h

#include "../../../scripting.h"


#include "GCPathKeyFrame.h"

class GCBaseMoveBehavior
{
private:
    void *m_ptr;

public:
    GCBaseMoveBehavior() {}
    GCBaseMoveBehavior(void *ptr) : m_ptr(ptr) {}

    int32_t GetPositionInterpolator() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseMoveBehavior", "m_iPositionInterpolator"); }
    void SetPositionInterpolator(int32_t value) { SetSchemaValue(m_ptr, "CBaseMoveBehavior", "m_iPositionInterpolator", false, value); }
    int32_t GetRotationInterpolator() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseMoveBehavior", "m_iRotationInterpolator"); }
    void SetRotationInterpolator(int32_t value) { SetSchemaValue(m_ptr, "CBaseMoveBehavior", "m_iRotationInterpolator", false, value); }
    float GetAnimStartTime() const { return GetSchemaValue<float>(m_ptr, "CBaseMoveBehavior", "m_flAnimStartTime"); }
    void SetAnimStartTime(float value) { SetSchemaValue(m_ptr, "CBaseMoveBehavior", "m_flAnimStartTime", false, value); }
    float GetAnimEndTime() const { return GetSchemaValue<float>(m_ptr, "CBaseMoveBehavior", "m_flAnimEndTime"); }
    void SetAnimEndTime(float value) { SetSchemaValue(m_ptr, "CBaseMoveBehavior", "m_flAnimEndTime", false, value); }
    float GetAverageSpeedAcrossFrame() const { return GetSchemaValue<float>(m_ptr, "CBaseMoveBehavior", "m_flAverageSpeedAcrossFrame"); }
    void SetAverageSpeedAcrossFrame(float value) { SetSchemaValue(m_ptr, "CBaseMoveBehavior", "m_flAverageSpeedAcrossFrame", false, value); }
    GCPathKeyFrame* GetCurrentKeyFrame() const { return GetSchemaValue<GCPathKeyFrame*>(m_ptr, "CBaseMoveBehavior", "m_pCurrentKeyFrame"); }
    void SetCurrentKeyFrame(GCPathKeyFrame* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'CurrentKeyFrame' is not possible.\n"); }
    GCPathKeyFrame* GetTargetKeyFrame() const { return GetSchemaValue<GCPathKeyFrame*>(m_ptr, "CBaseMoveBehavior", "m_pTargetKeyFrame"); }
    void SetTargetKeyFrame(GCPathKeyFrame* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetKeyFrame' is not possible.\n"); }
    GCPathKeyFrame* GetPreKeyFrame() const { return GetSchemaValue<GCPathKeyFrame*>(m_ptr, "CBaseMoveBehavior", "m_pPreKeyFrame"); }
    void SetPreKeyFrame(GCPathKeyFrame* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PreKeyFrame' is not possible.\n"); }
    GCPathKeyFrame* GetPostKeyFrame() const { return GetSchemaValue<GCPathKeyFrame*>(m_ptr, "CBaseMoveBehavior", "m_pPostKeyFrame"); }
    void SetPostKeyFrame(GCPathKeyFrame* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PostKeyFrame' is not possible.\n"); }
    float GetTimeIntoFrame() const { return GetSchemaValue<float>(m_ptr, "CBaseMoveBehavior", "m_flTimeIntoFrame"); }
    void SetTimeIntoFrame(float value) { SetSchemaValue(m_ptr, "CBaseMoveBehavior", "m_flTimeIntoFrame", false, value); }
    int32_t GetDirection() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseMoveBehavior", "m_iDirection"); }
    void SetDirection(int32_t value) { SetSchemaValue(m_ptr, "CBaseMoveBehavior", "m_iDirection", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif