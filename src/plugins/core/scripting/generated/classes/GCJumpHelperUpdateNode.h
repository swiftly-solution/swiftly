class GCJumpHelperUpdateNode;

#ifndef _gccjumphelperupdatenode_h
#define _gccjumphelperupdatenode_h

#include "../../../scripting.h"

#include "../types/GJumpCorrectionMethod.h"
#include "GCAnimParamHandle.h"

class GCJumpHelperUpdateNode
{
private:
    void *m_ptr;

public:
    GCJumpHelperUpdateNode() {}
    GCJumpHelperUpdateNode(void *ptr) : m_ptr(ptr) {}

    GCAnimParamHandle GetTargetParam() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CJumpHelperUpdateNode", "m_hTargetParam"); }
    void SetTargetParam(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CJumpHelperUpdateNode", "m_hTargetParam", false, value); }
    Vector GetOriginalJumpMovement() const { return GetSchemaValue<Vector>(m_ptr, "CJumpHelperUpdateNode", "m_flOriginalJumpMovement"); }
    void SetOriginalJumpMovement(Vector value) { SetSchemaValue(m_ptr, "CJumpHelperUpdateNode", "m_flOriginalJumpMovement", false, value); }
    float GetOriginalJumpDuration() const { return GetSchemaValue<float>(m_ptr, "CJumpHelperUpdateNode", "m_flOriginalJumpDuration"); }
    void SetOriginalJumpDuration(float value) { SetSchemaValue(m_ptr, "CJumpHelperUpdateNode", "m_flOriginalJumpDuration", false, value); }
    float GetJumpStartCycle() const { return GetSchemaValue<float>(m_ptr, "CJumpHelperUpdateNode", "m_flJumpStartCycle"); }
    void SetJumpStartCycle(float value) { SetSchemaValue(m_ptr, "CJumpHelperUpdateNode", "m_flJumpStartCycle", false, value); }
    float GetJumpEndCycle() const { return GetSchemaValue<float>(m_ptr, "CJumpHelperUpdateNode", "m_flJumpEndCycle"); }
    void SetJumpEndCycle(float value) { SetSchemaValue(m_ptr, "CJumpHelperUpdateNode", "m_flJumpEndCycle", false, value); }
    JumpCorrectionMethod GetCorrectionMethod() const { return GetSchemaValue<JumpCorrectionMethod>(m_ptr, "CJumpHelperUpdateNode", "m_eCorrectionMethod"); }
    void SetCorrectionMethod(JumpCorrectionMethod value) { SetSchemaValue(m_ptr, "CJumpHelperUpdateNode", "m_eCorrectionMethod", false, value); }
    std::vector<bool> GetTranslationAxis() const { bool* outValue = GetSchemaValue<bool*>(m_ptr, "CJumpHelperUpdateNode", "m_bTranslationAxis"); std::vector<bool> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetTranslationAxis(std::vector<bool> value) { bool* outValue = GetSchemaValue<bool*>(m_ptr, "CJumpHelperUpdateNode", "m_bTranslationAxis"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CJumpHelperUpdateNode", "m_bTranslationAxis", false, outValue); }
    bool GetScaleSpeed() const { return GetSchemaValue<bool>(m_ptr, "CJumpHelperUpdateNode", "m_bScaleSpeed"); }
    void SetScaleSpeed(bool value) { SetSchemaValue(m_ptr, "CJumpHelperUpdateNode", "m_bScaleSpeed", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif