class GCEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable;

#ifndef _gccenvsoundscapetriggerablealias_snd_soundscape_triggerable_h
#define _gccenvsoundscapetriggerablealias_snd_soundscape_triggerable_h

#include "../../../scripting.h"




class GCEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable
{
private:
    void *m_ptr;

public:
    GCEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable() {}
    GCEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif