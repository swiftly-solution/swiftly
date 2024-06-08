class GCGameChoreoServices;

#ifndef _gccgamechoreoservices_h
#define _gccgamechoreoservices_h

#include "../../../scripting.h"


#include "GCBaseAnimGraph.h"
#include "GCScriptedSequence.h"
#include "GIChoreoServices.h"

class GCGameChoreoServices
{
private:
    void *m_ptr;

public:
    GCGameChoreoServices() {}
    GCGameChoreoServices(void *ptr) : m_ptr(ptr) {}

    GCBaseAnimGraph* GetOwner() const { return GetSchemaValue<GCBaseAnimGraph*>(m_ptr, "CGameChoreoServices", "m_hOwner"); }
    void SetOwner(GCBaseAnimGraph* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Owner' is not possible.\n"); }
    GCScriptedSequence* GetScriptedSequence() const { return GetSchemaValue<GCScriptedSequence*>(m_ptr, "CGameChoreoServices", "m_hScriptedSequence"); }
    void SetScriptedSequence(GCScriptedSequence* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ScriptedSequence' is not possible.\n"); }
    GIChoreoServices GetScriptState() const { return GetSchemaValue<GIChoreoServices>(m_ptr, "CGameChoreoServices", "m_scriptState"); }
    void SetScriptState(GIChoreoServices value) { SetSchemaValue(m_ptr, "CGameChoreoServices", "m_scriptState", false, value); }
    GIChoreoServices GetChoreoState() const { return GetSchemaValue<GIChoreoServices>(m_ptr, "CGameChoreoServices", "m_choreoState"); }
    void SetChoreoState(GIChoreoServices value) { SetSchemaValue(m_ptr, "CGameChoreoServices", "m_choreoState", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif