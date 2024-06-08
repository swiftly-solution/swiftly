class GCSSDSMsg_EndFrame;

#ifndef _gccssdsmsg_endframe_h
#define _gccssdsmsg_endframe_h

#include "../../../scripting.h"


#include "GCSSDSEndFrameViewInfo.h"

class GCSSDSMsg_EndFrame
{
private:
    void *m_ptr;

public:
    GCSSDSMsg_EndFrame() {}
    GCSSDSMsg_EndFrame(void *ptr) : m_ptr(ptr) {}

    std::vector<GCSSDSEndFrameViewInfo> GetViews() const { CUtlVector<GCSSDSEndFrameViewInfo>* vec = GetSchemaValue<CUtlVector<GCSSDSEndFrameViewInfo>*>(m_ptr, "CSSDSMsg_EndFrame", "m_Views"); std::vector<GCSSDSEndFrameViewInfo> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetViews(std::vector<GCSSDSEndFrameViewInfo> value) { SetSchemaValueCUtlVector<GCSSDSEndFrameViewInfo>(m_ptr, "CSSDSMsg_EndFrame", "m_Views", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif