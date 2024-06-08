class GCSpeedScaleUpdateNode;

#ifndef _gccspeedscaleupdatenode_h
#define _gccspeedscaleupdatenode_h

#include "../../../scripting.h"


#include "GCAnimParamHandle.h"

class GCSpeedScaleUpdateNode
{
private:
    void *m_ptr;

public:
    GCSpeedScaleUpdateNode() {}
    GCSpeedScaleUpdateNode(void *ptr) : m_ptr(ptr) {}

    GCAnimParamHandle GetParamIndex() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CSpeedScaleUpdateNode", "m_paramIndex"); }
    void SetParamIndex(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CSpeedScaleUpdateNode", "m_paramIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif