class GCLogicNavigation;

#ifndef _gcclogicnavigation_h
#define _gcclogicnavigation_h

#include "../../../scripting.h"

#include "../types/Gnavproperties_t.h"


class GCLogicNavigation
{
private:
    void *m_ptr;

public:
    GCLogicNavigation() {}
    GCLogicNavigation(void *ptr) : m_ptr(ptr) {}

    bool GetIsOn() const { return GetSchemaValue<bool>(m_ptr, "CLogicNavigation", "m_isOn"); }
    void SetIsOn(bool value) { SetSchemaValue(m_ptr, "CLogicNavigation", "m_isOn", false, value); }
    navproperties_t GetNavProperty() const { return GetSchemaValue<navproperties_t>(m_ptr, "CLogicNavigation", "m_navProperty"); }
    void SetNavProperty(navproperties_t value) { SetSchemaValue(m_ptr, "CLogicNavigation", "m_navProperty", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif