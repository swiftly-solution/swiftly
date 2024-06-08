class GJiggleBoneSettings_t;

#ifndef _gcjigglebonesettings_t_h
#define _gcjigglebonesettings_t_h

#include "../../../scripting.h"

#include "../types/GJiggleBoneSimSpace.h"


class GJiggleBoneSettings_t
{
private:
    void *m_ptr;

public:
    GJiggleBoneSettings_t() {}
    GJiggleBoneSettings_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetBoneIndex() const { return GetSchemaValue<int32_t>(m_ptr, "JiggleBoneSettings_t", "m_nBoneIndex"); }
    void SetBoneIndex(int32_t value) { SetSchemaValue(m_ptr, "JiggleBoneSettings_t", "m_nBoneIndex", true, value); }
    float GetSpringStrength() const { return GetSchemaValue<float>(m_ptr, "JiggleBoneSettings_t", "m_flSpringStrength"); }
    void SetSpringStrength(float value) { SetSchemaValue(m_ptr, "JiggleBoneSettings_t", "m_flSpringStrength", true, value); }
    float GetMaxTimeStep() const { return GetSchemaValue<float>(m_ptr, "JiggleBoneSettings_t", "m_flMaxTimeStep"); }
    void SetMaxTimeStep(float value) { SetSchemaValue(m_ptr, "JiggleBoneSettings_t", "m_flMaxTimeStep", true, value); }
    float GetDamping() const { return GetSchemaValue<float>(m_ptr, "JiggleBoneSettings_t", "m_flDamping"); }
    void SetDamping(float value) { SetSchemaValue(m_ptr, "JiggleBoneSettings_t", "m_flDamping", true, value); }
    Vector GetBoundsMaxLS() const { return GetSchemaValue<Vector>(m_ptr, "JiggleBoneSettings_t", "m_vBoundsMaxLS"); }
    void SetBoundsMaxLS(Vector value) { SetSchemaValue(m_ptr, "JiggleBoneSettings_t", "m_vBoundsMaxLS", true, value); }
    Vector GetBoundsMinLS() const { return GetSchemaValue<Vector>(m_ptr, "JiggleBoneSettings_t", "m_vBoundsMinLS"); }
    void SetBoundsMinLS(Vector value) { SetSchemaValue(m_ptr, "JiggleBoneSettings_t", "m_vBoundsMinLS", true, value); }
    JiggleBoneSimSpace GetSimSpace() const { return GetSchemaValue<JiggleBoneSimSpace>(m_ptr, "JiggleBoneSettings_t", "m_eSimSpace"); }
    void SetSimSpace(JiggleBoneSimSpace value) { SetSchemaValue(m_ptr, "JiggleBoneSettings_t", "m_eSimSpace", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif