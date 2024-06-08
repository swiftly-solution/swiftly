class GWorldNodeOnDiskBufferData_t;

#ifndef _gcworldnodeondiskbufferdata_t_h
#define _gcworldnodeondiskbufferdata_t_h

#include "../../../scripting.h"


#include "GRenderInputLayoutField_t.h"

class GWorldNodeOnDiskBufferData_t
{
private:
    void *m_ptr;

public:
    GWorldNodeOnDiskBufferData_t() {}
    GWorldNodeOnDiskBufferData_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetElementCount() const { return GetSchemaValue<int32_t>(m_ptr, "WorldNodeOnDiskBufferData_t", "m_nElementCount"); }
    void SetElementCount(int32_t value) { SetSchemaValue(m_ptr, "WorldNodeOnDiskBufferData_t", "m_nElementCount", true, value); }
    int32_t GetElementSizeInBytes() const { return GetSchemaValue<int32_t>(m_ptr, "WorldNodeOnDiskBufferData_t", "m_nElementSizeInBytes"); }
    void SetElementSizeInBytes(int32_t value) { SetSchemaValue(m_ptr, "WorldNodeOnDiskBufferData_t", "m_nElementSizeInBytes", true, value); }
    std::vector<GRenderInputLayoutField_t> GetInputLayoutFields() const { CUtlVector<GRenderInputLayoutField_t>* vec = GetSchemaValue<CUtlVector<GRenderInputLayoutField_t>*>(m_ptr, "WorldNodeOnDiskBufferData_t", "m_inputLayoutFields"); std::vector<GRenderInputLayoutField_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetInputLayoutFields(std::vector<GRenderInputLayoutField_t> value) { SetSchemaValueCUtlVector<GRenderInputLayoutField_t>(m_ptr, "WorldNodeOnDiskBufferData_t", "m_inputLayoutFields", true, value); }
    std::vector<uint8> GetData() const { CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "WorldNodeOnDiskBufferData_t", "m_pData"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetData(std::vector<uint8> value) { SetSchemaValueCUtlVector<uint8>(m_ptr, "WorldNodeOnDiskBufferData_t", "m_pData", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif