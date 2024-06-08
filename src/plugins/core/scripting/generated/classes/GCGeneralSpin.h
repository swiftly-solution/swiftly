class GCGeneralSpin;

#ifndef _gccgeneralspin_h
#define _gccgeneralspin_h

#include "../../../scripting.h"




class GCGeneralSpin
{
private:
    void *m_ptr;

public:
    GCGeneralSpin() {}
    GCGeneralSpin(void *ptr) : m_ptr(ptr) {}

    int32_t GetSpinRateDegrees() const { return GetSchemaValue<int32_t>(m_ptr, "CGeneralSpin", "m_nSpinRateDegrees"); }
    void SetSpinRateDegrees(int32_t value) { SetSchemaValue(m_ptr, "CGeneralSpin", "m_nSpinRateDegrees", false, value); }
    int32_t GetSpinRateMinDegrees() const { return GetSchemaValue<int32_t>(m_ptr, "CGeneralSpin", "m_nSpinRateMinDegrees"); }
    void SetSpinRateMinDegrees(int32_t value) { SetSchemaValue(m_ptr, "CGeneralSpin", "m_nSpinRateMinDegrees", false, value); }
    float GetSpinRateStopTime() const { return GetSchemaValue<float>(m_ptr, "CGeneralSpin", "m_fSpinRateStopTime"); }
    void SetSpinRateStopTime(float value) { SetSchemaValue(m_ptr, "CGeneralSpin", "m_fSpinRateStopTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif