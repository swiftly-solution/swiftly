class GCLogicLineToEntity;

#ifndef _gcclogiclinetoentity_h
#define _gcclogiclinetoentity_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCLogicLineToEntity
{
private:
    void *m_ptr;

public:
    GCLogicLineToEntity() {}
    GCLogicLineToEntity(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetSourceName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicLineToEntity", "m_SourceName"); }
    void SetSourceName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CLogicLineToEntity", "m_SourceName", false, value); }
    GCBaseEntity* GetStartEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CLogicLineToEntity", "m_StartEntity"); }
    void SetStartEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'StartEntity' is not possible.\n"); }
    GCBaseEntity* GetEndEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CLogicLineToEntity", "m_EndEntity"); }
    void SetEndEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'EndEntity' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif