class GCNavVolumeVector;

#ifndef _gccnavvolumevector_h
#define _gccnavvolumevector_h

#include "../../../scripting.h"




class GCNavVolumeVector
{
private:
    void *m_ptr;

public:
    GCNavVolumeVector() {}
    GCNavVolumeVector(void *ptr) : m_ptr(ptr) {}

    bool GetHasBeenPreFiltered() const { return GetSchemaValue<bool>(m_ptr, "CNavVolumeVector", "m_bHasBeenPreFiltered"); }
    void SetHasBeenPreFiltered(bool value) { SetSchemaValue(m_ptr, "CNavVolumeVector", "m_bHasBeenPreFiltered", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif