class GAggregateLODSetup_t;

#ifndef _gcaggregatelodsetup_t_h
#define _gcaggregatelodsetup_t_h

#include "../../../scripting.h"




class GAggregateLODSetup_t
{
private:
    void *m_ptr;

public:
    GAggregateLODSetup_t() {}
    GAggregateLODSetup_t(void *ptr) : m_ptr(ptr) {}

    Vector GetLODOrigin() const { return GetSchemaValue<Vector>(m_ptr, "AggregateLODSetup_t", "m_vLODOrigin"); }
    void SetLODOrigin(Vector value) { SetSchemaValue(m_ptr, "AggregateLODSetup_t", "m_vLODOrigin", true, value); }
    float GetMaxObjectScale() const { return GetSchemaValue<float>(m_ptr, "AggregateLODSetup_t", "m_fMaxObjectScale"); }
    void SetMaxObjectScale(float value) { SetSchemaValue(m_ptr, "AggregateLODSetup_t", "m_fMaxObjectScale", true, value); }
    std::vector<float32> GetSwitchDistances() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "AggregateLODSetup_t", "m_fSwitchDistances"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSwitchDistances(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "AggregateLODSetup_t", "m_fSwitchDistances", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif