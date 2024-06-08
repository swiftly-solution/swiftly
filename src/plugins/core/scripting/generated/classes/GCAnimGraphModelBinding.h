class GCAnimGraphModelBinding;

#ifndef _gccanimgraphmodelbinding_h
#define _gccanimgraphmodelbinding_h

#include "../../../scripting.h"




class GCAnimGraphModelBinding
{
private:
    void *m_ptr;

public:
    GCAnimGraphModelBinding() {}
    GCAnimGraphModelBinding(void *ptr) : m_ptr(ptr) {}

    CUtlString GetModelName() const { return GetSchemaValue<CUtlString>(m_ptr, "CAnimGraphModelBinding", "m_modelName"); }
    void SetModelName(CUtlString value) { SetSchemaValue(m_ptr, "CAnimGraphModelBinding", "m_modelName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif