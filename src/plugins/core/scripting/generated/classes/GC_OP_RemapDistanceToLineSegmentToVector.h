class GC_OP_RemapDistanceToLineSegmentToVector;

#ifndef _gcc_op_remapdistancetolinesegmenttovector_h
#define _gcc_op_remapdistancetolinesegmenttovector_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapDistanceToLineSegmentToVector
{
private:
    void *m_ptr;

public:
    GC_OP_RemapDistanceToLineSegmentToVector() {}
    GC_OP_RemapDistanceToLineSegmentToVector(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapDistanceToLineSegmentToVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapDistanceToLineSegmentToVector", "m_nFieldOutput", false, value); }
    Vector GetMinOutputValue() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_RemapDistanceToLineSegmentToVector", "m_vMinOutputValue"); }
    void SetMinOutputValue(Vector value) { SetSchemaValue(m_ptr, "C_OP_RemapDistanceToLineSegmentToVector", "m_vMinOutputValue", false, value); }
    Vector GetMaxOutputValue() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_RemapDistanceToLineSegmentToVector", "m_vMaxOutputValue"); }
    void SetMaxOutputValue(Vector value) { SetSchemaValue(m_ptr, "C_OP_RemapDistanceToLineSegmentToVector", "m_vMaxOutputValue", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif