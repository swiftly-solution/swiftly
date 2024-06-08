class GNmCompressionSettings_t__QuantizationRange_t;

#ifndef _gcnmcompressionsettings_t__quantizationrange_t_h
#define _gcnmcompressionsettings_t__quantizationrange_t_h

#include "../../../scripting.h"




class GNmCompressionSettings_t__QuantizationRange_t
{
private:
    void *m_ptr;

public:
    GNmCompressionSettings_t__QuantizationRange_t() {}
    GNmCompressionSettings_t__QuantizationRange_t(void *ptr) : m_ptr(ptr) {}

    float GetRangeStart() const { return GetSchemaValue<float>(m_ptr, "NmCompressionSettings_t__QuantizationRange_t", "m_flRangeStart"); }
    void SetRangeStart(float value) { SetSchemaValue(m_ptr, "NmCompressionSettings_t__QuantizationRange_t", "m_flRangeStart", true, value); }
    float GetRangeLength() const { return GetSchemaValue<float>(m_ptr, "NmCompressionSettings_t__QuantizationRange_t", "m_flRangeLength"); }
    void SetRangeLength(float value) { SetSchemaValue(m_ptr, "NmCompressionSettings_t__QuantizationRange_t", "m_flRangeLength", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif