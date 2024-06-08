class GCAudioAnimTag;

#ifndef _gccaudioanimtag_h
#define _gccaudioanimtag_h

#include "../../../scripting.h"




class GCAudioAnimTag
{
private:
    void *m_ptr;

public:
    GCAudioAnimTag() {}
    GCAudioAnimTag(void *ptr) : m_ptr(ptr) {}

    CUtlString GetClipName() const { return GetSchemaValue<CUtlString>(m_ptr, "CAudioAnimTag", "m_clipName"); }
    void SetClipName(CUtlString value) { SetSchemaValue(m_ptr, "CAudioAnimTag", "m_clipName", false, value); }
    CUtlString GetAttachmentName() const { return GetSchemaValue<CUtlString>(m_ptr, "CAudioAnimTag", "m_attachmentName"); }
    void SetAttachmentName(CUtlString value) { SetSchemaValue(m_ptr, "CAudioAnimTag", "m_attachmentName", false, value); }
    float GetVolume() const { return GetSchemaValue<float>(m_ptr, "CAudioAnimTag", "m_flVolume"); }
    void SetVolume(float value) { SetSchemaValue(m_ptr, "CAudioAnimTag", "m_flVolume", false, value); }
    bool GetStopWhenTagEnds() const { return GetSchemaValue<bool>(m_ptr, "CAudioAnimTag", "m_bStopWhenTagEnds"); }
    void SetStopWhenTagEnds(bool value) { SetSchemaValue(m_ptr, "CAudioAnimTag", "m_bStopWhenTagEnds", false, value); }
    bool GetStopWhenGraphEnds() const { return GetSchemaValue<bool>(m_ptr, "CAudioAnimTag", "m_bStopWhenGraphEnds"); }
    void SetStopWhenGraphEnds(bool value) { SetSchemaValue(m_ptr, "CAudioAnimTag", "m_bStopWhenGraphEnds", false, value); }
    bool GetPlayOnServer() const { return GetSchemaValue<bool>(m_ptr, "CAudioAnimTag", "m_bPlayOnServer"); }
    void SetPlayOnServer(bool value) { SetSchemaValue(m_ptr, "CAudioAnimTag", "m_bPlayOnServer", false, value); }
    bool GetPlayOnClient() const { return GetSchemaValue<bool>(m_ptr, "CAudioAnimTag", "m_bPlayOnClient"); }
    void SetPlayOnClient(bool value) { SetSchemaValue(m_ptr, "CAudioAnimTag", "m_bPlayOnClient", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif