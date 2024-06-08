class GCRopeOverlapHit;

#ifndef _gccropeoverlaphit_h
#define _gccropeoverlaphit_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCRopeOverlapHit
{
private:
    void *m_ptr;

public:
    GCRopeOverlapHit() {}
    GCRopeOverlapHit(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CRopeOverlapHit", "m_hEntity"); }
    void SetEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Entity' is not possible.\n"); }
    std::vector<int32> GetOverlappingLinks() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CRopeOverlapHit", "m_vecOverlappingLinks"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetOverlappingLinks(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "CRopeOverlapHit", "m_vecOverlappingLinks", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif