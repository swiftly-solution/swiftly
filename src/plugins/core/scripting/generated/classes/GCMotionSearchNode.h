class GCMotionSearchNode;

#ifndef _gccmotionsearchnode_h
#define _gccmotionsearchnode_h

#include "../../../scripting.h"


#include "GCMotionSearchNode.h"
#include "GCVectorQuantizer.h"

class GCMotionSearchNode
{
private:
    void *m_ptr;

public:
    GCMotionSearchNode() {}
    GCMotionSearchNode(void *ptr) : m_ptr(ptr) {}

    std::vector<GCMotionSearchNode*> GetChildren() const { CUtlVector<GCMotionSearchNode*>* vec = GetSchemaValue<CUtlVector<GCMotionSearchNode*>*>(m_ptr, "CMotionSearchNode", "m_children"); std::vector<GCMotionSearchNode*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetChildren(std::vector<GCMotionSearchNode*> value) { SetSchemaValueCUtlVector<GCMotionSearchNode*>(m_ptr, "CMotionSearchNode", "m_children", false, value); }
    GCVectorQuantizer GetQuantizer() const { return GetSchemaValue<GCVectorQuantizer>(m_ptr, "CMotionSearchNode", "m_quantizer"); }
    void SetQuantizer(GCVectorQuantizer value) { SetSchemaValue(m_ptr, "CMotionSearchNode", "m_quantizer", false, value); }
    std::vector<int32> GetSelectableSamples() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CMotionSearchNode", "m_selectableSamples"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSelectableSamples(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "CMotionSearchNode", "m_selectableSamples", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif