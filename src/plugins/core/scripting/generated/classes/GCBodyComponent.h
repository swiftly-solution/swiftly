class GCBodyComponent;

#ifndef _gccbodycomponent_h
#define _gccbodycomponent_h

#include "../../../scripting.h"


#include "GCGameSceneNode.h"
#include "GCNetworkVarChainer.h"

class GCBodyComponent
{
private:
    void *m_ptr;

public:
    GCBodyComponent() {}
    GCBodyComponent(void *ptr) : m_ptr(ptr) {}

    GCGameSceneNode* GetSceneNode() const { return GetSchemaValue<GCGameSceneNode*>(m_ptr, "CBodyComponent", "m_pSceneNode"); }
    void SetSceneNode(GCGameSceneNode* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'SceneNode' is not possible.\n"); }
    GCNetworkVarChainer Get__pChainEntity() const { return GetSchemaValue<GCNetworkVarChainer>(m_ptr, "CBodyComponent", "__m_pChainEntity"); }
    void Set__pChainEntity(GCNetworkVarChainer value) { SetSchemaValue(m_ptr, "CBodyComponent", "__m_pChainEntity", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif