class GCFootstepControl;

#ifndef _gccfootstepcontrol_h
#define _gccfootstepcontrol_h

#include "../../../scripting.h"




class GCFootstepControl
{
private:
    void *m_ptr;

public:
    GCFootstepControl() {}
    GCFootstepControl(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetSource() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFootstepControl", "m_source"); }
    void SetSource(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFootstepControl", "m_source", false, value); }
    CUtlSymbolLarge GetDestination() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFootstepControl", "m_destination"); }
    void SetDestination(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFootstepControl", "m_destination", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif