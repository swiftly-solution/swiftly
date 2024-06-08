class GCRagdollUpdateNode;

#ifndef _gccragdollupdatenode_h
#define _gccragdollupdatenode_h

#include "../../../scripting.h"

#include "../types/GRagdollPoseControl.h"


class GCRagdollUpdateNode
{
private:
    void *m_ptr;

public:
    GCRagdollUpdateNode() {}
    GCRagdollUpdateNode(void *ptr) : m_ptr(ptr) {}

    int32_t GetWeightListIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CRagdollUpdateNode", "m_nWeightListIndex"); }
    void SetWeightListIndex(int32_t value) { SetSchemaValue(m_ptr, "CRagdollUpdateNode", "m_nWeightListIndex", false, value); }
    RagdollPoseControl GetPoseControlMethod() const { return GetSchemaValue<RagdollPoseControl>(m_ptr, "CRagdollUpdateNode", "m_poseControlMethod"); }
    void SetPoseControlMethod(RagdollPoseControl value) { SetSchemaValue(m_ptr, "CRagdollUpdateNode", "m_poseControlMethod", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif