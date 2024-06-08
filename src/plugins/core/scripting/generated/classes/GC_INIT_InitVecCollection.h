class GC_INIT_InitVecCollection;

#ifndef _gcc_init_initveccollection_h
#define _gcc_init_initveccollection_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_INIT_InitVecCollection
{
private:
    void *m_ptr;

public:
    GC_INIT_InitVecCollection() {}
    GC_INIT_InitVecCollection(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetOutputField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_InitVecCollection", "m_nOutputField"); }
    void SetOutputField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_InitVecCollection", "m_nOutputField", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif