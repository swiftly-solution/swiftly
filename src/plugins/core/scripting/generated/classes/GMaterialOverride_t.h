class GMaterialOverride_t;

#ifndef _gcmaterialoverride_t_h
#define _gcmaterialoverride_t_h

#include "../../../scripting.h"




class GMaterialOverride_t
{
private:
    void *m_ptr;

public:
    GMaterialOverride_t() {}
    GMaterialOverride_t(void *ptr) : m_ptr(ptr) {}

    uint32_t GetSubSceneObject() const { return GetSchemaValue<uint32_t>(m_ptr, "MaterialOverride_t", "m_nSubSceneObject"); }
    void SetSubSceneObject(uint32_t value) { SetSchemaValue(m_ptr, "MaterialOverride_t", "m_nSubSceneObject", true, value); }
    uint32_t GetDrawCallIndex() const { return GetSchemaValue<uint32_t>(m_ptr, "MaterialOverride_t", "m_nDrawCallIndex"); }
    void SetDrawCallIndex(uint32_t value) { SetSchemaValue(m_ptr, "MaterialOverride_t", "m_nDrawCallIndex", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif