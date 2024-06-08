class GCHitBoxSetList;

#ifndef _gcchitboxsetlist_h
#define _gcchitboxsetlist_h

#include "../../../scripting.h"


#include "GCHitBox.h"
#include "GCHitBoxSet.h"

class GCHitBoxSetList
{
private:
    void *m_ptr;

public:
    GCHitBoxSetList() {}
    GCHitBoxSetList(void *ptr) : m_ptr(ptr) {}

    std::vector<GCHitBoxSet> GetHitBoxSets() const { CUtlVector<GCHitBoxSet>* vec = GetSchemaValue<CUtlVector<GCHitBoxSet>*>(m_ptr, "CHitBoxSetList", "m_HitBoxSets"); std::vector<GCHitBoxSet> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetHitBoxSets(std::vector<GCHitBoxSet> value) { SetSchemaValueCUtlVector<GCHitBoxSet>(m_ptr, "CHitBoxSetList", "m_HitBoxSets", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif