class GC_SunGlowOverlay;

#ifndef _gcc_sunglowoverlay_h
#define _gcc_sunglowoverlay_h

#include "../../../scripting.h"




class GC_SunGlowOverlay
{
private:
    void *m_ptr;

public:
    GC_SunGlowOverlay() {}
    GC_SunGlowOverlay(void *ptr) : m_ptr(ptr) {}

    bool GetModulateByDot() const { return GetSchemaValue<bool>(m_ptr, "C_SunGlowOverlay", "m_bModulateByDot"); }
    void SetModulateByDot(bool value) { SetSchemaValue(m_ptr, "C_SunGlowOverlay", "m_bModulateByDot", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif