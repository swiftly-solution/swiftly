class GFootFixedSettings;

#ifndef _gcfootfixedsettings_h
#define _gcfootfixedsettings_h

#include "../../../scripting.h"


#include "GTraceSettings_t.h"

class GFootFixedSettings
{
private:
    void *m_ptr;

public:
    GFootFixedSettings() {}
    GFootFixedSettings(void *ptr) : m_ptr(ptr) {}

    GTraceSettings_t GetTraceSettings() const { return GetSchemaValue<GTraceSettings_t>(m_ptr, "FootFixedSettings", "m_traceSettings"); }
    void SetTraceSettings(GTraceSettings_t value) { SetSchemaValue(m_ptr, "FootFixedSettings", "m_traceSettings", false, value); }
    Vector GetFootBaseBindPosePositionMS() const { return GetSchemaValue<Vector>(m_ptr, "FootFixedSettings", "m_vFootBaseBindPosePositionMS"); }
    void SetFootBaseBindPosePositionMS(Vector value) { SetSchemaValue(m_ptr, "FootFixedSettings", "m_vFootBaseBindPosePositionMS", false, value); }
    float GetFootBaseLength() const { return GetSchemaValue<float>(m_ptr, "FootFixedSettings", "m_flFootBaseLength"); }
    void SetFootBaseLength(float value) { SetSchemaValue(m_ptr, "FootFixedSettings", "m_flFootBaseLength", false, value); }
    float GetMaxRotationLeft() const { return GetSchemaValue<float>(m_ptr, "FootFixedSettings", "m_flMaxRotationLeft"); }
    void SetMaxRotationLeft(float value) { SetSchemaValue(m_ptr, "FootFixedSettings", "m_flMaxRotationLeft", false, value); }
    float GetMaxRotationRight() const { return GetSchemaValue<float>(m_ptr, "FootFixedSettings", "m_flMaxRotationRight"); }
    void SetMaxRotationRight(float value) { SetSchemaValue(m_ptr, "FootFixedSettings", "m_flMaxRotationRight", false, value); }
    int32_t GetFootstepLandedTagIndex() const { return GetSchemaValue<int32_t>(m_ptr, "FootFixedSettings", "m_footstepLandedTagIndex"); }
    void SetFootstepLandedTagIndex(int32_t value) { SetSchemaValue(m_ptr, "FootFixedSettings", "m_footstepLandedTagIndex", false, value); }
    bool GetEnableTracing() const { return GetSchemaValue<bool>(m_ptr, "FootFixedSettings", "m_bEnableTracing"); }
    void SetEnableTracing(bool value) { SetSchemaValue(m_ptr, "FootFixedSettings", "m_bEnableTracing", false, value); }
    float GetTraceAngleBlend() const { return GetSchemaValue<float>(m_ptr, "FootFixedSettings", "m_flTraceAngleBlend"); }
    void SetTraceAngleBlend(float value) { SetSchemaValue(m_ptr, "FootFixedSettings", "m_flTraceAngleBlend", false, value); }
    int32_t GetDisableTagIndex() const { return GetSchemaValue<int32_t>(m_ptr, "FootFixedSettings", "m_nDisableTagIndex"); }
    void SetDisableTagIndex(int32_t value) { SetSchemaValue(m_ptr, "FootFixedSettings", "m_nDisableTagIndex", false, value); }
    int32_t GetFootIndex() const { return GetSchemaValue<int32_t>(m_ptr, "FootFixedSettings", "m_nFootIndex"); }
    void SetFootIndex(int32_t value) { SetSchemaValue(m_ptr, "FootFixedSettings", "m_nFootIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif