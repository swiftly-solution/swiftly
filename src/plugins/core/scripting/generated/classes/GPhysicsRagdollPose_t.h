class GPhysicsRagdollPose_t;

#ifndef _gcphysicsragdollpose_t_h
#define _gcphysicsragdollpose_t_h

#include "../../../scripting.h"


#include "GCNetworkVarChainer.h"
#include "GCBaseEntity.h"

class GPhysicsRagdollPose_t
{
private:
    void *m_ptr;

public:
    GPhysicsRagdollPose_t() {}
    GPhysicsRagdollPose_t(void *ptr) : m_ptr(ptr) {}

    GCNetworkVarChainer Get__pChainEntity() const { return GetSchemaValue<GCNetworkVarChainer>(m_ptr, "PhysicsRagdollPose_t", "__m_pChainEntity"); }
    void Set__pChainEntity(GCNetworkVarChainer value) { SetSchemaValue(m_ptr, "PhysicsRagdollPose_t", "__m_pChainEntity", true, value); }
    GCBaseEntity* GetOwner() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "PhysicsRagdollPose_t", "m_hOwner"); }
    void SetOwner(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Owner' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif