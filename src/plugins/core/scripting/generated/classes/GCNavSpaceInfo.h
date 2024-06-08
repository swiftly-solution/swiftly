class GCNavSpaceInfo;

#ifndef _gccnavspaceinfo_h
#define _gccnavspaceinfo_h

#include "../../../scripting.h"




class GCNavSpaceInfo
{
private:
    void *m_ptr;

public:
    GCNavSpaceInfo() {}
    GCNavSpaceInfo(void *ptr) : m_ptr(ptr) {}

    bool GetCreateFlightSpace() const { return GetSchemaValue<bool>(m_ptr, "CNavSpaceInfo", "m_bCreateFlightSpace"); }
    void SetCreateFlightSpace(bool value) { SetSchemaValue(m_ptr, "CNavSpaceInfo", "m_bCreateFlightSpace", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif