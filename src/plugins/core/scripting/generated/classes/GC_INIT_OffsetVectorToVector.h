class GC_INIT_OffsetVectorToVector;

#ifndef _gcc_init_offsetvectortovector_h
#define _gcc_init_offsetvectortovector_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"
#include "GCRandomNumberGeneratorParameters.h"

class GC_INIT_OffsetVectorToVector
{
private:
    void *m_ptr;

public:
    GC_INIT_OffsetVectorToVector() {}
    GC_INIT_OffsetVectorToVector(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldInput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_OffsetVectorToVector", "m_nFieldInput"); }
    void SetFieldInput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_OffsetVectorToVector", "m_nFieldInput", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_OffsetVectorToVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_OffsetVectorToVector", "m_nFieldOutput", false, value); }
    Vector GetOutputMin() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_OffsetVectorToVector", "m_vecOutputMin"); }
    void SetOutputMin(Vector value) { SetSchemaValue(m_ptr, "C_INIT_OffsetVectorToVector", "m_vecOutputMin", false, value); }
    Vector GetOutputMax() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_OffsetVectorToVector", "m_vecOutputMax"); }
    void SetOutputMax(Vector value) { SetSchemaValue(m_ptr, "C_INIT_OffsetVectorToVector", "m_vecOutputMax", false, value); }
    GCRandomNumberGeneratorParameters GetRandomnessParameters() const { return GetSchemaValue<GCRandomNumberGeneratorParameters>(m_ptr, "C_INIT_OffsetVectorToVector", "m_randomnessParameters"); }
    void SetRandomnessParameters(GCRandomNumberGeneratorParameters value) { SetSchemaValue(m_ptr, "C_INIT_OffsetVectorToVector", "m_randomnessParameters", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif