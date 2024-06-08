class GCFogTrigger;

#ifndef _gccfogtrigger_h
#define _gccfogtrigger_h

#include "../../../scripting.h"


#include "Gfogparams_t.h"

class GCFogTrigger
{
private:
    void *m_ptr;

public:
    GCFogTrigger() {}
    GCFogTrigger(void *ptr) : m_ptr(ptr) {}

    Gfogparams_t GetFog() const { return GetSchemaValue<Gfogparams_t>(m_ptr, "CFogTrigger", "m_fog"); }
    void SetFog(Gfogparams_t value) { SetSchemaValue(m_ptr, "CFogTrigger", "m_fog", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif