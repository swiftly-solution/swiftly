class GBlendItem_t;

#ifndef _gcblenditem_t_h
#define _gcblenditem_t_h

#include "../../../scripting.h"


#include "GTagSpan_t.h"
#include "GCAnimUpdateNodeRef.h"

class GBlendItem_t
{
private:
    void *m_ptr;

public:
    GBlendItem_t() {}
    GBlendItem_t(void *ptr) : m_ptr(ptr) {}

    std::vector<GTagSpan_t> GetTags() const { CUtlVector<GTagSpan_t>* vec = GetSchemaValue<CUtlVector<GTagSpan_t>*>(m_ptr, "BlendItem_t", "m_tags"); std::vector<GTagSpan_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTags(std::vector<GTagSpan_t> value) { SetSchemaValueCUtlVector<GTagSpan_t>(m_ptr, "BlendItem_t", "m_tags", true, value); }
    GCAnimUpdateNodeRef GetChild() const { return GetSchemaValue<GCAnimUpdateNodeRef>(m_ptr, "BlendItem_t", "m_pChild"); }
    void SetChild(GCAnimUpdateNodeRef value) { SetSchemaValue(m_ptr, "BlendItem_t", "m_pChild", true, value); }
    Vector2D GetPos() const { return GetSchemaValue<Vector2D>(m_ptr, "BlendItem_t", "m_vPos"); }
    void SetPos(Vector2D value) { SetSchemaValue(m_ptr, "BlendItem_t", "m_vPos", true, value); }
    float GetDuration() const { return GetSchemaValue<float>(m_ptr, "BlendItem_t", "m_flDuration"); }
    void SetDuration(float value) { SetSchemaValue(m_ptr, "BlendItem_t", "m_flDuration", true, value); }
    bool GetUseCustomDuration() const { return GetSchemaValue<bool>(m_ptr, "BlendItem_t", "m_bUseCustomDuration"); }
    void SetUseCustomDuration(bool value) { SetSchemaValue(m_ptr, "BlendItem_t", "m_bUseCustomDuration", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif