class GCSosGroupMatchPattern;

#ifndef _gccsosgroupmatchpattern_h
#define _gccsosgroupmatchpattern_h

#include "../../../scripting.h"




class GCSosGroupMatchPattern
{
private:
    void *m_ptr;

public:
    GCSosGroupMatchPattern() {}
    GCSosGroupMatchPattern(void *ptr) : m_ptr(ptr) {}

    CUtlString GetMatchSoundEventName() const { return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupMatchPattern", "m_matchSoundEventName"); }
    void SetMatchSoundEventName(CUtlString value) { SetSchemaValue(m_ptr, "CSosGroupMatchPattern", "m_matchSoundEventName", false, value); }
    CUtlString GetMatchSoundEventSubString() const { return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupMatchPattern", "m_matchSoundEventSubString"); }
    void SetMatchSoundEventSubString(CUtlString value) { SetSchemaValue(m_ptr, "CSosGroupMatchPattern", "m_matchSoundEventSubString", false, value); }
    float GetEntIndex() const { return GetSchemaValue<float>(m_ptr, "CSosGroupMatchPattern", "m_flEntIndex"); }
    void SetEntIndex(float value) { SetSchemaValue(m_ptr, "CSosGroupMatchPattern", "m_flEntIndex", false, value); }
    float GetOpvar() const { return GetSchemaValue<float>(m_ptr, "CSosGroupMatchPattern", "m_flOpvar"); }
    void SetOpvar(float value) { SetSchemaValue(m_ptr, "CSosGroupMatchPattern", "m_flOpvar", false, value); }
    CUtlString GetOpvarString() const { return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupMatchPattern", "m_opvarString"); }
    void SetOpvarString(CUtlString value) { SetSchemaValue(m_ptr, "CSosGroupMatchPattern", "m_opvarString", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif