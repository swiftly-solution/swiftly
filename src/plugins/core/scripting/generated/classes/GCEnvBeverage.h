class GCEnvBeverage;

#ifndef _gccenvbeverage_h
#define _gccenvbeverage_h

#include "../../../scripting.h"




class GCEnvBeverage
{
private:
    void *m_ptr;

public:
    GCEnvBeverage() {}
    GCEnvBeverage(void *ptr) : m_ptr(ptr) {}

    bool GetCanInDispenser() const { return GetSchemaValue<bool>(m_ptr, "CEnvBeverage", "m_CanInDispenser"); }
    void SetCanInDispenser(bool value) { SetSchemaValue(m_ptr, "CEnvBeverage", "m_CanInDispenser", false, value); }
    int32_t GetBeverageType() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvBeverage", "m_nBeverageType"); }
    void SetBeverageType(int32_t value) { SetSchemaValue(m_ptr, "CEnvBeverage", "m_nBeverageType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif