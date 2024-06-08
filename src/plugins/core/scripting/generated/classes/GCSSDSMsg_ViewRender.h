class GCSSDSMsg_ViewRender;

#ifndef _gccssdsmsg_viewrender_h
#define _gccssdsmsg_viewrender_h

#include "../../../scripting.h"


#include "GSceneViewId_t.h"

class GCSSDSMsg_ViewRender
{
private:
    void *m_ptr;

public:
    GCSSDSMsg_ViewRender() {}
    GCSSDSMsg_ViewRender(void *ptr) : m_ptr(ptr) {}

    GSceneViewId_t GetViewId() const { return GetSchemaValue<GSceneViewId_t>(m_ptr, "CSSDSMsg_ViewRender", "m_viewId"); }
    void SetViewId(GSceneViewId_t value) { SetSchemaValue(m_ptr, "CSSDSMsg_ViewRender", "m_viewId", false, value); }
    CUtlString GetViewName() const { return GetSchemaValue<CUtlString>(m_ptr, "CSSDSMsg_ViewRender", "m_ViewName"); }
    void SetViewName(CUtlString value) { SetSchemaValue(m_ptr, "CSSDSMsg_ViewRender", "m_ViewName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif