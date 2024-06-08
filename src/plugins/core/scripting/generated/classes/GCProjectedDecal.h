class GCProjectedDecal;

#ifndef _gccprojecteddecal_h
#define _gccprojecteddecal_h

#include "../../../scripting.h"




class GCProjectedDecal
{
private:
    void *m_ptr;

public:
    GCProjectedDecal() {}
    GCProjectedDecal(void *ptr) : m_ptr(ptr) {}

    int32_t GetTexture() const { return GetSchemaValue<int32_t>(m_ptr, "CProjectedDecal", "m_nTexture"); }
    void SetTexture(int32_t value) { SetSchemaValue(m_ptr, "CProjectedDecal", "m_nTexture", false, value); }
    float GetDistance() const { return GetSchemaValue<float>(m_ptr, "CProjectedDecal", "m_flDistance"); }
    void SetDistance(float value) { SetSchemaValue(m_ptr, "CProjectedDecal", "m_flDistance", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif