class GRagdollCreationParams_t;

#ifndef _gcragdollcreationparams_t_h
#define _gcragdollcreationparams_t_h

#include "../../../scripting.h"




class GRagdollCreationParams_t
{
private:
    void *m_ptr;

public:
    GRagdollCreationParams_t() {}
    GRagdollCreationParams_t(void *ptr) : m_ptr(ptr) {}

    Vector GetForce() const { return GetSchemaValue<Vector>(m_ptr, "RagdollCreationParams_t", "m_vForce"); }
    void SetForce(Vector value) { SetSchemaValue(m_ptr, "RagdollCreationParams_t", "m_vForce", true, value); }
    int32_t GetForceBone() const { return GetSchemaValue<int32_t>(m_ptr, "RagdollCreationParams_t", "m_nForceBone"); }
    void SetForceBone(int32_t value) { SetSchemaValue(m_ptr, "RagdollCreationParams_t", "m_nForceBone", true, value); }
    bool GetForceCurrentWorldTransform() const { return GetSchemaValue<bool>(m_ptr, "RagdollCreationParams_t", "m_bForceCurrentWorldTransform"); }
    void SetForceCurrentWorldTransform(bool value) { SetSchemaValue(m_ptr, "RagdollCreationParams_t", "m_bForceCurrentWorldTransform", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif