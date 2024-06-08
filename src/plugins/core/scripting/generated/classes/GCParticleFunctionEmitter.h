class GCParticleFunctionEmitter;

#ifndef _gccparticlefunctionemitter_h
#define _gccparticlefunctionemitter_h

#include "../../../scripting.h"




class GCParticleFunctionEmitter
{
private:
    void *m_ptr;

public:
    GCParticleFunctionEmitter() {}
    GCParticleFunctionEmitter(void *ptr) : m_ptr(ptr) {}

    int32_t GetEmitterIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleFunctionEmitter", "m_nEmitterIndex"); }
    void SetEmitterIndex(int32_t value) { SetSchemaValue(m_ptr, "CParticleFunctionEmitter", "m_nEmitterIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif