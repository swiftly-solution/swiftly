class GCParticleFunctionPreEmission;

#ifndef _gccparticlefunctionpreemission_h
#define _gccparticlefunctionpreemission_h

#include "../../../scripting.h"




class GCParticleFunctionPreEmission
{
private:
    void *m_ptr;

public:
    GCParticleFunctionPreEmission() {}
    GCParticleFunctionPreEmission(void *ptr) : m_ptr(ptr) {}

    bool GetRunOnce() const { return GetSchemaValue<bool>(m_ptr, "CParticleFunctionPreEmission", "m_bRunOnce"); }
    void SetRunOnce(bool value) { SetSchemaValue(m_ptr, "CParticleFunctionPreEmission", "m_bRunOnce", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif