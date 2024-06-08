class GC_INIT_RandomVector;

#ifndef _gcc_init_randomvector_h
#define _gcc_init_randomvector_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"
#include "GCRandomNumberGeneratorParameters.h"

class GC_INIT_RandomVector
{
private:
    void *m_ptr;

public:
    GC_INIT_RandomVector() {}
    GC_INIT_RandomVector(void *ptr) : m_ptr(ptr) {}

    Vector GetMin() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_RandomVector", "m_vecMin"); }
    void SetMin(Vector value) { SetSchemaValue(m_ptr, "C_INIT_RandomVector", "m_vecMin", false, value); }
    Vector GetMax() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_RandomVector", "m_vecMax"); }
    void SetMax(Vector value) { SetSchemaValue(m_ptr, "C_INIT_RandomVector", "m_vecMax", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_RandomVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_RandomVector", "m_nFieldOutput", false, value); }
    GCRandomNumberGeneratorParameters GetRandomnessParameters() const { return GetSchemaValue<GCRandomNumberGeneratorParameters>(m_ptr, "C_INIT_RandomVector", "m_randomnessParameters"); }
    void SetRandomnessParameters(GCRandomNumberGeneratorParameters value) { SetSchemaValue(m_ptr, "C_INIT_RandomVector", "m_randomnessParameters", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif