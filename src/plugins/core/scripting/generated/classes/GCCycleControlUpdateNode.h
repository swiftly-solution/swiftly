class GCCycleControlUpdateNode;

#ifndef _gcccyclecontrolupdatenode_h
#define _gcccyclecontrolupdatenode_h

#include "../../../scripting.h"

#include "../types/GAnimValueSource.h"
#include "GCAnimParamHandle.h"

class GCCycleControlUpdateNode
{
private:
    void *m_ptr;

public:
    GCCycleControlUpdateNode() {}
    GCCycleControlUpdateNode(void *ptr) : m_ptr(ptr) {}

    AnimValueSource GetValueSource() const { return GetSchemaValue<AnimValueSource>(m_ptr, "CCycleControlUpdateNode", "m_valueSource"); }
    void SetValueSource(AnimValueSource value) { SetSchemaValue(m_ptr, "CCycleControlUpdateNode", "m_valueSource", false, value); }
    GCAnimParamHandle GetParamIndex() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CCycleControlUpdateNode", "m_paramIndex"); }
    void SetParamIndex(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CCycleControlUpdateNode", "m_paramIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif