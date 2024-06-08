class GNodeData_t;

#ifndef _gcnodedata_t_h
#define _gcnodedata_t_h

#include "../../../scripting.h"




class GNodeData_t
{
private:
    void *m_ptr;

public:
    GNodeData_t() {}
    GNodeData_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetParent() const { return GetSchemaValue<int32_t>(m_ptr, "NodeData_t", "m_nParent"); }
    void SetParent(int32_t value) { SetSchemaValue(m_ptr, "NodeData_t", "m_nParent", true, value); }
    Vector GetOrigin() const { return GetSchemaValue<Vector>(m_ptr, "NodeData_t", "m_vOrigin"); }
    void SetOrigin(Vector value) { SetSchemaValue(m_ptr, "NodeData_t", "m_vOrigin", true, value); }
    Vector GetMinBounds() const { return GetSchemaValue<Vector>(m_ptr, "NodeData_t", "m_vMinBounds"); }
    void SetMinBounds(Vector value) { SetSchemaValue(m_ptr, "NodeData_t", "m_vMinBounds", true, value); }
    Vector GetMaxBounds() const { return GetSchemaValue<Vector>(m_ptr, "NodeData_t", "m_vMaxBounds"); }
    void SetMaxBounds(Vector value) { SetSchemaValue(m_ptr, "NodeData_t", "m_vMaxBounds", true, value); }
    float GetMinimumDistance() const { return GetSchemaValue<float>(m_ptr, "NodeData_t", "m_flMinimumDistance"); }
    void SetMinimumDistance(float value) { SetSchemaValue(m_ptr, "NodeData_t", "m_flMinimumDistance", true, value); }
    std::vector<int32> GetChildNodeIndices() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "NodeData_t", "m_ChildNodeIndices"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetChildNodeIndices(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "NodeData_t", "m_ChildNodeIndices", true, value); }
    CUtlString GetWorldNodePrefix() const { return GetSchemaValue<CUtlString>(m_ptr, "NodeData_t", "m_worldNodePrefix"); }
    void SetWorldNodePrefix(CUtlString value) { SetSchemaValue(m_ptr, "NodeData_t", "m_worldNodePrefix", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif