class GCMultiplayer_Expresser;

#ifndef _gccmultiplayer_expresser_h
#define _gccmultiplayer_expresser_h

#include "../../../scripting.h"




class GCMultiplayer_Expresser
{
private:
    void *m_ptr;

public:
    GCMultiplayer_Expresser() {}
    GCMultiplayer_Expresser(void *ptr) : m_ptr(ptr) {}

    bool GetAllowMultipleScenes() const { return GetSchemaValue<bool>(m_ptr, "CMultiplayer_Expresser", "m_bAllowMultipleScenes"); }
    void SetAllowMultipleScenes(bool value) { SetSchemaValue(m_ptr, "CMultiplayer_Expresser", "m_bAllowMultipleScenes", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif