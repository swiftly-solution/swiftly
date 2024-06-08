class GCLogicNPCCounterAABB;

#ifndef _gcclogicnpccounteraabb_h
#define _gcclogicnpccounteraabb_h

#include "../../../scripting.h"




class GCLogicNPCCounterAABB
{
private:
    void *m_ptr;

public:
    GCLogicNPCCounterAABB() {}
    GCLogicNPCCounterAABB(void *ptr) : m_ptr(ptr) {}

    Vector GetDistanceOuterMins() const { return GetSchemaValue<Vector>(m_ptr, "CLogicNPCCounterAABB", "m_vDistanceOuterMins"); }
    void SetDistanceOuterMins(Vector value) { SetSchemaValue(m_ptr, "CLogicNPCCounterAABB", "m_vDistanceOuterMins", false, value); }
    Vector GetDistanceOuterMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CLogicNPCCounterAABB", "m_vDistanceOuterMaxs"); }
    void SetDistanceOuterMaxs(Vector value) { SetSchemaValue(m_ptr, "CLogicNPCCounterAABB", "m_vDistanceOuterMaxs", false, value); }
    Vector GetOuterMins() const { return GetSchemaValue<Vector>(m_ptr, "CLogicNPCCounterAABB", "m_vOuterMins"); }
    void SetOuterMins(Vector value) { SetSchemaValue(m_ptr, "CLogicNPCCounterAABB", "m_vOuterMins", false, value); }
    Vector GetOuterMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CLogicNPCCounterAABB", "m_vOuterMaxs"); }
    void SetOuterMaxs(Vector value) { SetSchemaValue(m_ptr, "CLogicNPCCounterAABB", "m_vOuterMaxs", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif