class GRelationshipOverride_t;

#ifndef _gcrelationshipoverride_t_h
#define _gcrelationshipoverride_t_h

#include "../../../scripting.h"

#include "../types/GClass_T.h"
#include "GCBaseEntity.h"

class GRelationshipOverride_t
{
private:
    void *m_ptr;

public:
    GRelationshipOverride_t() {}
    GRelationshipOverride_t(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "RelationshipOverride_t", "entity"); }
    void SetEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Entity' is not possible.\n"); }
    Class_T GetClassType() const { return GetSchemaValue<Class_T>(m_ptr, "RelationshipOverride_t", "classType"); }
    void SetClassType(Class_T value) { SetSchemaValue(m_ptr, "RelationshipOverride_t", "classType", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif