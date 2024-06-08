class GManifestTestResource_t;

#ifndef _gcmanifesttestresource_t_h
#define _gcmanifesttestresource_t_h

#include "../../../scripting.h"




class GManifestTestResource_t
{
private:
    void *m_ptr;

public:
    GManifestTestResource_t() {}
    GManifestTestResource_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "ManifestTestResource_t", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "ManifestTestResource_t", "m_name", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif