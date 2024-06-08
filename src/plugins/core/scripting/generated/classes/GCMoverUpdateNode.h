class GCMoverUpdateNode;

#ifndef _gccmoverupdatenode_h
#define _gccmoverupdatenode_h

#include "../../../scripting.h"

#include "../types/GAnimValueSource.h"
#include "GCAnimInputDamping.h"
#include "GCAnimParamHandle.h"

class GCMoverUpdateNode
{
private:
    void *m_ptr;

public:
    GCMoverUpdateNode() {}
    GCMoverUpdateNode(void *ptr) : m_ptr(ptr) {}

    GCAnimInputDamping GetDamping() const { return GetSchemaValue<GCAnimInputDamping>(m_ptr, "CMoverUpdateNode", "m_damping"); }
    void SetDamping(GCAnimInputDamping value) { SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_damping", false, value); }
    AnimValueSource GetFacingTarget() const { return GetSchemaValue<AnimValueSource>(m_ptr, "CMoverUpdateNode", "m_facingTarget"); }
    void SetFacingTarget(AnimValueSource value) { SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_facingTarget", false, value); }
    GCAnimParamHandle GetMoveVecParam() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CMoverUpdateNode", "m_hMoveVecParam"); }
    void SetMoveVecParam(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_hMoveVecParam", false, value); }
    GCAnimParamHandle GetMoveHeadingParam() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CMoverUpdateNode", "m_hMoveHeadingParam"); }
    void SetMoveHeadingParam(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_hMoveHeadingParam", false, value); }
    GCAnimParamHandle GetTurnToFaceParam() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CMoverUpdateNode", "m_hTurnToFaceParam"); }
    void SetTurnToFaceParam(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_hTurnToFaceParam", false, value); }
    float GetTurnToFaceOffset() const { return GetSchemaValue<float>(m_ptr, "CMoverUpdateNode", "m_flTurnToFaceOffset"); }
    void SetTurnToFaceOffset(float value) { SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_flTurnToFaceOffset", false, value); }
    float GetTurnToFaceLimit() const { return GetSchemaValue<float>(m_ptr, "CMoverUpdateNode", "m_flTurnToFaceLimit"); }
    void SetTurnToFaceLimit(float value) { SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_flTurnToFaceLimit", false, value); }
    bool GetAdditive() const { return GetSchemaValue<bool>(m_ptr, "CMoverUpdateNode", "m_bAdditive"); }
    void SetAdditive(bool value) { SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_bAdditive", false, value); }
    bool GetApplyMovement() const { return GetSchemaValue<bool>(m_ptr, "CMoverUpdateNode", "m_bApplyMovement"); }
    void SetApplyMovement(bool value) { SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_bApplyMovement", false, value); }
    bool GetOrientMovement() const { return GetSchemaValue<bool>(m_ptr, "CMoverUpdateNode", "m_bOrientMovement"); }
    void SetOrientMovement(bool value) { SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_bOrientMovement", false, value); }
    bool GetApplyRotation() const { return GetSchemaValue<bool>(m_ptr, "CMoverUpdateNode", "m_bApplyRotation"); }
    void SetApplyRotation(bool value) { SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_bApplyRotation", false, value); }
    bool GetLimitOnly() const { return GetSchemaValue<bool>(m_ptr, "CMoverUpdateNode", "m_bLimitOnly"); }
    void SetLimitOnly(bool value) { SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_bLimitOnly", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif