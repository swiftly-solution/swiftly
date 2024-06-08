class GCNetworkTransmitComponent;

#ifndef _gccnetworktransmitcomponent_h
#define _gccnetworktransmitcomponent_h

#include "../../../scripting.h"




class GCNetworkTransmitComponent
{
private:
    void *m_ptr;

public:
    GCNetworkTransmitComponent() {}
    GCNetworkTransmitComponent(void *ptr) : m_ptr(ptr) {}

    uint8_t GetTransmitStateOwnedCounter() const { return GetSchemaValue<uint8_t>(m_ptr, "CNetworkTransmitComponent", "m_nTransmitStateOwnedCounter"); }
    void SetTransmitStateOwnedCounter(uint8_t value) { SetSchemaValue(m_ptr, "CNetworkTransmitComponent", "m_nTransmitStateOwnedCounter", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif