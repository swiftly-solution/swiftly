class GCParticleFunctionInitializer;

#ifndef _gccparticlefunctioninitializer_h
#define _gccparticlefunctioninitializer_h

#include "../../../scripting.h"




class GCParticleFunctionInitializer
{
private:
    void *m_ptr;

public:
    GCParticleFunctionInitializer() {}
    GCParticleFunctionInitializer(void *ptr) : m_ptr(ptr) {}

    int32_t GetAssociatedEmitterIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleFunctionInitializer", "m_nAssociatedEmitterIndex"); }
    void SetAssociatedEmitterIndex(int32_t value) { SetSchemaValue(m_ptr, "CParticleFunctionInitializer", "m_nAssociatedEmitterIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif