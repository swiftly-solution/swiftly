class GC_INIT_AddVectorToVector;

#ifndef _gcc_init_addvectortovector_h
#define _gcc_init_addvectortovector_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"
#include "GCRandomNumberGeneratorParameters.h"

class GC_INIT_AddVectorToVector
{
private:
    void *m_ptr;

public:
    GC_INIT_AddVectorToVector() {}
    GC_INIT_AddVectorToVector(void *ptr) : m_ptr(ptr) {}

    Vector GetScale() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_AddVectorToVector", "m_vecScale"); }
    void SetScale(Vector value) { SetSchemaValue(m_ptr, "C_INIT_AddVectorToVector", "m_vecScale", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_AddVectorToVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_AddVectorToVector", "m_nFieldOutput", false, value); }
    GParticleAttributeIndex_t GetFieldInput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_AddVectorToVector", "m_nFieldInput"); }
    void SetFieldInput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_AddVectorToVector", "m_nFieldInput", false, value); }
    Vector GetOffsetMin() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_AddVectorToVector", "m_vOffsetMin"); }
    void SetOffsetMin(Vector value) { SetSchemaValue(m_ptr, "C_INIT_AddVectorToVector", "m_vOffsetMin", false, value); }
    Vector GetOffsetMax() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_AddVectorToVector", "m_vOffsetMax"); }
    void SetOffsetMax(Vector value) { SetSchemaValue(m_ptr, "C_INIT_AddVectorToVector", "m_vOffsetMax", false, value); }
    GCRandomNumberGeneratorParameters GetRandomnessParameters() const { return GetSchemaValue<GCRandomNumberGeneratorParameters>(m_ptr, "C_INIT_AddVectorToVector", "m_randomnessParameters"); }
    void SetRandomnessParameters(GCRandomNumberGeneratorParameters value) { SetSchemaValue(m_ptr, "C_INIT_AddVectorToVector", "m_randomnessParameters", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif