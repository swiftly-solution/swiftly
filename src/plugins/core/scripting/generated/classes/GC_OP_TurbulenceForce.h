class GC_OP_TurbulenceForce;

#ifndef _gcc_op_turbulenceforce_h
#define _gcc_op_turbulenceforce_h

#include "../../../scripting.h"




class GC_OP_TurbulenceForce
{
private:
    void *m_ptr;

public:
    GC_OP_TurbulenceForce() {}
    GC_OP_TurbulenceForce(void *ptr) : m_ptr(ptr) {}

    float GetNoiseCoordScale0() const { return GetSchemaValue<float>(m_ptr, "C_OP_TurbulenceForce", "m_flNoiseCoordScale0"); }
    void SetNoiseCoordScale0(float value) { SetSchemaValue(m_ptr, "C_OP_TurbulenceForce", "m_flNoiseCoordScale0", false, value); }
    float GetNoiseCoordScale1() const { return GetSchemaValue<float>(m_ptr, "C_OP_TurbulenceForce", "m_flNoiseCoordScale1"); }
    void SetNoiseCoordScale1(float value) { SetSchemaValue(m_ptr, "C_OP_TurbulenceForce", "m_flNoiseCoordScale1", false, value); }
    float GetNoiseCoordScale2() const { return GetSchemaValue<float>(m_ptr, "C_OP_TurbulenceForce", "m_flNoiseCoordScale2"); }
    void SetNoiseCoordScale2(float value) { SetSchemaValue(m_ptr, "C_OP_TurbulenceForce", "m_flNoiseCoordScale2", false, value); }
    float GetNoiseCoordScale3() const { return GetSchemaValue<float>(m_ptr, "C_OP_TurbulenceForce", "m_flNoiseCoordScale3"); }
    void SetNoiseCoordScale3(float value) { SetSchemaValue(m_ptr, "C_OP_TurbulenceForce", "m_flNoiseCoordScale3", false, value); }
    Vector GetNoiseAmount0() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_TurbulenceForce", "m_vecNoiseAmount0"); }
    void SetNoiseAmount0(Vector value) { SetSchemaValue(m_ptr, "C_OP_TurbulenceForce", "m_vecNoiseAmount0", false, value); }
    Vector GetNoiseAmount1() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_TurbulenceForce", "m_vecNoiseAmount1"); }
    void SetNoiseAmount1(Vector value) { SetSchemaValue(m_ptr, "C_OP_TurbulenceForce", "m_vecNoiseAmount1", false, value); }
    Vector GetNoiseAmount2() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_TurbulenceForce", "m_vecNoiseAmount2"); }
    void SetNoiseAmount2(Vector value) { SetSchemaValue(m_ptr, "C_OP_TurbulenceForce", "m_vecNoiseAmount2", false, value); }
    Vector GetNoiseAmount3() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_TurbulenceForce", "m_vecNoiseAmount3"); }
    void SetNoiseAmount3(Vector value) { SetSchemaValue(m_ptr, "C_OP_TurbulenceForce", "m_vecNoiseAmount3", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif