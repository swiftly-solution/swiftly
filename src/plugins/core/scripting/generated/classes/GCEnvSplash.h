class GCEnvSplash;

#ifndef _gccenvsplash_h
#define _gccenvsplash_h

#include "../../../scripting.h"




class GCEnvSplash
{
private:
    void *m_ptr;

public:
    GCEnvSplash() {}
    GCEnvSplash(void *ptr) : m_ptr(ptr) {}

    float GetScale() const { return GetSchemaValue<float>(m_ptr, "CEnvSplash", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "CEnvSplash", "m_flScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif