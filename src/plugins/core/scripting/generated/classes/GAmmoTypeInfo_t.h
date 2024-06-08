class GAmmoTypeInfo_t;

#ifndef _gcammotypeinfo_t_h
#define _gcammotypeinfo_t_h

#include "../../../scripting.h"

#include "../types/GAmmoFlags_t.h"
#include "GCRangeInt.h"
#include "GCRangeFloat.h"

class GAmmoTypeInfo_t
{
private:
    void *m_ptr;

public:
    GAmmoTypeInfo_t() {}
    GAmmoTypeInfo_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetMaxCarry() const { return GetSchemaValue<int32_t>(m_ptr, "AmmoTypeInfo_t", "m_nMaxCarry"); }
    void SetMaxCarry(int32_t value) { SetSchemaValue(m_ptr, "AmmoTypeInfo_t", "m_nMaxCarry", true, value); }
    GCRangeInt GetSplashSize() const { return GetSchemaValue<GCRangeInt>(m_ptr, "AmmoTypeInfo_t", "m_nSplashSize"); }
    void SetSplashSize(GCRangeInt value) { SetSchemaValue(m_ptr, "AmmoTypeInfo_t", "m_nSplashSize", true, value); }
    AmmoFlags_t GetFlags() const { return GetSchemaValue<AmmoFlags_t>(m_ptr, "AmmoTypeInfo_t", "m_nFlags"); }
    void SetFlags(AmmoFlags_t value) { SetSchemaValue(m_ptr, "AmmoTypeInfo_t", "m_nFlags", true, value); }
    float GetMass() const { return GetSchemaValue<float>(m_ptr, "AmmoTypeInfo_t", "m_flMass"); }
    void SetMass(float value) { SetSchemaValue(m_ptr, "AmmoTypeInfo_t", "m_flMass", true, value); }
    GCRangeFloat GetSpeed() const { return GetSchemaValue<GCRangeFloat>(m_ptr, "AmmoTypeInfo_t", "m_flSpeed"); }
    void SetSpeed(GCRangeFloat value) { SetSchemaValue(m_ptr, "AmmoTypeInfo_t", "m_flSpeed", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif