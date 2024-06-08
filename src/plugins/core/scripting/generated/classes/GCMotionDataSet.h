class GCMotionDataSet;

#ifndef _gccmotiondataset_h
#define _gccmotiondataset_h

#include "../../../scripting.h"


#include "GCMotionGraph.h"
#include "GCMotionGraphGroup.h"

class GCMotionDataSet
{
private:
    void *m_ptr;

public:
    GCMotionDataSet() {}
    GCMotionDataSet(void *ptr) : m_ptr(ptr) {}

    std::vector<GCMotionGraphGroup> GetGroups() const { CUtlVector<GCMotionGraphGroup>* vec = GetSchemaValue<CUtlVector<GCMotionGraphGroup>*>(m_ptr, "CMotionDataSet", "m_groups"); std::vector<GCMotionGraphGroup> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetGroups(std::vector<GCMotionGraphGroup> value) { SetSchemaValueCUtlVector<GCMotionGraphGroup>(m_ptr, "CMotionDataSet", "m_groups", false, value); }
    int32_t GetDimensionCount() const { return GetSchemaValue<int32_t>(m_ptr, "CMotionDataSet", "m_nDimensionCount"); }
    void SetDimensionCount(int32_t value) { SetSchemaValue(m_ptr, "CMotionDataSet", "m_nDimensionCount", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif