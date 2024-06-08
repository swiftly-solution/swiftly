class GC_OP_SelectivelyEnableChildren;

#ifndef _gcc_op_selectivelyenablechildren_h
#define _gcc_op_selectivelyenablechildren_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_SelectivelyEnableChildren
{
private:
    void *m_ptr;

public:
    GC_OP_SelectivelyEnableChildren() {}
    GC_OP_SelectivelyEnableChildren(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetChildGroupID() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SelectivelyEnableChildren", "m_nChildGroupID"); }
    void SetChildGroupID(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SelectivelyEnableChildren", "m_nChildGroupID", false, value); }
    GCParticleCollectionFloatInput GetFirstChild() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SelectivelyEnableChildren", "m_nFirstChild"); }
    void SetFirstChild(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SelectivelyEnableChildren", "m_nFirstChild", false, value); }
    GCParticleCollectionFloatInput GetNumChildrenToEnable() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SelectivelyEnableChildren", "m_nNumChildrenToEnable"); }
    void SetNumChildrenToEnable(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SelectivelyEnableChildren", "m_nNumChildrenToEnable", false, value); }
    bool GetPlayEndcapOnStop() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SelectivelyEnableChildren", "m_bPlayEndcapOnStop"); }
    void SetPlayEndcapOnStop(bool value) { SetSchemaValue(m_ptr, "C_OP_SelectivelyEnableChildren", "m_bPlayEndcapOnStop", false, value); }
    bool GetDestroyImmediately() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SelectivelyEnableChildren", "m_bDestroyImmediately"); }
    void SetDestroyImmediately(bool value) { SetSchemaValue(m_ptr, "C_OP_SelectivelyEnableChildren", "m_bDestroyImmediately", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif