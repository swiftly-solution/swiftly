class GCFootAdjustmentUpdateNode;

#ifndef _gccfootadjustmentupdatenode_h
#define _gccfootadjustmentupdatenode_h

#include "../../../scripting.h"


#include "GCPoseHandle.h"
#include "GCAnimParamHandle.h"

class GCFootAdjustmentUpdateNode
{
private:
    void *m_ptr;

public:
    GCFootAdjustmentUpdateNode() {}
    GCFootAdjustmentUpdateNode(void *ptr) : m_ptr(ptr) {}

    GCPoseHandle GetBasePoseCacheHandle() const { return GetSchemaValue<GCPoseHandle>(m_ptr, "CFootAdjustmentUpdateNode", "m_hBasePoseCacheHandle"); }
    void SetBasePoseCacheHandle(GCPoseHandle value) { SetSchemaValue(m_ptr, "CFootAdjustmentUpdateNode", "m_hBasePoseCacheHandle", false, value); }
    GCAnimParamHandle GetFacingTarget() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CFootAdjustmentUpdateNode", "m_facingTarget"); }
    void SetFacingTarget(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CFootAdjustmentUpdateNode", "m_facingTarget", false, value); }
    float GetTurnTimeMin() const { return GetSchemaValue<float>(m_ptr, "CFootAdjustmentUpdateNode", "m_flTurnTimeMin"); }
    void SetTurnTimeMin(float value) { SetSchemaValue(m_ptr, "CFootAdjustmentUpdateNode", "m_flTurnTimeMin", false, value); }
    float GetTurnTimeMax() const { return GetSchemaValue<float>(m_ptr, "CFootAdjustmentUpdateNode", "m_flTurnTimeMax"); }
    void SetTurnTimeMax(float value) { SetSchemaValue(m_ptr, "CFootAdjustmentUpdateNode", "m_flTurnTimeMax", false, value); }
    float GetStepHeightMax() const { return GetSchemaValue<float>(m_ptr, "CFootAdjustmentUpdateNode", "m_flStepHeightMax"); }
    void SetStepHeightMax(float value) { SetSchemaValue(m_ptr, "CFootAdjustmentUpdateNode", "m_flStepHeightMax", false, value); }
    float GetStepHeightMaxAngle() const { return GetSchemaValue<float>(m_ptr, "CFootAdjustmentUpdateNode", "m_flStepHeightMaxAngle"); }
    void SetStepHeightMaxAngle(float value) { SetSchemaValue(m_ptr, "CFootAdjustmentUpdateNode", "m_flStepHeightMaxAngle", false, value); }
    bool GetResetChild() const { return GetSchemaValue<bool>(m_ptr, "CFootAdjustmentUpdateNode", "m_bResetChild"); }
    void SetResetChild(bool value) { SetSchemaValue(m_ptr, "CFootAdjustmentUpdateNode", "m_bResetChild", false, value); }
    bool GetAnimationDriven() const { return GetSchemaValue<bool>(m_ptr, "CFootAdjustmentUpdateNode", "m_bAnimationDriven"); }
    void SetAnimationDriven(bool value) { SetSchemaValue(m_ptr, "CFootAdjustmentUpdateNode", "m_bAnimationDriven", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif