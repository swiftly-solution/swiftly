class GCRagdollAnimTag;

#ifndef _gccragdollanimtag_h
#define _gccragdollanimtag_h

#include "../../../scripting.h"

#include "../types/GAnimPoseControl.h"


class GCRagdollAnimTag
{
private:
    void *m_ptr;

public:
    GCRagdollAnimTag() {}
    GCRagdollAnimTag(void *ptr) : m_ptr(ptr) {}

    AnimPoseControl GetPoseControl() const { return GetSchemaValue<AnimPoseControl>(m_ptr, "CRagdollAnimTag", "m_nPoseControl"); }
    void SetPoseControl(AnimPoseControl value) { SetSchemaValue(m_ptr, "CRagdollAnimTag", "m_nPoseControl", false, value); }
    float GetFrequency() const { return GetSchemaValue<float>(m_ptr, "CRagdollAnimTag", "m_flFrequency"); }
    void SetFrequency(float value) { SetSchemaValue(m_ptr, "CRagdollAnimTag", "m_flFrequency", false, value); }
    float GetDampingRatio() const { return GetSchemaValue<float>(m_ptr, "CRagdollAnimTag", "m_flDampingRatio"); }
    void SetDampingRatio(float value) { SetSchemaValue(m_ptr, "CRagdollAnimTag", "m_flDampingRatio", false, value); }
    float GetDecayDuration() const { return GetSchemaValue<float>(m_ptr, "CRagdollAnimTag", "m_flDecayDuration"); }
    void SetDecayDuration(float value) { SetSchemaValue(m_ptr, "CRagdollAnimTag", "m_flDecayDuration", false, value); }
    float GetDecayBias() const { return GetSchemaValue<float>(m_ptr, "CRagdollAnimTag", "m_flDecayBias"); }
    void SetDecayBias(float value) { SetSchemaValue(m_ptr, "CRagdollAnimTag", "m_flDecayBias", false, value); }
    bool GetDestroy() const { return GetSchemaValue<bool>(m_ptr, "CRagdollAnimTag", "m_bDestroy"); }
    void SetDestroy(bool value) { SetSchemaValue(m_ptr, "CRagdollAnimTag", "m_bDestroy", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif