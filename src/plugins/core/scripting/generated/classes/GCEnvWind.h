class GCEnvWind;

#ifndef _gccenvwind_h
#define _gccenvwind_h

#include "../../../scripting.h"


#include "GCEnvWindShared.h"
#include "GCEnvWind.h"

class GCEnvWind
{
private:
    void *m_ptr;

public:
    GCEnvWind() {}
    GCEnvWind(void *ptr) : m_ptr(ptr) {}

    GCEnvWindShared GetEnvWindShared() const { return GetSchemaValue<GCEnvWindShared>(m_ptr, "CEnvWind", "m_EnvWindShared"); }
    void SetEnvWindShared(GCEnvWindShared value) { SetSchemaValue(m_ptr, "CEnvWind", "m_EnvWindShared", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif