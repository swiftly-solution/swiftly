class GIKTargetSettings_t;

#ifndef _gciktargetsettings_t_h
#define _gciktargetsettings_t_h

#include "../../../scripting.h"

#include "../types/GIKTargetSource.h"
#include "../types/GIKTargetCoordinateSystem.h"
#include "GIKBoneNameAndIndex_t.h"
#include "GAnimParamID.h"

class GIKTargetSettings_t
{
private:
    void *m_ptr;

public:
    GIKTargetSettings_t() {}
    GIKTargetSettings_t(void *ptr) : m_ptr(ptr) {}

    IKTargetSource GetTargetSource() const { return GetSchemaValue<IKTargetSource>(m_ptr, "IKTargetSettings_t", "m_TargetSource"); }
    void SetTargetSource(IKTargetSource value) { SetSchemaValue(m_ptr, "IKTargetSettings_t", "m_TargetSource", true, value); }
    GIKBoneNameAndIndex_t GetBone() const { return GetSchemaValue<GIKBoneNameAndIndex_t>(m_ptr, "IKTargetSettings_t", "m_Bone"); }
    void SetBone(GIKBoneNameAndIndex_t value) { SetSchemaValue(m_ptr, "IKTargetSettings_t", "m_Bone", true, value); }
    GAnimParamID GetAnimgraphParameterNamePosition() const { return GetSchemaValue<GAnimParamID>(m_ptr, "IKTargetSettings_t", "m_AnimgraphParameterNamePosition"); }
    void SetAnimgraphParameterNamePosition(GAnimParamID value) { SetSchemaValue(m_ptr, "IKTargetSettings_t", "m_AnimgraphParameterNamePosition", true, value); }
    GAnimParamID GetAnimgraphParameterNameOrientation() const { return GetSchemaValue<GAnimParamID>(m_ptr, "IKTargetSettings_t", "m_AnimgraphParameterNameOrientation"); }
    void SetAnimgraphParameterNameOrientation(GAnimParamID value) { SetSchemaValue(m_ptr, "IKTargetSettings_t", "m_AnimgraphParameterNameOrientation", true, value); }
    IKTargetCoordinateSystem GetTargetCoordSystem() const { return GetSchemaValue<IKTargetCoordinateSystem>(m_ptr, "IKTargetSettings_t", "m_TargetCoordSystem"); }
    void SetTargetCoordSystem(IKTargetCoordinateSystem value) { SetSchemaValue(m_ptr, "IKTargetSettings_t", "m_TargetCoordSystem", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif