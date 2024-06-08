class GC_OP_RemapDensityToVector;

#ifndef _gcc_op_remapdensitytovector_h
#define _gcc_op_remapdensitytovector_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapDensityToVector
{
private:
    void *m_ptr;

public:
    GC_OP_RemapDensityToVector() {}
    GC_OP_RemapDensityToVector(void *ptr) : m_ptr(ptr) {}

    float GetRadiusScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapDensityToVector", "m_flRadiusScale"); }
    void SetRadiusScale(float value) { SetSchemaValue(m_ptr, "C_OP_RemapDensityToVector", "m_flRadiusScale", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapDensityToVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapDensityToVector", "m_nFieldOutput", false, value); }
    float GetDensityMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapDensityToVector", "m_flDensityMin"); }
    void SetDensityMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapDensityToVector", "m_flDensityMin", false, value); }
    float GetDensityMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapDensityToVector", "m_flDensityMax"); }
    void SetDensityMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapDensityToVector", "m_flDensityMax", false, value); }
    Vector GetOutputMin() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_RemapDensityToVector", "m_vecOutputMin"); }
    void SetOutputMin(Vector value) { SetSchemaValue(m_ptr, "C_OP_RemapDensityToVector", "m_vecOutputMin", false, value); }
    Vector GetOutputMax() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_RemapDensityToVector", "m_vecOutputMax"); }
    void SetOutputMax(Vector value) { SetSchemaValue(m_ptr, "C_OP_RemapDensityToVector", "m_vecOutputMax", false, value); }
    bool GetUseParentDensity() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapDensityToVector", "m_bUseParentDensity"); }
    void SetUseParentDensity(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapDensityToVector", "m_bUseParentDensity", false, value); }
    int32_t GetVoxelGridResolution() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapDensityToVector", "m_nVoxelGridResolution"); }
    void SetVoxelGridResolution(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapDensityToVector", "m_nVoxelGridResolution", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif