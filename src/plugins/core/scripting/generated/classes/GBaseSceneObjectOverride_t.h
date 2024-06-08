class GBaseSceneObjectOverride_t;

#ifndef _gcbasesceneobjectoverride_t_h
#define _gcbasesceneobjectoverride_t_h

#include "../../../scripting.h"




class GBaseSceneObjectOverride_t
{
private:
    void *m_ptr;

public:
    GBaseSceneObjectOverride_t() {}
    GBaseSceneObjectOverride_t(void *ptr) : m_ptr(ptr) {}

    uint32_t GetSceneObjectIndex() const { return GetSchemaValue<uint32_t>(m_ptr, "BaseSceneObjectOverride_t", "m_nSceneObjectIndex"); }
    void SetSceneObjectIndex(uint32_t value) { SetSchemaValue(m_ptr, "BaseSceneObjectOverride_t", "m_nSceneObjectIndex", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif