class GC_OP_ChooseRandomChildrenInGroup;

#ifndef _gcc_op_chooserandomchildreningroup_h
#define _gcc_op_chooserandomchildreningroup_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_ChooseRandomChildrenInGroup
{
private:
    void *m_ptr;

public:
    GC_OP_ChooseRandomChildrenInGroup() {}
    GC_OP_ChooseRandomChildrenInGroup(void *ptr) : m_ptr(ptr) {}

    int32_t GetChildGroupID() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_ChooseRandomChildrenInGroup", "m_nChildGroupID"); }
    void SetChildGroupID(int32_t value) { SetSchemaValue(m_ptr, "C_OP_ChooseRandomChildrenInGroup", "m_nChildGroupID", false, value); }
    GCParticleCollectionFloatInput GetNumberOfChildren() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_ChooseRandomChildrenInGroup", "m_flNumberOfChildren"); }
    void SetNumberOfChildren(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ChooseRandomChildrenInGroup", "m_flNumberOfChildren", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif