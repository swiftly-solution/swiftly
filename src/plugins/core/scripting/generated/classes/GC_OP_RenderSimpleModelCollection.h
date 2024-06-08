class GC_OP_RenderSimpleModelCollection;

#ifndef _gcc_op_rendersimplemodelcollection_h
#define _gcc_op_rendersimplemodelcollection_h

#include "../../../scripting.h"


#include "GCParticleModelInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_RenderSimpleModelCollection
{
private:
    void *m_ptr;

public:
    GC_OP_RenderSimpleModelCollection() {}
    GC_OP_RenderSimpleModelCollection(void *ptr) : m_ptr(ptr) {}

    bool GetCenterOffset() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderSimpleModelCollection", "m_bCenterOffset"); }
    void SetCenterOffset(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderSimpleModelCollection", "m_bCenterOffset", false, value); }
    GCParticleModelInput GetModelInput() const { return GetSchemaValue<GCParticleModelInput>(m_ptr, "C_OP_RenderSimpleModelCollection", "m_modelInput"); }
    void SetModelInput(GCParticleModelInput value) { SetSchemaValue(m_ptr, "C_OP_RenderSimpleModelCollection", "m_modelInput", false, value); }
    int32_t GetLOD() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderSimpleModelCollection", "m_nLOD"); }
    void SetLOD(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderSimpleModelCollection", "m_nLOD", false, value); }
    bool GetDisableShadows() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderSimpleModelCollection", "m_bDisableShadows"); }
    void SetDisableShadows(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderSimpleModelCollection", "m_bDisableShadows", false, value); }
    bool GetDisableMotionBlur() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderSimpleModelCollection", "m_bDisableMotionBlur"); }
    void SetDisableMotionBlur(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderSimpleModelCollection", "m_bDisableMotionBlur", false, value); }
    bool GetAcceptsDecals() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderSimpleModelCollection", "m_bAcceptsDecals"); }
    void SetAcceptsDecals(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderSimpleModelCollection", "m_bAcceptsDecals", false, value); }
    GParticleAttributeIndex_t GetAngularVelocityField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderSimpleModelCollection", "m_nAngularVelocityField"); }
    void SetAngularVelocityField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderSimpleModelCollection", "m_nAngularVelocityField", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif