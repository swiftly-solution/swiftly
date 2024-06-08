class GC_OP_Diffusion;

#ifndef _gcc_op_diffusion_h
#define _gcc_op_diffusion_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_Diffusion
{
private:
    void *m_ptr;

public:
    GC_OP_Diffusion() {}
    GC_OP_Diffusion(void *ptr) : m_ptr(ptr) {}

    float GetRadiusScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_Diffusion", "m_flRadiusScale"); }
    void SetRadiusScale(float value) { SetSchemaValue(m_ptr, "C_OP_Diffusion", "m_flRadiusScale", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_Diffusion", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_Diffusion", "m_nFieldOutput", false, value); }
    int32_t GetVoxelGridResolution() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_Diffusion", "m_nVoxelGridResolution"); }
    void SetVoxelGridResolution(int32_t value) { SetSchemaValue(m_ptr, "C_OP_Diffusion", "m_nVoxelGridResolution", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif