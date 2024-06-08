class GC_OP_Cull;

#ifndef _gcc_op_cull_h
#define _gcc_op_cull_h

#include "../../../scripting.h"




class GC_OP_Cull
{
private:
    void *m_ptr;

public:
    GC_OP_Cull() {}
    GC_OP_Cull(void *ptr) : m_ptr(ptr) {}

    float GetCullPerc() const { return GetSchemaValue<float>(m_ptr, "C_OP_Cull", "m_flCullPerc"); }
    void SetCullPerc(float value) { SetSchemaValue(m_ptr, "C_OP_Cull", "m_flCullPerc", false, value); }
    float GetCullStart() const { return GetSchemaValue<float>(m_ptr, "C_OP_Cull", "m_flCullStart"); }
    void SetCullStart(float value) { SetSchemaValue(m_ptr, "C_OP_Cull", "m_flCullStart", false, value); }
    float GetCullEnd() const { return GetSchemaValue<float>(m_ptr, "C_OP_Cull", "m_flCullEnd"); }
    void SetCullEnd(float value) { SetSchemaValue(m_ptr, "C_OP_Cull", "m_flCullEnd", false, value); }
    float GetCullExp() const { return GetSchemaValue<float>(m_ptr, "C_OP_Cull", "m_flCullExp"); }
    void SetCullExp(float value) { SetSchemaValue(m_ptr, "C_OP_Cull", "m_flCullExp", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif