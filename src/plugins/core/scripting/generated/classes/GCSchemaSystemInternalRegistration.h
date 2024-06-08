class GCSchemaSystemInternalRegistration;

#ifndef _gccschemasysteminternalregistration_h
#define _gccschemasysteminternalregistration_h

#include "../../../scripting.h"




class GCSchemaSystemInternalRegistration
{
private:
    void *m_ptr;

public:
    GCSchemaSystemInternalRegistration() {}
    GCSchemaSystemInternalRegistration(void *ptr) : m_ptr(ptr) {}

    Vector2D GetVector2D() const { return GetSchemaValue<Vector2D>(m_ptr, "CSchemaSystemInternalRegistration", "m_Vector2D"); }
    void SetVector2D(Vector2D value) { SetSchemaValue(m_ptr, "CSchemaSystemInternalRegistration", "m_Vector2D", false, value); }
    Vector GetVector() const { return GetSchemaValue<Vector>(m_ptr, "CSchemaSystemInternalRegistration", "m_Vector"); }
    void SetVector(Vector value) { SetSchemaValue(m_ptr, "CSchemaSystemInternalRegistration", "m_Vector", false, value); }
    Vector GetVectorAligned() const { return GetSchemaValue<Vector>(m_ptr, "CSchemaSystemInternalRegistration", "m_VectorAligned"); }
    void SetVectorAligned(Vector value) { SetSchemaValue(m_ptr, "CSchemaSystemInternalRegistration", "m_VectorAligned", false, value); }
    Quaternion GetQuaternion() const { return GetSchemaValue<Quaternion>(m_ptr, "CSchemaSystemInternalRegistration", "m_Quaternion"); }
    void SetQuaternion(Quaternion value) { SetSchemaValue(m_ptr, "CSchemaSystemInternalRegistration", "m_Quaternion", false, value); }
    QAngle GetQAngle() const { return GetSchemaValue<QAngle>(m_ptr, "CSchemaSystemInternalRegistration", "m_QAngle"); }
    void SetQAngle(QAngle value) { SetSchemaValue(m_ptr, "CSchemaSystemInternalRegistration", "m_QAngle", false, value); }
    Vector GetRotationVector() const { return GetSchemaValue<Vector>(m_ptr, "CSchemaSystemInternalRegistration", "m_RotationVector"); }
    void SetRotationVector(Vector value) { SetSchemaValue(m_ptr, "CSchemaSystemInternalRegistration", "m_RotationVector", false, value); }
    RadianEuler GetRadianEuler() const { return GetSchemaValue<RadianEuler>(m_ptr, "CSchemaSystemInternalRegistration", "m_RadianEuler"); }
    void SetRadianEuler(RadianEuler value) { SetSchemaValue(m_ptr, "CSchemaSystemInternalRegistration", "m_RadianEuler", false, value); }
    matrix3x4_t GetMatrix3x4_t() const { return GetSchemaValue<matrix3x4_t>(m_ptr, "CSchemaSystemInternalRegistration", "m_matrix3x4_t"); }
    void SetMatrix3x4_t(matrix3x4_t value) { SetSchemaValue(m_ptr, "CSchemaSystemInternalRegistration", "m_matrix3x4_t", false, value); }
    matrix3x4a_t GetMatrix3x4a_t() const { return GetSchemaValue<matrix3x4a_t>(m_ptr, "CSchemaSystemInternalRegistration", "m_matrix3x4a_t"); }
    void SetMatrix3x4a_t(matrix3x4a_t value) { SetSchemaValue(m_ptr, "CSchemaSystemInternalRegistration", "m_matrix3x4a_t", false, value); }
    Color GetColor() const { return GetSchemaValue<Color>(m_ptr, "CSchemaSystemInternalRegistration", "m_Color"); }
    void SetColor(Color value) { SetSchemaValue(m_ptr, "CSchemaSystemInternalRegistration", "m_Color", false, value); }
    Vector4D GetVector4D() const { return GetSchemaValue<Vector4D>(m_ptr, "CSchemaSystemInternalRegistration", "m_Vector4D"); }
    void SetVector4D(Vector4D value) { SetSchemaValue(m_ptr, "CSchemaSystemInternalRegistration", "m_Vector4D", false, value); }
    KeyValues* GetKeyValues() const { return GetSchemaValue<KeyValues*>(m_ptr, "CSchemaSystemInternalRegistration", "m_pKeyValues"); }
    void SetKeyValues(KeyValues* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'KeyValues' is not possible.\n"); }
    CUtlString GetCUtlString() const { return GetSchemaValue<CUtlString>(m_ptr, "CSchemaSystemInternalRegistration", "m_CUtlString"); }
    void SetCUtlString(CUtlString value) { SetSchemaValue(m_ptr, "CSchemaSystemInternalRegistration", "m_CUtlString", false, value); }
    CUtlSymbol GetCUtlSymbol() const { return GetSchemaValue<CUtlSymbol>(m_ptr, "CSchemaSystemInternalRegistration", "m_CUtlSymbol"); }
    void SetCUtlSymbol(CUtlSymbol value) { SetSchemaValue(m_ptr, "CSchemaSystemInternalRegistration", "m_CUtlSymbol", false, value); }
    CUtlStringToken GetStringToken() const { return GetSchemaValue<CUtlStringToken>(m_ptr, "CSchemaSystemInternalRegistration", "m_stringToken"); }
    void SetStringToken(CUtlStringToken value) { SetSchemaValue(m_ptr, "CSchemaSystemInternalRegistration", "m_stringToken", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif