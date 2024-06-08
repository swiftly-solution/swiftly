class GCEnvSoundscapeTriggerable;

#ifndef _gccenvsoundscapetriggerable_h
#define _gccenvsoundscapetriggerable_h

#include "../../../scripting.h"




class GCEnvSoundscapeTriggerable
{
private:
    void *m_ptr;

public:
    GCEnvSoundscapeTriggerable() {}
    GCEnvSoundscapeTriggerable(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif