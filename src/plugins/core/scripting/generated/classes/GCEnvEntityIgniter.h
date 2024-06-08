class GCEnvEntityIgniter;

#ifndef _gccenventityigniter_h
#define _gccenventityigniter_h

#include "../../../scripting.h"




class GCEnvEntityIgniter
{
private:
    void *m_ptr;

public:
    GCEnvEntityIgniter() {}
    GCEnvEntityIgniter(void *ptr) : m_ptr(ptr) {}

    float GetLifetime() const { return GetSchemaValue<float>(m_ptr, "CEnvEntityIgniter", "m_flLifetime"); }
    void SetLifetime(float value) { SetSchemaValue(m_ptr, "CEnvEntityIgniter", "m_flLifetime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif