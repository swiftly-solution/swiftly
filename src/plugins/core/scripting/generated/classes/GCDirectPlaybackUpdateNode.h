class GCDirectPlaybackUpdateNode;

#ifndef _gccdirectplaybackupdatenode_h
#define _gccdirectplaybackupdatenode_h

#include "../../../scripting.h"


#include "GCDirectPlaybackTagData.h"

class GCDirectPlaybackUpdateNode
{
private:
    void *m_ptr;

public:
    GCDirectPlaybackUpdateNode() {}
    GCDirectPlaybackUpdateNode(void *ptr) : m_ptr(ptr) {}

    bool GetFinishEarly() const { return GetSchemaValue<bool>(m_ptr, "CDirectPlaybackUpdateNode", "m_bFinishEarly"); }
    void SetFinishEarly(bool value) { SetSchemaValue(m_ptr, "CDirectPlaybackUpdateNode", "m_bFinishEarly", false, value); }
    bool GetResetOnFinish() const { return GetSchemaValue<bool>(m_ptr, "CDirectPlaybackUpdateNode", "m_bResetOnFinish"); }
    void SetResetOnFinish(bool value) { SetSchemaValue(m_ptr, "CDirectPlaybackUpdateNode", "m_bResetOnFinish", false, value); }
    std::vector<GCDirectPlaybackTagData> GetAllTags() const { CUtlVector<GCDirectPlaybackTagData>* vec = GetSchemaValue<CUtlVector<GCDirectPlaybackTagData>*>(m_ptr, "CDirectPlaybackUpdateNode", "m_allTags"); std::vector<GCDirectPlaybackTagData> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetAllTags(std::vector<GCDirectPlaybackTagData> value) { SetSchemaValueCUtlVector<GCDirectPlaybackTagData>(m_ptr, "CDirectPlaybackUpdateNode", "m_allTags", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif