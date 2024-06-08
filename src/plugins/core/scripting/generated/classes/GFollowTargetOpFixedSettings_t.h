class GFollowTargetOpFixedSettings_t;

#ifndef _gcfollowtargetopfixedsettings_t_h
#define _gcfollowtargetopfixedsettings_t_h

#include "../../../scripting.h"




class GFollowTargetOpFixedSettings_t
{
private:
    void *m_ptr;

public:
    GFollowTargetOpFixedSettings_t() {}
    GFollowTargetOpFixedSettings_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetBoneIndex() const { return GetSchemaValue<int32_t>(m_ptr, "FollowTargetOpFixedSettings_t", "m_boneIndex"); }
    void SetBoneIndex(int32_t value) { SetSchemaValue(m_ptr, "FollowTargetOpFixedSettings_t", "m_boneIndex", true, value); }
    bool GetBoneTarget() const { return GetSchemaValue<bool>(m_ptr, "FollowTargetOpFixedSettings_t", "m_bBoneTarget"); }
    void SetBoneTarget(bool value) { SetSchemaValue(m_ptr, "FollowTargetOpFixedSettings_t", "m_bBoneTarget", true, value); }
    int32_t GetBoneTargetIndex() const { return GetSchemaValue<int32_t>(m_ptr, "FollowTargetOpFixedSettings_t", "m_boneTargetIndex"); }
    void SetBoneTargetIndex(int32_t value) { SetSchemaValue(m_ptr, "FollowTargetOpFixedSettings_t", "m_boneTargetIndex", true, value); }
    bool GetWorldCoodinateTarget() const { return GetSchemaValue<bool>(m_ptr, "FollowTargetOpFixedSettings_t", "m_bWorldCoodinateTarget"); }
    void SetWorldCoodinateTarget(bool value) { SetSchemaValue(m_ptr, "FollowTargetOpFixedSettings_t", "m_bWorldCoodinateTarget", true, value); }
    bool GetMatchTargetOrientation() const { return GetSchemaValue<bool>(m_ptr, "FollowTargetOpFixedSettings_t", "m_bMatchTargetOrientation"); }
    void SetMatchTargetOrientation(bool value) { SetSchemaValue(m_ptr, "FollowTargetOpFixedSettings_t", "m_bMatchTargetOrientation", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif