class GCStanceScaleUpdateNode;

#ifndef _gccstancescaleupdatenode_h
#define _gccstancescaleupdatenode_h

#include "../../../scripting.h"


#include "GCAnimParamHandle.h"

class GCStanceScaleUpdateNode
{
private:
    void *m_ptr;

public:
    GCStanceScaleUpdateNode() {}
    GCStanceScaleUpdateNode(void *ptr) : m_ptr(ptr) {}

    GCAnimParamHandle GetParam() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CStanceScaleUpdateNode", "m_hParam"); }
    void SetParam(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CStanceScaleUpdateNode", "m_hParam", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif