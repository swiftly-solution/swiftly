class GC_OP_RemapDistanceToLineSegmentToScalar;

#ifndef _gcc_op_remapdistancetolinesegmenttoscalar_h
#define _gcc_op_remapdistancetolinesegmenttoscalar_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapDistanceToLineSegmentToScalar
{
private:
    void *m_ptr;

public:
    GC_OP_RemapDistanceToLineSegmentToScalar() {}
    GC_OP_RemapDistanceToLineSegmentToScalar(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapDistanceToLineSegmentToScalar", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapDistanceToLineSegmentToScalar", "m_nFieldOutput", false, value); }
    float GetMinOutputValue() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapDistanceToLineSegmentToScalar", "m_flMinOutputValue"); }
    void SetMinOutputValue(float value) { SetSchemaValue(m_ptr, "C_OP_RemapDistanceToLineSegmentToScalar", "m_flMinOutputValue", false, value); }
    float GetMaxOutputValue() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapDistanceToLineSegmentToScalar", "m_flMaxOutputValue"); }
    void SetMaxOutputValue(float value) { SetSchemaValue(m_ptr, "C_OP_RemapDistanceToLineSegmentToScalar", "m_flMaxOutputValue", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif