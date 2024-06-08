class GCPlayerControllerComponent;

#ifndef _gccplayercontrollercomponent_h
#define _gccplayercontrollercomponent_h

#include "../../../scripting.h"


#include "GCNetworkVarChainer.h"

class GCPlayerControllerComponent
{
private:
    void *m_ptr;

public:
    GCPlayerControllerComponent() {}
    GCPlayerControllerComponent(void *ptr) : m_ptr(ptr) {}

    GCNetworkVarChainer Get__pChainEntity() const { return GetSchemaValue<GCNetworkVarChainer>(m_ptr, "CPlayerControllerComponent", "__m_pChainEntity"); }
    void Set__pChainEntity(GCNetworkVarChainer value) { SetSchemaValue(m_ptr, "CPlayerControllerComponent", "__m_pChainEntity", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif