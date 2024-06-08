class GIKBoneNameAndIndex_t;

#ifndef _gcikbonenameandindex_t_h
#define _gcikbonenameandindex_t_h

#include "../../../scripting.h"




class GIKBoneNameAndIndex_t
{
private:
    void *m_ptr;

public:
    GIKBoneNameAndIndex_t() {}
    GIKBoneNameAndIndex_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "IKBoneNameAndIndex_t", "m_Name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "IKBoneNameAndIndex_t", "m_Name", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif