class GCAnimNodePath;

#ifndef _gccanimnodepath_h
#define _gccanimnodepath_h

#include "../../../scripting.h"


#include "GAnimNodeID.h"

class GCAnimNodePath
{
private:
    void *m_ptr;

public:
    GCAnimNodePath() {}
    GCAnimNodePath(void *ptr) : m_ptr(ptr) {}

    std::vector<GAnimNodeID> GetPath() const { GAnimNodeID* outValue = GetSchemaValue<GAnimNodeID*>(m_ptr, "CAnimNodePath", "m_path"); std::vector<GAnimNodeID> ret; for(int i = 0; i < 11; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetPath(std::vector<GAnimNodeID> value) { GAnimNodeID* outValue = GetSchemaValue<GAnimNodeID*>(m_ptr, "CAnimNodePath", "m_path"); for(int i = 0; i < 11; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAnimNodePath", "m_path", false, outValue); }
    int32_t GetCount() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimNodePath", "m_nCount"); }
    void SetCount(int32_t value) { SetSchemaValue(m_ptr, "CAnimNodePath", "m_nCount", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif