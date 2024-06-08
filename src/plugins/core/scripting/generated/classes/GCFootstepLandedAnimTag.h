class GCFootstepLandedAnimTag;

#ifndef _gccfootsteplandedanimtag_h
#define _gccfootsteplandedanimtag_h

#include "../../../scripting.h"

#include "../types/GFootstepLandedFootSoundType_t.h"


class GCFootstepLandedAnimTag
{
private:
    void *m_ptr;

public:
    GCFootstepLandedAnimTag() {}
    GCFootstepLandedAnimTag(void *ptr) : m_ptr(ptr) {}

    FootstepLandedFootSoundType_t GetFootstepType() const { return GetSchemaValue<FootstepLandedFootSoundType_t>(m_ptr, "CFootstepLandedAnimTag", "m_FootstepType"); }
    void SetFootstepType(FootstepLandedFootSoundType_t value) { SetSchemaValue(m_ptr, "CFootstepLandedAnimTag", "m_FootstepType", false, value); }
    CUtlString GetOverrideSoundName() const { return GetSchemaValue<CUtlString>(m_ptr, "CFootstepLandedAnimTag", "m_OverrideSoundName"); }
    void SetOverrideSoundName(CUtlString value) { SetSchemaValue(m_ptr, "CFootstepLandedAnimTag", "m_OverrideSoundName", false, value); }
    CUtlString GetDebugAnimSourceString() const { return GetSchemaValue<CUtlString>(m_ptr, "CFootstepLandedAnimTag", "m_DebugAnimSourceString"); }
    void SetDebugAnimSourceString(CUtlString value) { SetSchemaValue(m_ptr, "CFootstepLandedAnimTag", "m_DebugAnimSourceString", false, value); }
    CUtlString GetBoneName() const { return GetSchemaValue<CUtlString>(m_ptr, "CFootstepLandedAnimTag", "m_BoneName"); }
    void SetBoneName(CUtlString value) { SetSchemaValue(m_ptr, "CFootstepLandedAnimTag", "m_BoneName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif