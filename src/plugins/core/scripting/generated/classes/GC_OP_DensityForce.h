class GC_OP_DensityForce;

#ifndef _gcc_op_densityforce_h
#define _gcc_op_densityforce_h

#include "../../../scripting.h"




class GC_OP_DensityForce
{
private:
    void *m_ptr;

public:
    GC_OP_DensityForce() {}
    GC_OP_DensityForce(void *ptr) : m_ptr(ptr) {}

    float GetRadiusScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_DensityForce", "m_flRadiusScale"); }
    void SetRadiusScale(float value) { SetSchemaValue(m_ptr, "C_OP_DensityForce", "m_flRadiusScale", false, value); }
    float GetForceScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_DensityForce", "m_flForceScale"); }
    void SetForceScale(float value) { SetSchemaValue(m_ptr, "C_OP_DensityForce", "m_flForceScale", false, value); }
    float GetTargetDensity() const { return GetSchemaValue<float>(m_ptr, "C_OP_DensityForce", "m_flTargetDensity"); }
    void SetTargetDensity(float value) { SetSchemaValue(m_ptr, "C_OP_DensityForce", "m_flTargetDensity", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif