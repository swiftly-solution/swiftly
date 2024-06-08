class GCEnvSoundscapeProxyAlias_snd_soundscape_proxy;

#ifndef _gccenvsoundscapeproxyalias_snd_soundscape_proxy_h
#define _gccenvsoundscapeproxyalias_snd_soundscape_proxy_h

#include "../../../scripting.h"




class GCEnvSoundscapeProxyAlias_snd_soundscape_proxy
{
private:
    void *m_ptr;

public:
    GCEnvSoundscapeProxyAlias_snd_soundscape_proxy() {}
    GCEnvSoundscapeProxyAlias_snd_soundscape_proxy(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif