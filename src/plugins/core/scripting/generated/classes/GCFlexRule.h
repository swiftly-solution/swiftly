class GCFlexRule;

#ifndef _gccflexrule_h
#define _gccflexrule_h

#include "../../../scripting.h"


#include "GCFlexOp.h"

class GCFlexRule
{
private:
    void *m_ptr;

public:
    GCFlexRule() {}
    GCFlexRule(void *ptr) : m_ptr(ptr) {}

    int32_t GetFlex() const { return GetSchemaValue<int32_t>(m_ptr, "CFlexRule", "m_nFlex"); }
    void SetFlex(int32_t value) { SetSchemaValue(m_ptr, "CFlexRule", "m_nFlex", false, value); }
    std::vector<GCFlexOp> GetFlexOps() const { CUtlVector<GCFlexOp>* vec = GetSchemaValue<CUtlVector<GCFlexOp>*>(m_ptr, "CFlexRule", "m_FlexOps"); std::vector<GCFlexOp> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFlexOps(std::vector<GCFlexOp> value) { SetSchemaValueCUtlVector<GCFlexOp>(m_ptr, "CFlexRule", "m_FlexOps", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif