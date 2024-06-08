class GFollowAttachmentSettings_t;

#ifndef _gcfollowattachmentsettings_t_h
#define _gcfollowattachmentsettings_t_h

#include "../../../scripting.h"


#include "GCAnimAttachment.h"

class GFollowAttachmentSettings_t
{
private:
    void *m_ptr;

public:
    GFollowAttachmentSettings_t() {}
    GFollowAttachmentSettings_t(void *ptr) : m_ptr(ptr) {}

    GCAnimAttachment GetAttachment() const { return GetSchemaValue<GCAnimAttachment>(m_ptr, "FollowAttachmentSettings_t", "m_attachment"); }
    void SetAttachment(GCAnimAttachment value) { SetSchemaValue(m_ptr, "FollowAttachmentSettings_t", "m_attachment", true, value); }
    int32_t GetBoneIndex() const { return GetSchemaValue<int32_t>(m_ptr, "FollowAttachmentSettings_t", "m_boneIndex"); }
    void SetBoneIndex(int32_t value) { SetSchemaValue(m_ptr, "FollowAttachmentSettings_t", "m_boneIndex", true, value); }
    bool GetMatchTranslation() const { return GetSchemaValue<bool>(m_ptr, "FollowAttachmentSettings_t", "m_bMatchTranslation"); }
    void SetMatchTranslation(bool value) { SetSchemaValue(m_ptr, "FollowAttachmentSettings_t", "m_bMatchTranslation", true, value); }
    bool GetMatchRotation() const { return GetSchemaValue<bool>(m_ptr, "FollowAttachmentSettings_t", "m_bMatchRotation"); }
    void SetMatchRotation(bool value) { SetSchemaValue(m_ptr, "FollowAttachmentSettings_t", "m_bMatchRotation", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif