class GCAnimDataChannelDesc;

#ifndef _gccanimdatachanneldesc_h
#define _gccanimdatachanneldesc_h

#include "../../../scripting.h"




class GCAnimDataChannelDesc
{
private:
    void *m_ptr;

public:
    GCAnimDataChannelDesc() {}
    GCAnimDataChannelDesc(void *ptr) : m_ptr(ptr) {}

    CBufferString GetChannelClass() const { return GetSchemaValue<CBufferString>(m_ptr, "CAnimDataChannelDesc", "m_szChannelClass"); }
    void SetChannelClass(CBufferString value) { SetSchemaValue(m_ptr, "CAnimDataChannelDesc", "m_szChannelClass", false, value); }
    CBufferString GetVariableName() const { return GetSchemaValue<CBufferString>(m_ptr, "CAnimDataChannelDesc", "m_szVariableName"); }
    void SetVariableName(CBufferString value) { SetSchemaValue(m_ptr, "CAnimDataChannelDesc", "m_szVariableName", false, value); }
    int32_t GetFlags() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimDataChannelDesc", "m_nFlags"); }
    void SetFlags(int32_t value) { SetSchemaValue(m_ptr, "CAnimDataChannelDesc", "m_nFlags", false, value); }
    int32_t GetType() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimDataChannelDesc", "m_nType"); }
    void SetType(int32_t value) { SetSchemaValue(m_ptr, "CAnimDataChannelDesc", "m_nType", false, value); }
    CBufferString GetGrouping() const { return GetSchemaValue<CBufferString>(m_ptr, "CAnimDataChannelDesc", "m_szGrouping"); }
    void SetGrouping(CBufferString value) { SetSchemaValue(m_ptr, "CAnimDataChannelDesc", "m_szGrouping", false, value); }
    CBufferString GetDescription() const { return GetSchemaValue<CBufferString>(m_ptr, "CAnimDataChannelDesc", "m_szDescription"); }
    void SetDescription(CBufferString value) { SetSchemaValue(m_ptr, "CAnimDataChannelDesc", "m_szDescription", false, value); }
    std::vector<CBufferString> GetElementNameArray() const { CUtlVector<CBufferString>* vec = GetSchemaValue<CUtlVector<CBufferString>*>(m_ptr, "CAnimDataChannelDesc", "m_szElementNameArray"); std::vector<CBufferString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetElementNameArray(std::vector<CBufferString> value) { SetSchemaValueCUtlVector<CBufferString>(m_ptr, "CAnimDataChannelDesc", "m_szElementNameArray", false, value); }
    std::vector<int32> GetElementIndexArray() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CAnimDataChannelDesc", "m_nElementIndexArray"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetElementIndexArray(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "CAnimDataChannelDesc", "m_nElementIndexArray", false, value); }
    std::vector<uint32> GetElementMaskArray() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CAnimDataChannelDesc", "m_nElementMaskArray"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetElementMaskArray(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "CAnimDataChannelDesc", "m_nElementMaskArray", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif