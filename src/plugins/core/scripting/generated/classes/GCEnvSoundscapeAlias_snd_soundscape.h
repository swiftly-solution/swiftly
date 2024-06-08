class GCEnvSoundscapeAlias_snd_soundscape;

#ifndef _gccenvsoundscapealias_snd_soundscape_h
#define _gccenvsoundscapealias_snd_soundscape_h

#include "../../../scripting.h"




class GCEnvSoundscapeAlias_snd_soundscape
{
private:
    void *m_ptr;

public:
    GCEnvSoundscapeAlias_snd_soundscape() {}
    GCEnvSoundscapeAlias_snd_soundscape(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif