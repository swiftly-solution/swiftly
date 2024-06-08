class GCMeshletDescriptor;

#ifndef _gccmeshletdescriptor_h
#define _gccmeshletdescriptor_h

#include "../../../scripting.h"


#include "GCDrawCullingData.h"

class GCMeshletDescriptor
{
private:
    void *m_ptr;

public:
    GCMeshletDescriptor() {}
    GCMeshletDescriptor(void *ptr) : m_ptr(ptr) {}

    GCDrawCullingData GetCullingData() const { return GetSchemaValue<GCDrawCullingData>(m_ptr, "CMeshletDescriptor", "m_CullingData"); }
    void SetCullingData(GCDrawCullingData value) { SetSchemaValue(m_ptr, "CMeshletDescriptor", "m_CullingData", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif