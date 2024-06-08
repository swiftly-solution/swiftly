class GRnMeshDesc_t;

#ifndef _gcrnmeshdesc_t_h
#define _gcrnmeshdesc_t_h

#include "../../../scripting.h"


#include "GRnMesh_t.h"

class GRnMeshDesc_t
{
private:
    void *m_ptr;

public:
    GRnMeshDesc_t() {}
    GRnMeshDesc_t(void *ptr) : m_ptr(ptr) {}

    GRnMesh_t GetMesh() const { return GetSchemaValue<GRnMesh_t>(m_ptr, "RnMeshDesc_t", "m_Mesh"); }
    void SetMesh(GRnMesh_t value) { SetSchemaValue(m_ptr, "RnMeshDesc_t", "m_Mesh", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif