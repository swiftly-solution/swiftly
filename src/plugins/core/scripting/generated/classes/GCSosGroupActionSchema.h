class GCSosGroupActionSchema;

#ifndef _gccsosgroupactionschema_h
#define _gccsosgroupactionschema_h

#include "../../../scripting.h"

#include "../types/GActionType_t.h"


class GCSosGroupActionSchema
{
private:
    void *m_ptr;

public:
    GCSosGroupActionSchema() {}
    GCSosGroupActionSchema(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSchema", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "CSosGroupActionSchema", "m_name", false, value); }
    ActionType_t GetActionType() const { return GetSchemaValue<ActionType_t>(m_ptr, "CSosGroupActionSchema", "m_actionType"); }
    void SetActionType(ActionType_t value) { SetSchemaValue(m_ptr, "CSosGroupActionSchema", "m_actionType", false, value); }
    ActionType_t GetActionInstanceType() const { return GetSchemaValue<ActionType_t>(m_ptr, "CSosGroupActionSchema", "m_actionInstanceType"); }
    void SetActionInstanceType(ActionType_t value) { SetSchemaValue(m_ptr, "CSosGroupActionSchema", "m_actionInstanceType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif