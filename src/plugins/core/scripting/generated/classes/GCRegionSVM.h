class GCRegionSVM;

#ifndef _gccregionsvm_h
#define _gccregionsvm_h

#include "../../../scripting.h"


#include "GRnPlane_t.h"

class GCRegionSVM
{
private:
    void *m_ptr;

public:
    GCRegionSVM() {}
    GCRegionSVM(void *ptr) : m_ptr(ptr) {}

    std::vector<GRnPlane_t> GetPlanes() const { CUtlVector<GRnPlane_t>* vec = GetSchemaValue<CUtlVector<GRnPlane_t>*>(m_ptr, "CRegionSVM", "m_Planes"); std::vector<GRnPlane_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPlanes(std::vector<GRnPlane_t> value) { SetSchemaValueCUtlVector<GRnPlane_t>(m_ptr, "CRegionSVM", "m_Planes", false, value); }
    std::vector<uint32> GetNodes() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CRegionSVM", "m_Nodes"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetNodes(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "CRegionSVM", "m_Nodes", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif