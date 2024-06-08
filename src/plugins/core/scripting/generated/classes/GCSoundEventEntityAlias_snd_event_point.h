class GCSoundEventEntityAlias_snd_event_point;

#ifndef _gccsoundevententityalias_snd_event_point_h
#define _gccsoundevententityalias_snd_event_point_h

#include "../../../scripting.h"




class GCSoundEventEntityAlias_snd_event_point
{
private:
    void *m_ptr;

public:
    GCSoundEventEntityAlias_snd_event_point() {}
    GCSoundEventEntityAlias_snd_event_point(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif