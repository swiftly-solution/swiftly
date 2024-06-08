class GLookAtOpFixedSettings_t;

#ifndef _gclookatopfixedsettings_t_h
#define _gclookatopfixedsettings_t_h

#include "../../../scripting.h"


#include "GCAnimAttachment.h"
#include "GCAnimInputDamping.h"
#include "GLookAtBone_t.h"

class GLookAtOpFixedSettings_t
{
private:
    void *m_ptr;

public:
    GLookAtOpFixedSettings_t() {}
    GLookAtOpFixedSettings_t(void *ptr) : m_ptr(ptr) {}

    GCAnimAttachment GetAttachment() const { return GetSchemaValue<GCAnimAttachment>(m_ptr, "LookAtOpFixedSettings_t", "m_attachment"); }
    void SetAttachment(GCAnimAttachment value) { SetSchemaValue(m_ptr, "LookAtOpFixedSettings_t", "m_attachment", true, value); }
    GCAnimInputDamping GetDamping() const { return GetSchemaValue<GCAnimInputDamping>(m_ptr, "LookAtOpFixedSettings_t", "m_damping"); }
    void SetDamping(GCAnimInputDamping value) { SetSchemaValue(m_ptr, "LookAtOpFixedSettings_t", "m_damping", true, value); }
    std::vector<GLookAtBone_t> GetBones() const { CUtlVector<GLookAtBone_t>* vec = GetSchemaValue<CUtlVector<GLookAtBone_t>*>(m_ptr, "LookAtOpFixedSettings_t", "m_bones"); std::vector<GLookAtBone_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBones(std::vector<GLookAtBone_t> value) { SetSchemaValueCUtlVector<GLookAtBone_t>(m_ptr, "LookAtOpFixedSettings_t", "m_bones", true, value); }
    float GetYawLimit() const { return GetSchemaValue<float>(m_ptr, "LookAtOpFixedSettings_t", "m_flYawLimit"); }
    void SetYawLimit(float value) { SetSchemaValue(m_ptr, "LookAtOpFixedSettings_t", "m_flYawLimit", true, value); }
    float GetPitchLimit() const { return GetSchemaValue<float>(m_ptr, "LookAtOpFixedSettings_t", "m_flPitchLimit"); }
    void SetPitchLimit(float value) { SetSchemaValue(m_ptr, "LookAtOpFixedSettings_t", "m_flPitchLimit", true, value); }
    float GetHysteresisInnerAngle() const { return GetSchemaValue<float>(m_ptr, "LookAtOpFixedSettings_t", "m_flHysteresisInnerAngle"); }
    void SetHysteresisInnerAngle(float value) { SetSchemaValue(m_ptr, "LookAtOpFixedSettings_t", "m_flHysteresisInnerAngle", true, value); }
    float GetHysteresisOuterAngle() const { return GetSchemaValue<float>(m_ptr, "LookAtOpFixedSettings_t", "m_flHysteresisOuterAngle"); }
    void SetHysteresisOuterAngle(float value) { SetSchemaValue(m_ptr, "LookAtOpFixedSettings_t", "m_flHysteresisOuterAngle", true, value); }
    bool GetRotateYawForward() const { return GetSchemaValue<bool>(m_ptr, "LookAtOpFixedSettings_t", "m_bRotateYawForward"); }
    void SetRotateYawForward(bool value) { SetSchemaValue(m_ptr, "LookAtOpFixedSettings_t", "m_bRotateYawForward", true, value); }
    bool GetMaintainUpDirection() const { return GetSchemaValue<bool>(m_ptr, "LookAtOpFixedSettings_t", "m_bMaintainUpDirection"); }
    void SetMaintainUpDirection(bool value) { SetSchemaValue(m_ptr, "LookAtOpFixedSettings_t", "m_bMaintainUpDirection", true, value); }
    bool GetTargetIsPosition() const { return GetSchemaValue<bool>(m_ptr, "LookAtOpFixedSettings_t", "m_bTargetIsPosition"); }
    void SetTargetIsPosition(bool value) { SetSchemaValue(m_ptr, "LookAtOpFixedSettings_t", "m_bTargetIsPosition", true, value); }
    bool GetUseHysteresis() const { return GetSchemaValue<bool>(m_ptr, "LookAtOpFixedSettings_t", "m_bUseHysteresis"); }
    void SetUseHysteresis(bool value) { SetSchemaValue(m_ptr, "LookAtOpFixedSettings_t", "m_bUseHysteresis", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif