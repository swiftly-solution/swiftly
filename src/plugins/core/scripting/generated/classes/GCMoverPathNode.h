class GCMoverPathNode;

#ifndef _gccmoverpathnode_h
#define _gccmoverpathnode_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"
#include "GCPathMover.h"

class GCMoverPathNode
{
private:
    void *m_ptr;

public:
    GCMoverPathNode() {}
    GCMoverPathNode(void *ptr) : m_ptr(ptr) {}

    Vector GetInTangentLocal() const { return GetSchemaValue<Vector>(m_ptr, "CMoverPathNode", "m_vInTangentLocal"); }
    void SetInTangentLocal(Vector value) { SetSchemaValue(m_ptr, "CMoverPathNode", "m_vInTangentLocal", false, value); }
    Vector GetOutTangentLocal() const { return GetSchemaValue<Vector>(m_ptr, "CMoverPathNode", "m_vOutTangentLocal"); }
    void SetOutTangentLocal(Vector value) { SetSchemaValue(m_ptr, "CMoverPathNode", "m_vOutTangentLocal", false, value); }
    CUtlSymbolLarge GetParentPathUniqueID() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CMoverPathNode", "m_szParentPathUniqueID"); }
    void SetParentPathUniqueID(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CMoverPathNode", "m_szParentPathUniqueID", false, value); }
    GCEntityIOOutput GetOnPassThrough() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CMoverPathNode", "m_OnPassThrough"); }
    void SetOnPassThrough(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CMoverPathNode", "m_OnPassThrough", false, value); }
    GCPathMover* GetMover() const { return GetSchemaValue<GCPathMover*>(m_ptr, "CMoverPathNode", "m_hMover"); }
    void SetMover(GCPathMover* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Mover' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif