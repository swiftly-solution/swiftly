class GCFeVertexMapBuildArray;

#ifndef _gccfevertexmapbuildarray_h
#define _gccfevertexmapbuildarray_h

#include "../../../scripting.h"


#include "GFeVertexMapBuild_t.h"

class GCFeVertexMapBuildArray
{
private:
    void *m_ptr;

public:
    GCFeVertexMapBuildArray() {}
    GCFeVertexMapBuildArray(void *ptr) : m_ptr(ptr) {}

    std::vector<GFeVertexMapBuild_t*> GetArray() const { CUtlVector<GFeVertexMapBuild_t*>* vec = GetSchemaValue<CUtlVector<GFeVertexMapBuild_t*>*>(m_ptr, "CFeVertexMapBuildArray", "m_Array"); std::vector<GFeVertexMapBuild_t*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetArray(std::vector<GFeVertexMapBuild_t*> value) { SetSchemaValueCUtlVector<GFeVertexMapBuild_t*>(m_ptr, "CFeVertexMapBuildArray", "m_Array", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif