class GCCredits;

#ifndef _gcccredits_h
#define _gcccredits_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCCredits
{
private:
    void *m_ptr;

public:
    GCCredits() {}
    GCCredits(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnCreditsDone() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CCredits", "m_OnCreditsDone"); }
    void SetOnCreditsDone(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CCredits", "m_OnCreditsDone", false, value); }
    bool GetRolledOutroCredits() const { return GetSchemaValue<bool>(m_ptr, "CCredits", "m_bRolledOutroCredits"); }
    void SetRolledOutroCredits(bool value) { SetSchemaValue(m_ptr, "CCredits", "m_bRolledOutroCredits", false, value); }
    float GetLogoLength() const { return GetSchemaValue<float>(m_ptr, "CCredits", "m_flLogoLength"); }
    void SetLogoLength(float value) { SetSchemaValue(m_ptr, "CCredits", "m_flLogoLength", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif