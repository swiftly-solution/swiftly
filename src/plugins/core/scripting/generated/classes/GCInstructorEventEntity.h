class GCInstructorEventEntity;

#ifndef _gccinstructorevententity_h
#define _gccinstructorevententity_h

#include "../../../scripting.h"


#include "GCBasePlayerPawn.h"

class GCInstructorEventEntity
{
private:
    void *m_ptr;

public:
    GCInstructorEventEntity() {}
    GCInstructorEventEntity(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInstructorEventEntity", "m_iszName"); }
    void SetName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CInstructorEventEntity", "m_iszName", false, value); }
    CUtlSymbolLarge GetHintTargetEntity() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInstructorEventEntity", "m_iszHintTargetEntity"); }
    void SetHintTargetEntity(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CInstructorEventEntity", "m_iszHintTargetEntity", false, value); }
    GCBasePlayerPawn* GetTargetPlayer() const { return GetSchemaValue<GCBasePlayerPawn*>(m_ptr, "CInstructorEventEntity", "m_hTargetPlayer"); }
    void SetTargetPlayer(GCBasePlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetPlayer' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif