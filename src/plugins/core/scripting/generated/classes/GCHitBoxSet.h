class GCHitBoxSet;

#ifndef _gcchitboxset_h
#define _gcchitboxset_h

#include "../../../scripting.h"


#include "GCHitBox.h"

class GCHitBoxSet
{
private:
    void *m_ptr;

public:
    GCHitBoxSet() {}
    GCHitBoxSet(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CHitBoxSet", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "CHitBoxSet", "m_name", false, value); }
    uint32_t GetNameHash() const { return GetSchemaValue<uint32_t>(m_ptr, "CHitBoxSet", "m_nNameHash"); }
    void SetNameHash(uint32_t value) { SetSchemaValue(m_ptr, "CHitBoxSet", "m_nNameHash", false, value); }
    std::vector<GCHitBox> GetHitBoxes() const { CUtlVector<GCHitBox>* vec = GetSchemaValue<CUtlVector<GCHitBox>*>(m_ptr, "CHitBoxSet", "m_HitBoxes"); std::vector<GCHitBox> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetHitBoxes(std::vector<GCHitBox> value) { SetSchemaValueCUtlVector<GCHitBox>(m_ptr, "CHitBoxSet", "m_HitBoxes", false, value); }
    CUtlString GetSourceFilename() const { return GetSchemaValue<CUtlString>(m_ptr, "CHitBoxSet", "m_SourceFilename"); }
    void SetSourceFilename(CUtlString value) { SetSchemaValue(m_ptr, "CHitBoxSet", "m_SourceFilename", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif