class GCBodyGroupAnimTag;

#ifndef _gccbodygroupanimtag_h
#define _gccbodygroupanimtag_h

#include "../../../scripting.h"


#include "GCBodyGroupSetting.h"

class GCBodyGroupAnimTag
{
private:
    void *m_ptr;

public:
    GCBodyGroupAnimTag() {}
    GCBodyGroupAnimTag(void *ptr) : m_ptr(ptr) {}

    int32_t GetPriority() const { return GetSchemaValue<int32_t>(m_ptr, "CBodyGroupAnimTag", "m_nPriority"); }
    void SetPriority(int32_t value) { SetSchemaValue(m_ptr, "CBodyGroupAnimTag", "m_nPriority", false, value); }
    std::vector<GCBodyGroupSetting> GetBodyGroupSettings() const { CUtlVector<GCBodyGroupSetting>* vec = GetSchemaValue<CUtlVector<GCBodyGroupSetting>*>(m_ptr, "CBodyGroupAnimTag", "m_bodyGroupSettings"); std::vector<GCBodyGroupSetting> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBodyGroupSettings(std::vector<GCBodyGroupSetting> value) { SetSchemaValueCUtlVector<GCBodyGroupSetting>(m_ptr, "CBodyGroupAnimTag", "m_bodyGroupSettings", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif