class GC_OP_EnableChildrenFromParentParticleCount;

#ifndef _gcc_op_enablechildrenfromparentparticlecount_h
#define _gcc_op_enablechildrenfromparentparticlecount_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_EnableChildrenFromParentParticleCount
{
private:
    void *m_ptr;

public:
    GC_OP_EnableChildrenFromParentParticleCount() {}
    GC_OP_EnableChildrenFromParentParticleCount(void *ptr) : m_ptr(ptr) {}

    int32_t GetChildGroupID() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_EnableChildrenFromParentParticleCount", "m_nChildGroupID"); }
    void SetChildGroupID(int32_t value) { SetSchemaValue(m_ptr, "C_OP_EnableChildrenFromParentParticleCount", "m_nChildGroupID", false, value); }
    int32_t GetFirstChild() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_EnableChildrenFromParentParticleCount", "m_nFirstChild"); }
    void SetFirstChild(int32_t value) { SetSchemaValue(m_ptr, "C_OP_EnableChildrenFromParentParticleCount", "m_nFirstChild", false, value); }
    GCParticleCollectionFloatInput GetNumChildrenToEnable() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_EnableChildrenFromParentParticleCount", "m_nNumChildrenToEnable"); }
    void SetNumChildrenToEnable(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_EnableChildrenFromParentParticleCount", "m_nNumChildrenToEnable", false, value); }
    bool GetDisableChildren() const { return GetSchemaValue<bool>(m_ptr, "C_OP_EnableChildrenFromParentParticleCount", "m_bDisableChildren"); }
    void SetDisableChildren(bool value) { SetSchemaValue(m_ptr, "C_OP_EnableChildrenFromParentParticleCount", "m_bDisableChildren", false, value); }
    bool GetPlayEndcapOnStop() const { return GetSchemaValue<bool>(m_ptr, "C_OP_EnableChildrenFromParentParticleCount", "m_bPlayEndcapOnStop"); }
    void SetPlayEndcapOnStop(bool value) { SetSchemaValue(m_ptr, "C_OP_EnableChildrenFromParentParticleCount", "m_bPlayEndcapOnStop", false, value); }
    bool GetDestroyImmediately() const { return GetSchemaValue<bool>(m_ptr, "C_OP_EnableChildrenFromParentParticleCount", "m_bDestroyImmediately"); }
    void SetDestroyImmediately(bool value) { SetSchemaValue(m_ptr, "C_OP_EnableChildrenFromParentParticleCount", "m_bDestroyImmediately", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif