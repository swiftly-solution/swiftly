class GC_OP_SetGravityToCP;

#ifndef _gcc_op_setgravitytocp_h
#define _gcc_op_setgravitytocp_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_SetGravityToCP
{
private:
    void *m_ptr;

public:
    GC_OP_SetGravityToCP() {}
    GC_OP_SetGravityToCP(void *ptr) : m_ptr(ptr) {}

    int32_t GetCPInput() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetGravityToCP", "m_nCPInput"); }
    void SetCPInput(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetGravityToCP", "m_nCPInput", false, value); }
    int32_t GetCPOutput() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetGravityToCP", "m_nCPOutput"); }
    void SetCPOutput(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetGravityToCP", "m_nCPOutput", false, value); }
    GCParticleCollectionFloatInput GetScale() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SetGravityToCP", "m_flScale"); }
    void SetScale(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetGravityToCP", "m_flScale", false, value); }
    bool GetSetOrientation() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetGravityToCP", "m_bSetOrientation"); }
    void SetSetOrientation(bool value) { SetSchemaValue(m_ptr, "C_OP_SetGravityToCP", "m_bSetOrientation", false, value); }
    bool GetSetZDown() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetGravityToCP", "m_bSetZDown"); }
    void SetSetZDown(bool value) { SetSchemaValue(m_ptr, "C_OP_SetGravityToCP", "m_bSetZDown", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif