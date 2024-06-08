class GC_OP_SetVariable;

#ifndef _gcc_op_setvariable_h
#define _gcc_op_setvariable_h

#include "../../../scripting.h"


#include "GCParticleTransformInput.h"
#include "GCParticleCollectionFloatInput.h"

class GC_OP_SetVariable
{
private:
    void *m_ptr;

public:
    GC_OP_SetVariable() {}
    GC_OP_SetVariable(void *ptr) : m_ptr(ptr) {}

    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_SetVariable", "m_transformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_SetVariable", "m_transformInput", false, value); }
    Vector GetPositionOffset() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_SetVariable", "m_positionOffset"); }
    void SetPositionOffset(Vector value) { SetSchemaValue(m_ptr, "C_OP_SetVariable", "m_positionOffset", false, value); }
    QAngle GetRotationOffset() const { return GetSchemaValue<QAngle>(m_ptr, "C_OP_SetVariable", "m_rotationOffset"); }
    void SetRotationOffset(QAngle value) { SetSchemaValue(m_ptr, "C_OP_SetVariable", "m_rotationOffset", false, value); }
    GCParticleCollectionFloatInput GetFloatInput() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SetVariable", "m_floatInput"); }
    void SetFloatInput(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetVariable", "m_floatInput", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif