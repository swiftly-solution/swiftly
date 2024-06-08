class GCStateNodeTransitionData;

#ifndef _gccstatenodetransitiondata_h
#define _gccstatenodetransitiondata_h

#include "../../../scripting.h"


#include "GCBlendCurve.h"

class GCStateNodeTransitionData
{
private:
    void *m_ptr;

public:
    GCStateNodeTransitionData() {}
    GCStateNodeTransitionData(void *ptr) : m_ptr(ptr) {}

    GCBlendCurve GetCurve() const { return GetSchemaValue<GCBlendCurve>(m_ptr, "CStateNodeTransitionData", "m_curve"); }
    void SetCurve(GCBlendCurve value) { SetSchemaValue(m_ptr, "CStateNodeTransitionData", "m_curve", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif