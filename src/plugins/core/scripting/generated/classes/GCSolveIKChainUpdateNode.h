class GCSolveIKChainUpdateNode;

#ifndef _gccsolveikchainupdatenode_h
#define _gccsolveikchainupdatenode_h

#include "../../../scripting.h"


#include "GCSolveIKTargetHandle_t.h"
#include "GSolveIKChainPoseOpFixedSettings_t.h"

class GCSolveIKChainUpdateNode
{
private:
    void *m_ptr;

public:
    GCSolveIKChainUpdateNode() {}
    GCSolveIKChainUpdateNode(void *ptr) : m_ptr(ptr) {}

    std::vector<GCSolveIKTargetHandle_t> GetTargetHandles() const { CUtlVector<GCSolveIKTargetHandle_t>* vec = GetSchemaValue<CUtlVector<GCSolveIKTargetHandle_t>*>(m_ptr, "CSolveIKChainUpdateNode", "m_targetHandles"); std::vector<GCSolveIKTargetHandle_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTargetHandles(std::vector<GCSolveIKTargetHandle_t> value) { SetSchemaValueCUtlVector<GCSolveIKTargetHandle_t>(m_ptr, "CSolveIKChainUpdateNode", "m_targetHandles", false, value); }
    GSolveIKChainPoseOpFixedSettings_t GetOpFixedData() const { return GetSchemaValue<GSolveIKChainPoseOpFixedSettings_t>(m_ptr, "CSolveIKChainUpdateNode", "m_opFixedData"); }
    void SetOpFixedData(GSolveIKChainPoseOpFixedSettings_t value) { SetSchemaValue(m_ptr, "CSolveIKChainUpdateNode", "m_opFixedData", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif