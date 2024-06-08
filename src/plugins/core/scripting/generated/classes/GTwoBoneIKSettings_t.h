class GTwoBoneIKSettings_t;

#ifndef _gctwoboneiksettings_t_h
#define _gctwoboneiksettings_t_h

#include "../../../scripting.h"

#include "../types/GIkEndEffectorType.h"
#include "../types/GIkTargetType.h"
#include "GCAnimAttachment.h"
#include "GCAnimParamHandle.h"

class GTwoBoneIKSettings_t
{
private:
    void *m_ptr;

public:
    GTwoBoneIKSettings_t() {}
    GTwoBoneIKSettings_t(void *ptr) : m_ptr(ptr) {}

    IkEndEffectorType GetEndEffectorType() const { return GetSchemaValue<IkEndEffectorType>(m_ptr, "TwoBoneIKSettings_t", "m_endEffectorType"); }
    void SetEndEffectorType(IkEndEffectorType value) { SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_endEffectorType", true, value); }
    GCAnimAttachment GetEndEffectorAttachment() const { return GetSchemaValue<GCAnimAttachment>(m_ptr, "TwoBoneIKSettings_t", "m_endEffectorAttachment"); }
    void SetEndEffectorAttachment(GCAnimAttachment value) { SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_endEffectorAttachment", true, value); }
    IkTargetType GetTargetType() const { return GetSchemaValue<IkTargetType>(m_ptr, "TwoBoneIKSettings_t", "m_targetType"); }
    void SetTargetType(IkTargetType value) { SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_targetType", true, value); }
    GCAnimAttachment GetTargetAttachment() const { return GetSchemaValue<GCAnimAttachment>(m_ptr, "TwoBoneIKSettings_t", "m_targetAttachment"); }
    void SetTargetAttachment(GCAnimAttachment value) { SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_targetAttachment", true, value); }
    int32_t GetTargetBoneIndex() const { return GetSchemaValue<int32_t>(m_ptr, "TwoBoneIKSettings_t", "m_targetBoneIndex"); }
    void SetTargetBoneIndex(int32_t value) { SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_targetBoneIndex", true, value); }
    GCAnimParamHandle GetPositionParam() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "TwoBoneIKSettings_t", "m_hPositionParam"); }
    void SetPositionParam(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_hPositionParam", true, value); }
    GCAnimParamHandle GetRotationParam() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "TwoBoneIKSettings_t", "m_hRotationParam"); }
    void SetRotationParam(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_hRotationParam", true, value); }
    bool GetAlwaysUseFallbackHinge() const { return GetSchemaValue<bool>(m_ptr, "TwoBoneIKSettings_t", "m_bAlwaysUseFallbackHinge"); }
    void SetAlwaysUseFallbackHinge(bool value) { SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_bAlwaysUseFallbackHinge", true, value); }
    Vector GetLsFallbackHingeAxis() const { return GetSchemaValue<Vector>(m_ptr, "TwoBoneIKSettings_t", "m_vLsFallbackHingeAxis"); }
    void SetLsFallbackHingeAxis(Vector value) { SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_vLsFallbackHingeAxis", true, value); }
    int32_t GetFixedBoneIndex() const { return GetSchemaValue<int32_t>(m_ptr, "TwoBoneIKSettings_t", "m_nFixedBoneIndex"); }
    void SetFixedBoneIndex(int32_t value) { SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_nFixedBoneIndex", true, value); }
    int32_t GetMiddleBoneIndex() const { return GetSchemaValue<int32_t>(m_ptr, "TwoBoneIKSettings_t", "m_nMiddleBoneIndex"); }
    void SetMiddleBoneIndex(int32_t value) { SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_nMiddleBoneIndex", true, value); }
    int32_t GetEndBoneIndex() const { return GetSchemaValue<int32_t>(m_ptr, "TwoBoneIKSettings_t", "m_nEndBoneIndex"); }
    void SetEndBoneIndex(int32_t value) { SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_nEndBoneIndex", true, value); }
    bool GetMatchTargetOrientation() const { return GetSchemaValue<bool>(m_ptr, "TwoBoneIKSettings_t", "m_bMatchTargetOrientation"); }
    void SetMatchTargetOrientation(bool value) { SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_bMatchTargetOrientation", true, value); }
    bool GetConstrainTwist() const { return GetSchemaValue<bool>(m_ptr, "TwoBoneIKSettings_t", "m_bConstrainTwist"); }
    void SetConstrainTwist(bool value) { SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_bConstrainTwist", true, value); }
    float GetMaxTwist() const { return GetSchemaValue<float>(m_ptr, "TwoBoneIKSettings_t", "m_flMaxTwist"); }
    void SetMaxTwist(float value) { SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_flMaxTwist", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif