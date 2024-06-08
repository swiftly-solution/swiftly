class GFootFixedData_t;

#ifndef _gcfootfixeddata_t_h
#define _gcfootfixeddata_t_h

#include "../../../scripting.h"




class GFootFixedData_t
{
private:
    void *m_ptr;

public:
    GFootFixedData_t() {}
    GFootFixedData_t(void *ptr) : m_ptr(ptr) {}

    Vector GetToeOffset() const { return GetSchemaValue<Vector>(m_ptr, "FootFixedData_t", "m_vToeOffset"); }
    void SetToeOffset(Vector value) { SetSchemaValue(m_ptr, "FootFixedData_t", "m_vToeOffset", true, value); }
    Vector GetHeelOffset() const { return GetSchemaValue<Vector>(m_ptr, "FootFixedData_t", "m_vHeelOffset"); }
    void SetHeelOffset(Vector value) { SetSchemaValue(m_ptr, "FootFixedData_t", "m_vHeelOffset", true, value); }
    int32_t GetTargetBoneIndex() const { return GetSchemaValue<int32_t>(m_ptr, "FootFixedData_t", "m_nTargetBoneIndex"); }
    void SetTargetBoneIndex(int32_t value) { SetSchemaValue(m_ptr, "FootFixedData_t", "m_nTargetBoneIndex", true, value); }
    int32_t GetAnkleBoneIndex() const { return GetSchemaValue<int32_t>(m_ptr, "FootFixedData_t", "m_nAnkleBoneIndex"); }
    void SetAnkleBoneIndex(int32_t value) { SetSchemaValue(m_ptr, "FootFixedData_t", "m_nAnkleBoneIndex", true, value); }
    int32_t GetIKAnchorBoneIndex() const { return GetSchemaValue<int32_t>(m_ptr, "FootFixedData_t", "m_nIKAnchorBoneIndex"); }
    void SetIKAnchorBoneIndex(int32_t value) { SetSchemaValue(m_ptr, "FootFixedData_t", "m_nIKAnchorBoneIndex", true, value); }
    int32_t GetIkChainIndex() const { return GetSchemaValue<int32_t>(m_ptr, "FootFixedData_t", "m_ikChainIndex"); }
    void SetIkChainIndex(int32_t value) { SetSchemaValue(m_ptr, "FootFixedData_t", "m_ikChainIndex", true, value); }
    float GetMaxIKLength() const { return GetSchemaValue<float>(m_ptr, "FootFixedData_t", "m_flMaxIKLength"); }
    void SetMaxIKLength(float value) { SetSchemaValue(m_ptr, "FootFixedData_t", "m_flMaxIKLength", true, value); }
    int32_t GetFootIndex() const { return GetSchemaValue<int32_t>(m_ptr, "FootFixedData_t", "m_nFootIndex"); }
    void SetFootIndex(int32_t value) { SetSchemaValue(m_ptr, "FootFixedData_t", "m_nFootIndex", true, value); }
    int32_t GetTagIndex() const { return GetSchemaValue<int32_t>(m_ptr, "FootFixedData_t", "m_nTagIndex"); }
    void SetTagIndex(int32_t value) { SetSchemaValue(m_ptr, "FootFixedData_t", "m_nTagIndex", true, value); }
    float GetMaxRotationLeft() const { return GetSchemaValue<float>(m_ptr, "FootFixedData_t", "m_flMaxRotationLeft"); }
    void SetMaxRotationLeft(float value) { SetSchemaValue(m_ptr, "FootFixedData_t", "m_flMaxRotationLeft", true, value); }
    float GetMaxRotationRight() const { return GetSchemaValue<float>(m_ptr, "FootFixedData_t", "m_flMaxRotationRight"); }
    void SetMaxRotationRight(float value) { SetSchemaValue(m_ptr, "FootFixedData_t", "m_flMaxRotationRight", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif