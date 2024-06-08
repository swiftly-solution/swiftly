class GC_OP_SDFLighting;

#ifndef _gcc_op_sdflighting_h
#define _gcc_op_sdflighting_h

#include "../../../scripting.h"




class GC_OP_SDFLighting
{
private:
    void *m_ptr;

public:
    GC_OP_SDFLighting() {}
    GC_OP_SDFLighting(void *ptr) : m_ptr(ptr) {}

    Vector GetLightingDir() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_SDFLighting", "m_vLightingDir"); }
    void SetLightingDir(Vector value) { SetSchemaValue(m_ptr, "C_OP_SDFLighting", "m_vLightingDir", false, value); }
    Vector GetTint_0() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_SDFLighting", "m_vTint_0"); }
    void SetTint_0(Vector value) { SetSchemaValue(m_ptr, "C_OP_SDFLighting", "m_vTint_0", false, value); }
    Vector GetTint_1() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_SDFLighting", "m_vTint_1"); }
    void SetTint_1(Vector value) { SetSchemaValue(m_ptr, "C_OP_SDFLighting", "m_vTint_1", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif