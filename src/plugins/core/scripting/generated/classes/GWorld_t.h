class GWorld_t;

#ifndef _gcworld_t_h
#define _gcworld_t_h

#include "../../../scripting.h"


#include "GWorldBuilderParams_t.h"
#include "GNodeData_t.h"
#include "GBakedLightingInfo_t.h"

class GWorld_t
{
private:
    void *m_ptr;

public:
    GWorld_t() {}
    GWorld_t(void *ptr) : m_ptr(ptr) {}

    GWorldBuilderParams_t GetBuilderParams() const { return GetSchemaValue<GWorldBuilderParams_t>(m_ptr, "World_t", "m_builderParams"); }
    void SetBuilderParams(GWorldBuilderParams_t value) { SetSchemaValue(m_ptr, "World_t", "m_builderParams", true, value); }
    std::vector<GNodeData_t> GetWorldNodes() const { CUtlVector<GNodeData_t>* vec = GetSchemaValue<CUtlVector<GNodeData_t>*>(m_ptr, "World_t", "m_worldNodes"); std::vector<GNodeData_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetWorldNodes(std::vector<GNodeData_t> value) { SetSchemaValueCUtlVector<GNodeData_t>(m_ptr, "World_t", "m_worldNodes", true, value); }
    GBakedLightingInfo_t GetWorldLightingInfo() const { return GetSchemaValue<GBakedLightingInfo_t>(m_ptr, "World_t", "m_worldLightingInfo"); }
    void SetWorldLightingInfo(GBakedLightingInfo_t value) { SetSchemaValue(m_ptr, "World_t", "m_worldLightingInfo", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif