class GCAnimUpdateNodeBase;

#ifndef _gccanimupdatenodebase_h
#define _gccanimupdatenodebase_h

#include "../../../scripting.h"

#include "../types/GAnimNodeNetworkMode.h"
#include "GCAnimNodePath.h"

class GCAnimUpdateNodeBase
{
private:
    void *m_ptr;

public:
    GCAnimUpdateNodeBase() {}
    GCAnimUpdateNodeBase(void *ptr) : m_ptr(ptr) {}

    GCAnimNodePath GetNodePath() const { return GetSchemaValue<GCAnimNodePath>(m_ptr, "CAnimUpdateNodeBase", "m_nodePath"); }
    void SetNodePath(GCAnimNodePath value) { SetSchemaValue(m_ptr, "CAnimUpdateNodeBase", "m_nodePath", false, value); }
    AnimNodeNetworkMode GetNetworkMode() const { return GetSchemaValue<AnimNodeNetworkMode>(m_ptr, "CAnimUpdateNodeBase", "m_networkMode"); }
    void SetNetworkMode(AnimNodeNetworkMode value) { SetSchemaValue(m_ptr, "CAnimUpdateNodeBase", "m_networkMode", false, value); }
    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CAnimUpdateNodeBase", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "CAnimUpdateNodeBase", "m_name", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif