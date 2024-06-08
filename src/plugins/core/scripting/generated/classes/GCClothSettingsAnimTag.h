class GCClothSettingsAnimTag;

#ifndef _gccclothsettingsanimtag_h
#define _gccclothsettingsanimtag_h

#include "../../../scripting.h"




class GCClothSettingsAnimTag
{
private:
    void *m_ptr;

public:
    GCClothSettingsAnimTag() {}
    GCClothSettingsAnimTag(void *ptr) : m_ptr(ptr) {}

    float GetStiffness() const { return GetSchemaValue<float>(m_ptr, "CClothSettingsAnimTag", "m_flStiffness"); }
    void SetStiffness(float value) { SetSchemaValue(m_ptr, "CClothSettingsAnimTag", "m_flStiffness", false, value); }
    float GetEaseIn() const { return GetSchemaValue<float>(m_ptr, "CClothSettingsAnimTag", "m_flEaseIn"); }
    void SetEaseIn(float value) { SetSchemaValue(m_ptr, "CClothSettingsAnimTag", "m_flEaseIn", false, value); }
    float GetEaseOut() const { return GetSchemaValue<float>(m_ptr, "CClothSettingsAnimTag", "m_flEaseOut"); }
    void SetEaseOut(float value) { SetSchemaValue(m_ptr, "CClothSettingsAnimTag", "m_flEaseOut", false, value); }
    CUtlString GetVertexSet() const { return GetSchemaValue<CUtlString>(m_ptr, "CClothSettingsAnimTag", "m_nVertexSet"); }
    void SetVertexSet(CUtlString value) { SetSchemaValue(m_ptr, "CClothSettingsAnimTag", "m_nVertexSet", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif