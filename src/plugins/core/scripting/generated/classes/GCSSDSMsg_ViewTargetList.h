class GCSSDSMsg_ViewTargetList;

#ifndef _gccssdsmsg_viewtargetlist_h
#define _gccssdsmsg_viewtargetlist_h

#include "../../../scripting.h"


#include "GSceneViewId_t.h"
#include "GCSSDSMsg_ViewTarget.h"

class GCSSDSMsg_ViewTargetList
{
private:
    void *m_ptr;

public:
    GCSSDSMsg_ViewTargetList() {}
    GCSSDSMsg_ViewTargetList(void *ptr) : m_ptr(ptr) {}

    GSceneViewId_t GetViewId() const { return GetSchemaValue<GSceneViewId_t>(m_ptr, "CSSDSMsg_ViewTargetList", "m_viewId"); }
    void SetViewId(GSceneViewId_t value) { SetSchemaValue(m_ptr, "CSSDSMsg_ViewTargetList", "m_viewId", false, value); }
    CUtlString GetViewName() const { return GetSchemaValue<CUtlString>(m_ptr, "CSSDSMsg_ViewTargetList", "m_ViewName"); }
    void SetViewName(CUtlString value) { SetSchemaValue(m_ptr, "CSSDSMsg_ViewTargetList", "m_ViewName", false, value); }
    std::vector<GCSSDSMsg_ViewTarget> GetTargets() const { CUtlVector<GCSSDSMsg_ViewTarget>* vec = GetSchemaValue<CUtlVector<GCSSDSMsg_ViewTarget>*>(m_ptr, "CSSDSMsg_ViewTargetList", "m_Targets"); std::vector<GCSSDSMsg_ViewTarget> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTargets(std::vector<GCSSDSMsg_ViewTarget> value) { SetSchemaValueCUtlVector<GCSSDSMsg_ViewTarget>(m_ptr, "CSSDSMsg_ViewTargetList", "m_Targets", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif