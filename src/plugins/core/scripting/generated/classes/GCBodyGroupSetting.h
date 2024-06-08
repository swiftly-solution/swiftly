class GCBodyGroupSetting;

#ifndef _gccbodygroupsetting_h
#define _gccbodygroupsetting_h

#include "../../../scripting.h"




class GCBodyGroupSetting
{
private:
    void *m_ptr;

public:
    GCBodyGroupSetting() {}
    GCBodyGroupSetting(void *ptr) : m_ptr(ptr) {}

    CUtlString GetBodyGroupName() const { return GetSchemaValue<CUtlString>(m_ptr, "CBodyGroupSetting", "m_BodyGroupName"); }
    void SetBodyGroupName(CUtlString value) { SetSchemaValue(m_ptr, "CBodyGroupSetting", "m_BodyGroupName", false, value); }
    int32_t GetBodyGroupOption() const { return GetSchemaValue<int32_t>(m_ptr, "CBodyGroupSetting", "m_nBodyGroupOption"); }
    void SetBodyGroupOption(int32_t value) { SetSchemaValue(m_ptr, "CBodyGroupSetting", "m_nBodyGroupOption", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif