class GCSSDSEndFrameViewInfo;

#ifndef _gccssdsendframeviewinfo_h
#define _gccssdsendframeviewinfo_h

#include "../../../scripting.h"




class GCSSDSEndFrameViewInfo
{
private:
    void *m_ptr;

public:
    GCSSDSEndFrameViewInfo() {}
    GCSSDSEndFrameViewInfo(void *ptr) : m_ptr(ptr) {}

    uint64_t GetViewId() const { return GetSchemaValue<uint64_t>(m_ptr, "CSSDSEndFrameViewInfo", "m_nViewId"); }
    void SetViewId(uint64_t value) { SetSchemaValue(m_ptr, "CSSDSEndFrameViewInfo", "m_nViewId", false, value); }
    CUtlString GetViewName() const { return GetSchemaValue<CUtlString>(m_ptr, "CSSDSEndFrameViewInfo", "m_ViewName"); }
    void SetViewName(CUtlString value) { SetSchemaValue(m_ptr, "CSSDSEndFrameViewInfo", "m_ViewName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif