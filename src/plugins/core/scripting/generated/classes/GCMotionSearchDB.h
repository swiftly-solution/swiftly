class GCMotionSearchDB;

#ifndef _gccmotionsearchdb_h
#define _gccmotionsearchdb_h

#include "../../../scripting.h"


#include "GCMotionSearchNode.h"
#include "GCProductQuantizer.h"
#include "GMotionDBIndex.h"

class GCMotionSearchDB
{
private:
    void *m_ptr;

public:
    GCMotionSearchDB() {}
    GCMotionSearchDB(void *ptr) : m_ptr(ptr) {}

    GCMotionSearchNode GetRootNode() const { return GetSchemaValue<GCMotionSearchNode>(m_ptr, "CMotionSearchDB", "m_rootNode"); }
    void SetRootNode(GCMotionSearchNode value) { SetSchemaValue(m_ptr, "CMotionSearchDB", "m_rootNode", false, value); }
    GCProductQuantizer GetResidualQuantizer() const { return GetSchemaValue<GCProductQuantizer>(m_ptr, "CMotionSearchDB", "m_residualQuantizer"); }
    void SetResidualQuantizer(GCProductQuantizer value) { SetSchemaValue(m_ptr, "CMotionSearchDB", "m_residualQuantizer", false, value); }
    std::vector<GMotionDBIndex> GetCodeIndices() const { CUtlVector<GMotionDBIndex>* vec = GetSchemaValue<CUtlVector<GMotionDBIndex>*>(m_ptr, "CMotionSearchDB", "m_codeIndices"); std::vector<GMotionDBIndex> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCodeIndices(std::vector<GMotionDBIndex> value) { SetSchemaValueCUtlVector<GMotionDBIndex>(m_ptr, "CMotionSearchDB", "m_codeIndices", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif