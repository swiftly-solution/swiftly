class GCStateNodeStateData;

#ifndef _gccstatenodestatedata_h
#define _gccstatenodestatedata_h

#include "../../../scripting.h"


#include "GCAnimUpdateNodeRef.h"

class GCStateNodeStateData
{
private:
    void *m_ptr;

public:
    GCStateNodeStateData() {}
    GCStateNodeStateData(void *ptr) : m_ptr(ptr) {}

    GCAnimUpdateNodeRef GetChild() const { return GetSchemaValue<GCAnimUpdateNodeRef>(m_ptr, "CStateNodeStateData", "m_pChild"); }
    void SetChild(GCAnimUpdateNodeRef value) { SetSchemaValue(m_ptr, "CStateNodeStateData", "m_pChild", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif