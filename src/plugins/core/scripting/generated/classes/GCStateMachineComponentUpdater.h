class GCStateMachineComponentUpdater;

#ifndef _gccstatemachinecomponentupdater_h
#define _gccstatemachinecomponentupdater_h

#include "../../../scripting.h"


#include "GCAnimStateMachineUpdater.h"

class GCStateMachineComponentUpdater
{
private:
    void *m_ptr;

public:
    GCStateMachineComponentUpdater() {}
    GCStateMachineComponentUpdater(void *ptr) : m_ptr(ptr) {}

    GCAnimStateMachineUpdater GetStateMachine() const { return GetSchemaValue<GCAnimStateMachineUpdater>(m_ptr, "CStateMachineComponentUpdater", "m_stateMachine"); }
    void SetStateMachine(GCAnimStateMachineUpdater value) { SetSchemaValue(m_ptr, "CStateMachineComponentUpdater", "m_stateMachine", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif