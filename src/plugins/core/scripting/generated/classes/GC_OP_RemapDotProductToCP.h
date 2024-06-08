class GC_OP_RemapDotProductToCP;

#ifndef _gcc_op_remapdotproducttocp_h
#define _gcc_op_remapdotproducttocp_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_RemapDotProductToCP
{
private:
    void *m_ptr;

public:
    GC_OP_RemapDotProductToCP() {}
    GC_OP_RemapDotProductToCP(void *ptr) : m_ptr(ptr) {}

    int32_t GetInputCP1() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapDotProductToCP", "m_nInputCP1"); }
    void SetInputCP1(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapDotProductToCP", "m_nInputCP1", false, value); }
    int32_t GetInputCP2() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapDotProductToCP", "m_nInputCP2"); }
    void SetInputCP2(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapDotProductToCP", "m_nInputCP2", false, value); }
    int32_t GetOutputCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapDotProductToCP", "m_nOutputCP"); }
    void SetOutputCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapDotProductToCP", "m_nOutputCP", false, value); }
    int32_t GetOutVectorField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapDotProductToCP", "m_nOutVectorField"); }
    void SetOutVectorField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapDotProductToCP", "m_nOutVectorField", false, value); }
    GCParticleCollectionFloatInput GetInputMin() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RemapDotProductToCP", "m_flInputMin"); }
    void SetInputMin(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RemapDotProductToCP", "m_flInputMin", false, value); }
    GCParticleCollectionFloatInput GetInputMax() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RemapDotProductToCP", "m_flInputMax"); }
    void SetInputMax(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RemapDotProductToCP", "m_flInputMax", false, value); }
    GCParticleCollectionFloatInput GetOutputMin() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RemapDotProductToCP", "m_flOutputMin"); }
    void SetOutputMin(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RemapDotProductToCP", "m_flOutputMin", false, value); }
    GCParticleCollectionFloatInput GetOutputMax() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RemapDotProductToCP", "m_flOutputMax"); }
    void SetOutputMax(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RemapDotProductToCP", "m_flOutputMax", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif