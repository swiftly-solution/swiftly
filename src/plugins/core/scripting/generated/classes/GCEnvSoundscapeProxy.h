class GCEnvSoundscapeProxy;

#ifndef _gccenvsoundscapeproxy_h
#define _gccenvsoundscapeproxy_h

#include "../../../scripting.h"




class GCEnvSoundscapeProxy
{
private:
    void *m_ptr;

public:
    GCEnvSoundscapeProxy() {}
    GCEnvSoundscapeProxy(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetMainSoundscapeName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvSoundscapeProxy", "m_MainSoundscapeName"); }
    void SetMainSoundscapeName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvSoundscapeProxy", "m_MainSoundscapeName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif