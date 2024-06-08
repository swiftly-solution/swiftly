class GCFollowPathUpdateNode;

#ifndef _gccfollowpathupdatenode_h
#define _gccfollowpathupdatenode_h

#include "../../../scripting.h"

#include "../types/GAnimValueSource.h"
#include "GCAnimInputDamping.h"
#include "GCAnimParamHandle.h"

class GCFollowPathUpdateNode
{
private:
    void *m_ptr;

public:
    GCFollowPathUpdateNode() {}
    GCFollowPathUpdateNode(void *ptr) : m_ptr(ptr) {}

    float GetBlendOutTime() const { return GetSchemaValue<float>(m_ptr, "CFollowPathUpdateNode", "m_flBlendOutTime"); }
    void SetBlendOutTime(float value) { SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_flBlendOutTime", false, value); }
    bool GetBlockNonPathMovement() const { return GetSchemaValue<bool>(m_ptr, "CFollowPathUpdateNode", "m_bBlockNonPathMovement"); }
    void SetBlockNonPathMovement(bool value) { SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_bBlockNonPathMovement", false, value); }
    bool GetStopFeetAtGoal() const { return GetSchemaValue<bool>(m_ptr, "CFollowPathUpdateNode", "m_bStopFeetAtGoal"); }
    void SetStopFeetAtGoal(bool value) { SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_bStopFeetAtGoal", false, value); }
    bool GetScaleSpeed() const { return GetSchemaValue<bool>(m_ptr, "CFollowPathUpdateNode", "m_bScaleSpeed"); }
    void SetScaleSpeed(bool value) { SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_bScaleSpeed", false, value); }
    float GetScale() const { return GetSchemaValue<float>(m_ptr, "CFollowPathUpdateNode", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_flScale", false, value); }
    float GetMinAngle() const { return GetSchemaValue<float>(m_ptr, "CFollowPathUpdateNode", "m_flMinAngle"); }
    void SetMinAngle(float value) { SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_flMinAngle", false, value); }
    float GetMaxAngle() const { return GetSchemaValue<float>(m_ptr, "CFollowPathUpdateNode", "m_flMaxAngle"); }
    void SetMaxAngle(float value) { SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_flMaxAngle", false, value); }
    float GetSpeedScaleBlending() const { return GetSchemaValue<float>(m_ptr, "CFollowPathUpdateNode", "m_flSpeedScaleBlending"); }
    void SetSpeedScaleBlending(float value) { SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_flSpeedScaleBlending", false, value); }
    GCAnimInputDamping GetTurnDamping() const { return GetSchemaValue<GCAnimInputDamping>(m_ptr, "CFollowPathUpdateNode", "m_turnDamping"); }
    void SetTurnDamping(GCAnimInputDamping value) { SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_turnDamping", false, value); }
    AnimValueSource GetFacingTarget() const { return GetSchemaValue<AnimValueSource>(m_ptr, "CFollowPathUpdateNode", "m_facingTarget"); }
    void SetFacingTarget(AnimValueSource value) { SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_facingTarget", false, value); }
    GCAnimParamHandle GetParam() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CFollowPathUpdateNode", "m_hParam"); }
    void SetParam(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_hParam", false, value); }
    float GetTurnToFaceOffset() const { return GetSchemaValue<float>(m_ptr, "CFollowPathUpdateNode", "m_flTurnToFaceOffset"); }
    void SetTurnToFaceOffset(float value) { SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_flTurnToFaceOffset", false, value); }
    bool GetTurnToFace() const { return GetSchemaValue<bool>(m_ptr, "CFollowPathUpdateNode", "m_bTurnToFace"); }
    void SetTurnToFace(bool value) { SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_bTurnToFace", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif