class GPermModelExtPart_t;

#ifndef _gcpermmodelextpart_t_h
#define _gcpermmodelextpart_t_h

#include "../../../scripting.h"




class GPermModelExtPart_t
{
private:
    void *m_ptr;

public:
    GPermModelExtPart_t() {}
    GPermModelExtPart_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "PermModelExtPart_t", "m_Name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "PermModelExtPart_t", "m_Name", true, value); }
    int32_t GetParent() const { return GetSchemaValue<int32_t>(m_ptr, "PermModelExtPart_t", "m_nParent"); }
    void SetParent(int32_t value) { SetSchemaValue(m_ptr, "PermModelExtPart_t", "m_nParent", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif