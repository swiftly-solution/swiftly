class GCPlayerPawnComponent;

#ifndef _gccplayerpawncomponent_h
#define _gccplayerpawncomponent_h

#include "../../../scripting.h"


#include "GCNetworkVarChainer.h"

class GCPlayerPawnComponent
{
private:
    void *m_ptr;

public:
    GCPlayerPawnComponent() {}
    GCPlayerPawnComponent(void *ptr) : m_ptr(ptr) {}

    GCNetworkVarChainer Get__pChainEntity() const { return GetSchemaValue<GCNetworkVarChainer>(m_ptr, "CPlayerPawnComponent", "__m_pChainEntity"); }
    void Set__pChainEntity(GCNetworkVarChainer value) { SetSchemaValue(m_ptr, "CPlayerPawnComponent", "__m_pChainEntity", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif