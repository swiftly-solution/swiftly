class GCFootStepTriggerUpdateNode;

#ifndef _gccfootsteptriggerupdatenode_h
#define _gccfootsteptriggerupdatenode_h

#include "../../../scripting.h"


#include "GFootStepTrigger.h"

class GCFootStepTriggerUpdateNode
{
private:
    void *m_ptr;

public:
    GCFootStepTriggerUpdateNode() {}
    GCFootStepTriggerUpdateNode(void *ptr) : m_ptr(ptr) {}

    std::vector<GFootStepTrigger> GetTriggers() const { CUtlVector<GFootStepTrigger>* vec = GetSchemaValue<CUtlVector<GFootStepTrigger>*>(m_ptr, "CFootStepTriggerUpdateNode", "m_triggers"); std::vector<GFootStepTrigger> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTriggers(std::vector<GFootStepTrigger> value) { SetSchemaValueCUtlVector<GFootStepTrigger>(m_ptr, "CFootStepTriggerUpdateNode", "m_triggers", false, value); }
    float GetTolerance() const { return GetSchemaValue<float>(m_ptr, "CFootStepTriggerUpdateNode", "m_flTolerance"); }
    void SetTolerance(float value) { SetSchemaValue(m_ptr, "CFootStepTriggerUpdateNode", "m_flTolerance", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif