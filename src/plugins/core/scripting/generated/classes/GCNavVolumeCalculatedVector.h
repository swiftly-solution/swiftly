class GCNavVolumeCalculatedVector;

#ifndef _gccnavvolumecalculatedvector_h
#define _gccnavvolumecalculatedvector_h

#include "../../../scripting.h"




class GCNavVolumeCalculatedVector
{
private:
    void *m_ptr;

public:
    GCNavVolumeCalculatedVector() {}
    GCNavVolumeCalculatedVector(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif