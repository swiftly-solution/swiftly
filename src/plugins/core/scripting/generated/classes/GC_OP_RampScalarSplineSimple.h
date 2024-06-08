class GC_OP_RampScalarSplineSimple;

#ifndef _gcc_op_rampscalarsplinesimple_h
#define _gcc_op_rampscalarsplinesimple_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RampScalarSplineSimple
{
private:
    void *m_ptr;

public:
    GC_OP_RampScalarSplineSimple() {}
    GC_OP_RampScalarSplineSimple(void *ptr) : m_ptr(ptr) {}

    float GetRate() const { return GetSchemaValue<float>(m_ptr, "C_OP_RampScalarSplineSimple", "m_Rate"); }
    void SetRate(float value) { SetSchemaValue(m_ptr, "C_OP_RampScalarSplineSimple", "m_Rate", false, value); }
    float GetStartTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_RampScalarSplineSimple", "m_flStartTime"); }
    void SetStartTime(float value) { SetSchemaValue(m_ptr, "C_OP_RampScalarSplineSimple", "m_flStartTime", false, value); }
    float GetEndTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_RampScalarSplineSimple", "m_flEndTime"); }
    void SetEndTime(float value) { SetSchemaValue(m_ptr, "C_OP_RampScalarSplineSimple", "m_flEndTime", false, value); }
    GParticleAttributeIndex_t GetField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RampScalarSplineSimple", "m_nField"); }
    void SetField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RampScalarSplineSimple", "m_nField", false, value); }
    bool GetEaseOut() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RampScalarSplineSimple", "m_bEaseOut"); }
    void SetEaseOut(bool value) { SetSchemaValue(m_ptr, "C_OP_RampScalarSplineSimple", "m_bEaseOut", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif