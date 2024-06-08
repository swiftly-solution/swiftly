class GCMaterialAttributeAnimTag;

#ifndef _gccmaterialattributeanimtag_h
#define _gccmaterialattributeanimtag_h

#include "../../../scripting.h"

#include "../types/GMatterialAttributeTagType_t.h"


class GCMaterialAttributeAnimTag
{
private:
    void *m_ptr;

public:
    GCMaterialAttributeAnimTag() {}
    GCMaterialAttributeAnimTag(void *ptr) : m_ptr(ptr) {}

    CUtlString GetAttributeName() const { return GetSchemaValue<CUtlString>(m_ptr, "CMaterialAttributeAnimTag", "m_AttributeName"); }
    void SetAttributeName(CUtlString value) { SetSchemaValue(m_ptr, "CMaterialAttributeAnimTag", "m_AttributeName", false, value); }
    MatterialAttributeTagType_t GetAttributeType() const { return GetSchemaValue<MatterialAttributeTagType_t>(m_ptr, "CMaterialAttributeAnimTag", "m_AttributeType"); }
    void SetAttributeType(MatterialAttributeTagType_t value) { SetSchemaValue(m_ptr, "CMaterialAttributeAnimTag", "m_AttributeType", false, value); }
    float GetValue() const { return GetSchemaValue<float>(m_ptr, "CMaterialAttributeAnimTag", "m_flValue"); }
    void SetValue(float value) { SetSchemaValue(m_ptr, "CMaterialAttributeAnimTag", "m_flValue", false, value); }
    Color GetColor() const { return GetSchemaValue<Color>(m_ptr, "CMaterialAttributeAnimTag", "m_Color"); }
    void SetColor(Color value) { SetSchemaValue(m_ptr, "CMaterialAttributeAnimTag", "m_Color", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif