class GCSosGroupBranchPattern;

#ifndef _gccsosgroupbranchpattern_h
#define _gccsosgroupbranchpattern_h

#include "../../../scripting.h"




class GCSosGroupBranchPattern
{
private:
    void *m_ptr;

public:
    GCSosGroupBranchPattern() {}
    GCSosGroupBranchPattern(void *ptr) : m_ptr(ptr) {}

    bool GetMatchEventName() const { return GetSchemaValue<bool>(m_ptr, "CSosGroupBranchPattern", "m_bMatchEventName"); }
    void SetMatchEventName(bool value) { SetSchemaValue(m_ptr, "CSosGroupBranchPattern", "m_bMatchEventName", false, value); }
    bool GetMatchEventSubString() const { return GetSchemaValue<bool>(m_ptr, "CSosGroupBranchPattern", "m_bMatchEventSubString"); }
    void SetMatchEventSubString(bool value) { SetSchemaValue(m_ptr, "CSosGroupBranchPattern", "m_bMatchEventSubString", false, value); }
    bool GetMatchEntIndex() const { return GetSchemaValue<bool>(m_ptr, "CSosGroupBranchPattern", "m_bMatchEntIndex"); }
    void SetMatchEntIndex(bool value) { SetSchemaValue(m_ptr, "CSosGroupBranchPattern", "m_bMatchEntIndex", false, value); }
    bool GetMatchOpvar() const { return GetSchemaValue<bool>(m_ptr, "CSosGroupBranchPattern", "m_bMatchOpvar"); }
    void SetMatchOpvar(bool value) { SetSchemaValue(m_ptr, "CSosGroupBranchPattern", "m_bMatchOpvar", false, value); }
    bool GetMatchString() const { return GetSchemaValue<bool>(m_ptr, "CSosGroupBranchPattern", "m_bMatchString"); }
    void SetMatchString(bool value) { SetSchemaValue(m_ptr, "CSosGroupBranchPattern", "m_bMatchString", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif