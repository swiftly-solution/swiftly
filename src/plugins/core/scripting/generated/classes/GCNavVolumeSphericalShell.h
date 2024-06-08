class GCNavVolumeSphericalShell;

#ifndef _gccnavvolumesphericalshell_h
#define _gccnavvolumesphericalshell_h

#include "../../../scripting.h"




class GCNavVolumeSphericalShell
{
private:
    void *m_ptr;

public:
    GCNavVolumeSphericalShell() {}
    GCNavVolumeSphericalShell(void *ptr) : m_ptr(ptr) {}

    float GetRadiusInner() const { return GetSchemaValue<float>(m_ptr, "CNavVolumeSphericalShell", "m_flRadiusInner"); }
    void SetRadiusInner(float value) { SetSchemaValue(m_ptr, "CNavVolumeSphericalShell", "m_flRadiusInner", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif