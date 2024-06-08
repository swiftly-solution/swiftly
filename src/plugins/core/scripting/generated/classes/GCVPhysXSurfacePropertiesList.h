class GCVPhysXSurfacePropertiesList;

#ifndef _gccvphysxsurfacepropertieslist_h
#define _gccvphysxsurfacepropertieslist_h

#include "../../../scripting.h"


#include "GCPhysSurfaceProperties.h"

class GCVPhysXSurfacePropertiesList
{
private:
    void *m_ptr;

public:
    GCVPhysXSurfacePropertiesList() {}
    GCVPhysXSurfacePropertiesList(void *ptr) : m_ptr(ptr) {}

    std::vector<GCPhysSurfaceProperties*> GetSurfacePropertiesList() const { CUtlVector<GCPhysSurfaceProperties*>* vec = GetSchemaValue<CUtlVector<GCPhysSurfaceProperties*>*>(m_ptr, "CVPhysXSurfacePropertiesList", "m_surfacePropertiesList"); std::vector<GCPhysSurfaceProperties*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSurfacePropertiesList(std::vector<GCPhysSurfaceProperties*> value) { SetSchemaValueCUtlVector<GCPhysSurfaceProperties*>(m_ptr, "CVPhysXSurfacePropertiesList", "m_surfacePropertiesList", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif