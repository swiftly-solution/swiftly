class GCBaseConstraint;

#ifndef _gccbaseconstraint_h
#define _gccbaseconstraint_h

#include "../../../scripting.h"


#include "GCConstraintSlave.h"
#include "GCConstraintTarget.h"

class GCBaseConstraint
{
private:
    void *m_ptr;

public:
    GCBaseConstraint() {}
    GCBaseConstraint(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CBaseConstraint", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "CBaseConstraint", "m_name", false, value); }
    Vector GetUpVector() const { return GetSchemaValue<Vector>(m_ptr, "CBaseConstraint", "m_vUpVector"); }
    void SetUpVector(Vector value) { SetSchemaValue(m_ptr, "CBaseConstraint", "m_vUpVector", false, value); }
    std::vector<GCConstraintSlave> GetSlaves() const { CUtlVector<GCConstraintSlave>* vec = GetSchemaValue<CUtlVector<GCConstraintSlave>*>(m_ptr, "CBaseConstraint", "m_slaves"); std::vector<GCConstraintSlave> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSlaves(std::vector<GCConstraintSlave> value) { SetSchemaValueCUtlVector<GCConstraintSlave>(m_ptr, "CBaseConstraint", "m_slaves", false, value); }
    std::vector<GCConstraintTarget> GetTargets() const { CUtlVector<GCConstraintTarget>* vec = GetSchemaValue<CUtlVector<GCConstraintTarget>*>(m_ptr, "CBaseConstraint", "m_targets"); std::vector<GCConstraintTarget> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTargets(std::vector<GCConstraintTarget> value) { SetSchemaValueCUtlVector<GCConstraintTarget>(m_ptr, "CBaseConstraint", "m_targets", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif