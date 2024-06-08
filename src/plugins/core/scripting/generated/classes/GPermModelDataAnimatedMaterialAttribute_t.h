class GPermModelDataAnimatedMaterialAttribute_t;

#ifndef _gcpermmodeldataanimatedmaterialattribute_t_h
#define _gcpermmodeldataanimatedmaterialattribute_t_h

#include "../../../scripting.h"




class GPermModelDataAnimatedMaterialAttribute_t
{
private:
    void *m_ptr;

public:
    GPermModelDataAnimatedMaterialAttribute_t() {}
    GPermModelDataAnimatedMaterialAttribute_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetAttributeName() const { return GetSchemaValue<CUtlString>(m_ptr, "PermModelDataAnimatedMaterialAttribute_t", "m_AttributeName"); }
    void SetAttributeName(CUtlString value) { SetSchemaValue(m_ptr, "PermModelDataAnimatedMaterialAttribute_t", "m_AttributeName", true, value); }
    int32_t GetNumChannels() const { return GetSchemaValue<int32_t>(m_ptr, "PermModelDataAnimatedMaterialAttribute_t", "m_nNumChannels"); }
    void SetNumChannels(int32_t value) { SetSchemaValue(m_ptr, "PermModelDataAnimatedMaterialAttribute_t", "m_nNumChannels", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif