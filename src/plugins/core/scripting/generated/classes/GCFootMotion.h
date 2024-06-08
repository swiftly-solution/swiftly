class GCFootMotion;

#ifndef _gccfootmotion_h
#define _gccfootmotion_h

#include "../../../scripting.h"


#include "GCFootStride.h"

class GCFootMotion
{
private:
    void *m_ptr;

public:
    GCFootMotion() {}
    GCFootMotion(void *ptr) : m_ptr(ptr) {}

    std::vector<GCFootStride> GetStrides() const { CUtlVector<GCFootStride>* vec = GetSchemaValue<CUtlVector<GCFootStride>*>(m_ptr, "CFootMotion", "m_strides"); std::vector<GCFootStride> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetStrides(std::vector<GCFootStride> value) { SetSchemaValueCUtlVector<GCFootStride>(m_ptr, "CFootMotion", "m_strides", false, value); }
    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CFootMotion", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "CFootMotion", "m_name", false, value); }
    bool GetAdditive() const { return GetSchemaValue<bool>(m_ptr, "CFootMotion", "m_bAdditive"); }
    void SetAdditive(bool value) { SetSchemaValue(m_ptr, "CFootMotion", "m_bAdditive", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif