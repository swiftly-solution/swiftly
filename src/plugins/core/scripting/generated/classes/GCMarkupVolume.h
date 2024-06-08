class GCMarkupVolume;

#ifndef _gccmarkupvolume_h
#define _gccmarkupvolume_h

#include "../../../scripting.h"




class GCMarkupVolume
{
private:
    void *m_ptr;

public:
    GCMarkupVolume() {}
    GCMarkupVolume(void *ptr) : m_ptr(ptr) {}

    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CMarkupVolume", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CMarkupVolume", "m_bDisabled", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif