class GC_OP_RemapScalarOnceTimed;

#ifndef _gcc_op_remapscalaroncetimed_h
#define _gcc_op_remapscalaroncetimed_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapScalarOnceTimed
{
private:
    void *m_ptr;

public:
    GC_OP_RemapScalarOnceTimed() {}
    GC_OP_RemapScalarOnceTimed(void *ptr) : m_ptr(ptr) {}

    bool GetProportional() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapScalarOnceTimed", "m_bProportional"); }
    void SetProportional(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapScalarOnceTimed", "m_bProportional", false, value); }
    GParticleAttributeIndex_t GetFieldInput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapScalarOnceTimed", "m_nFieldInput"); }
    void SetFieldInput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapScalarOnceTimed", "m_nFieldInput", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapScalarOnceTimed", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapScalarOnceTimed", "m_nFieldOutput", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapScalarOnceTimed", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapScalarOnceTimed", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapScalarOnceTimed", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapScalarOnceTimed", "m_flInputMax", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapScalarOnceTimed", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapScalarOnceTimed", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapScalarOnceTimed", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapScalarOnceTimed", "m_flOutputMax", false, value); }
    float GetRemapTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapScalarOnceTimed", "m_flRemapTime"); }
    void SetRemapTime(float value) { SetSchemaValue(m_ptr, "C_OP_RemapScalarOnceTimed", "m_flRemapTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif