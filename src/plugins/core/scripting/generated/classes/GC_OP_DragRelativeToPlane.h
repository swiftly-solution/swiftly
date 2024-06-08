class GC_OP_DragRelativeToPlane;

#ifndef _gcc_op_dragrelativetoplane_h
#define _gcc_op_dragrelativetoplane_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_DragRelativeToPlane
{
private:
    void *m_ptr;

public:
    GC_OP_DragRelativeToPlane() {}
    GC_OP_DragRelativeToPlane(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetDragAtPlane() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_DragRelativeToPlane", "m_flDragAtPlane"); }
    void SetDragAtPlane(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_DragRelativeToPlane", "m_flDragAtPlane", false, value); }
    GCParticleCollectionFloatInput GetFalloff() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_DragRelativeToPlane", "m_flFalloff"); }
    void SetFalloff(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_DragRelativeToPlane", "m_flFalloff", false, value); }
    bool GetDirectional() const { return GetSchemaValue<bool>(m_ptr, "C_OP_DragRelativeToPlane", "m_bDirectional"); }
    void SetDirectional(bool value) { SetSchemaValue(m_ptr, "C_OP_DragRelativeToPlane", "m_bDirectional", false, value); }
    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_DragRelativeToPlane", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_DragRelativeToPlane", "m_nControlPointNumber", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif