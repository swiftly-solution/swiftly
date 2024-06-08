class Gmagnetted_objects_t;

#ifndef _gcmagnetted_objects_t_h
#define _gcmagnetted_objects_t_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class Gmagnetted_objects_t
{
private:
    void *m_ptr;

public:
    Gmagnetted_objects_t() {}
    Gmagnetted_objects_t(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "magnetted_objects_t", "hEntity"); }
    void SetEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Entity' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif