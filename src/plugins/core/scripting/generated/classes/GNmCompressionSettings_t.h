class GNmCompressionSettings_t;

#ifndef _gcnmcompressionsettings_t_h
#define _gcnmcompressionsettings_t_h

#include "../../../scripting.h"


#include "GNmCompressionSettings_t.h"

class GNmCompressionSettings_t
{
private:
    void *m_ptr;

public:
    GNmCompressionSettings_t() {}
    GNmCompressionSettings_t(void *ptr) : m_ptr(ptr) {}

    GNmCompressionSettings_t GetTranslationRangeX() const { return GetSchemaValue<GNmCompressionSettings_t>(m_ptr, "NmCompressionSettings_t", "m_translationRangeX"); }
    void SetTranslationRangeX(GNmCompressionSettings_t value) { SetSchemaValue(m_ptr, "NmCompressionSettings_t", "m_translationRangeX", true, value); }
    GNmCompressionSettings_t GetTranslationRangeY() const { return GetSchemaValue<GNmCompressionSettings_t>(m_ptr, "NmCompressionSettings_t", "m_translationRangeY"); }
    void SetTranslationRangeY(GNmCompressionSettings_t value) { SetSchemaValue(m_ptr, "NmCompressionSettings_t", "m_translationRangeY", true, value); }
    GNmCompressionSettings_t GetTranslationRangeZ() const { return GetSchemaValue<GNmCompressionSettings_t>(m_ptr, "NmCompressionSettings_t", "m_translationRangeZ"); }
    void SetTranslationRangeZ(GNmCompressionSettings_t value) { SetSchemaValue(m_ptr, "NmCompressionSettings_t", "m_translationRangeZ", true, value); }
    GNmCompressionSettings_t GetScaleRange() const { return GetSchemaValue<GNmCompressionSettings_t>(m_ptr, "NmCompressionSettings_t", "m_scaleRange"); }
    void SetScaleRange(GNmCompressionSettings_t value) { SetSchemaValue(m_ptr, "NmCompressionSettings_t", "m_scaleRange", true, value); }
    Quaternion GetConstantRotation() const { return GetSchemaValue<Quaternion>(m_ptr, "NmCompressionSettings_t", "m_constantRotation"); }
    void SetConstantRotation(Quaternion value) { SetSchemaValue(m_ptr, "NmCompressionSettings_t", "m_constantRotation", true, value); }
    bool GetIsRotationStatic() const { return GetSchemaValue<bool>(m_ptr, "NmCompressionSettings_t", "m_bIsRotationStatic"); }
    void SetIsRotationStatic(bool value) { SetSchemaValue(m_ptr, "NmCompressionSettings_t", "m_bIsRotationStatic", true, value); }
    bool GetIsTranslationStatic() const { return GetSchemaValue<bool>(m_ptr, "NmCompressionSettings_t", "m_bIsTranslationStatic"); }
    void SetIsTranslationStatic(bool value) { SetSchemaValue(m_ptr, "NmCompressionSettings_t", "m_bIsTranslationStatic", true, value); }
    bool GetIsScaleStatic() const { return GetSchemaValue<bool>(m_ptr, "NmCompressionSettings_t", "m_bIsScaleStatic"); }
    void SetIsScaleStatic(bool value) { SetSchemaValue(m_ptr, "NmCompressionSettings_t", "m_bIsScaleStatic", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif