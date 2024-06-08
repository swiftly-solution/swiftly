class GC_OP_RepeatedTriggerChildGroup;

#ifndef _gcc_op_repeatedtriggerchildgroup_h
#define _gcc_op_repeatedtriggerchildgroup_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_RepeatedTriggerChildGroup
{
private:
    void *m_ptr;

public:
    GC_OP_RepeatedTriggerChildGroup() {}
    GC_OP_RepeatedTriggerChildGroup(void *ptr) : m_ptr(ptr) {}

    int32_t GetChildGroupID() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RepeatedTriggerChildGroup", "m_nChildGroupID"); }
    void SetChildGroupID(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RepeatedTriggerChildGroup", "m_nChildGroupID", false, value); }
    GCParticleCollectionFloatInput GetClusterRefireTime() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RepeatedTriggerChildGroup", "m_flClusterRefireTime"); }
    void SetClusterRefireTime(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RepeatedTriggerChildGroup", "m_flClusterRefireTime", false, value); }
    GCParticleCollectionFloatInput GetClusterSize() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RepeatedTriggerChildGroup", "m_flClusterSize"); }
    void SetClusterSize(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RepeatedTriggerChildGroup", "m_flClusterSize", false, value); }
    GCParticleCollectionFloatInput GetClusterCooldown() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RepeatedTriggerChildGroup", "m_flClusterCooldown"); }
    void SetClusterCooldown(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RepeatedTriggerChildGroup", "m_flClusterCooldown", false, value); }
    bool GetLimitChildCount() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RepeatedTriggerChildGroup", "m_bLimitChildCount"); }
    void SetLimitChildCount(bool value) { SetSchemaValue(m_ptr, "C_OP_RepeatedTriggerChildGroup", "m_bLimitChildCount", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif