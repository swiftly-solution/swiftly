class GCRandomNumberGeneratorParameters;

#ifndef _gccrandomnumbergeneratorparameters_h
#define _gccrandomnumbergeneratorparameters_h

#include "../../../scripting.h"




class GCRandomNumberGeneratorParameters
{
private:
    void *m_ptr;

public:
    GCRandomNumberGeneratorParameters() {}
    GCRandomNumberGeneratorParameters(void *ptr) : m_ptr(ptr) {}

    bool GetDistributeEvenly() const { return GetSchemaValue<bool>(m_ptr, "CRandomNumberGeneratorParameters", "m_bDistributeEvenly"); }
    void SetDistributeEvenly(bool value) { SetSchemaValue(m_ptr, "CRandomNumberGeneratorParameters", "m_bDistributeEvenly", false, value); }
    int32_t GetSeed() const { return GetSchemaValue<int32_t>(m_ptr, "CRandomNumberGeneratorParameters", "m_nSeed"); }
    void SetSeed(int32_t value) { SetSchemaValue(m_ptr, "CRandomNumberGeneratorParameters", "m_nSeed", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif