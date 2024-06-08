class GCBaseAnimGraph;

#ifndef _gccbaseanimgraph_h
#define _gccbaseanimgraph_h

#include "../../../scripting.h"


#include "GIChoreoServices.h"
#include "GPhysicsRagdollPose_t.h"

class GCBaseAnimGraph
{
private:
    void *m_ptr;

public:
    GCBaseAnimGraph() {}
    GCBaseAnimGraph(void *ptr) : m_ptr(ptr) {}

    bool GetInitiallyPopulateInterpHistory() const { return GetSchemaValue<bool>(m_ptr, "CBaseAnimGraph", "m_bInitiallyPopulateInterpHistory"); }
    void SetInitiallyPopulateInterpHistory(bool value) { SetSchemaValue(m_ptr, "CBaseAnimGraph", "m_bInitiallyPopulateInterpHistory", false, value); }
    GIChoreoServices* GetChoreoServices() const { return GetSchemaValue<GIChoreoServices*>(m_ptr, "CBaseAnimGraph", "m_pChoreoServices"); }
    void SetChoreoServices(GIChoreoServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ChoreoServices' is not possible.\n"); }
    bool GetAnimGraphUpdateEnabled() const { return GetSchemaValue<bool>(m_ptr, "CBaseAnimGraph", "m_bAnimGraphUpdateEnabled"); }
    void SetAnimGraphUpdateEnabled(bool value) { SetSchemaValue(m_ptr, "CBaseAnimGraph", "m_bAnimGraphUpdateEnabled", false, value); }
    float GetMaxSlopeDistance() const { return GetSchemaValue<float>(m_ptr, "CBaseAnimGraph", "m_flMaxSlopeDistance"); }
    void SetMaxSlopeDistance(float value) { SetSchemaValue(m_ptr, "CBaseAnimGraph", "m_flMaxSlopeDistance", false, value); }
    Vector GetLastSlopeCheckPos() const { return GetSchemaValue<Vector>(m_ptr, "CBaseAnimGraph", "m_vLastSlopeCheckPos"); }
    void SetLastSlopeCheckPos(Vector value) { SetSchemaValue(m_ptr, "CBaseAnimGraph", "m_vLastSlopeCheckPos", false, value); }
    bool GetAnimationUpdateScheduled() const { return GetSchemaValue<bool>(m_ptr, "CBaseAnimGraph", "m_bAnimationUpdateScheduled"); }
    void SetAnimationUpdateScheduled(bool value) { SetSchemaValue(m_ptr, "CBaseAnimGraph", "m_bAnimationUpdateScheduled", false, value); }
    Vector GetForce() const { return GetSchemaValue<Vector>(m_ptr, "CBaseAnimGraph", "m_vecForce"); }
    void SetForce(Vector value) { SetSchemaValue(m_ptr, "CBaseAnimGraph", "m_vecForce", false, value); }
    int32_t GetForceBone() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseAnimGraph", "m_nForceBone"); }
    void SetForceBone(int32_t value) { SetSchemaValue(m_ptr, "CBaseAnimGraph", "m_nForceBone", false, value); }
    GPhysicsRagdollPose_t* GetRagdollPose() const { return GetSchemaValue<GPhysicsRagdollPose_t*>(m_ptr, "CBaseAnimGraph", "m_pRagdollPose"); }
    void SetRagdollPose(GPhysicsRagdollPose_t* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'RagdollPose' is not possible.\n"); }
    bool GetRagdollClientSide() const { return GetSchemaValue<bool>(m_ptr, "CBaseAnimGraph", "m_bRagdollClientSide"); }
    void SetRagdollClientSide(bool value) { SetSchemaValue(m_ptr, "CBaseAnimGraph", "m_bRagdollClientSide", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif