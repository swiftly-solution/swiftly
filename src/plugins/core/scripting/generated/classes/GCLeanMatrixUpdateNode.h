class GCLeanMatrixUpdateNode;

#ifndef _gccleanmatrixupdatenode_h
#define _gccleanmatrixupdatenode_h

#include "../../../scripting.h"

#include "../types/GAnimVectorSource.h"
#include "GCPoseHandle.h"
#include "GCAnimInputDamping.h"
#include "GCAnimParamHandle.h"

class GCLeanMatrixUpdateNode
{
private:
    void *m_ptr;

public:
    GCLeanMatrixUpdateNode() {}
    GCLeanMatrixUpdateNode(void *ptr) : m_ptr(ptr) {}

    std::vector<GCPoseHandle> GetPoses() const { GCPoseHandle* outValue = GetSchemaValue<GCPoseHandle*>(m_ptr, "CLeanMatrixUpdateNode", "m_poses"); std::vector<GCPoseHandle> ret; for(int i = 0; i < 9; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetPoses(std::vector<GCPoseHandle> value) { GCPoseHandle* outValue = GetSchemaValue<GCPoseHandle*>(m_ptr, "CLeanMatrixUpdateNode", "m_poses"); for(int i = 0; i < 9; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CLeanMatrixUpdateNode", "m_poses", false, outValue); }
    GCAnimInputDamping GetDamping() const { return GetSchemaValue<GCAnimInputDamping>(m_ptr, "CLeanMatrixUpdateNode", "m_damping"); }
    void SetDamping(GCAnimInputDamping value) { SetSchemaValue(m_ptr, "CLeanMatrixUpdateNode", "m_damping", false, value); }
    AnimVectorSource GetBlendSource() const { return GetSchemaValue<AnimVectorSource>(m_ptr, "CLeanMatrixUpdateNode", "m_blendSource"); }
    void SetBlendSource(AnimVectorSource value) { SetSchemaValue(m_ptr, "CLeanMatrixUpdateNode", "m_blendSource", false, value); }
    GCAnimParamHandle GetParamIndex() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CLeanMatrixUpdateNode", "m_paramIndex"); }
    void SetParamIndex(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CLeanMatrixUpdateNode", "m_paramIndex", false, value); }
    Vector GetVerticalAxis() const { return GetSchemaValue<Vector>(m_ptr, "CLeanMatrixUpdateNode", "m_verticalAxis"); }
    void SetVerticalAxis(Vector value) { SetSchemaValue(m_ptr, "CLeanMatrixUpdateNode", "m_verticalAxis", false, value); }
    Vector GetHorizontalAxis() const { return GetSchemaValue<Vector>(m_ptr, "CLeanMatrixUpdateNode", "m_horizontalAxis"); }
    void SetHorizontalAxis(Vector value) { SetSchemaValue(m_ptr, "CLeanMatrixUpdateNode", "m_horizontalAxis", false, value); }
    float GetMaxValue() const { return GetSchemaValue<float>(m_ptr, "CLeanMatrixUpdateNode", "m_flMaxValue"); }
    void SetMaxValue(float value) { SetSchemaValue(m_ptr, "CLeanMatrixUpdateNode", "m_flMaxValue", false, value); }
    int32_t GetSequenceMaxFrame() const { return GetSchemaValue<int32_t>(m_ptr, "CLeanMatrixUpdateNode", "m_nSequenceMaxFrame"); }
    void SetSequenceMaxFrame(int32_t value) { SetSchemaValue(m_ptr, "CLeanMatrixUpdateNode", "m_nSequenceMaxFrame", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif