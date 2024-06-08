class GCModelConfigElement_Command;

#ifndef _gccmodelconfigelement_command_h
#define _gccmodelconfigelement_command_h

#include "../../../scripting.h"




class GCModelConfigElement_Command
{
private:
    void *m_ptr;

public:
    GCModelConfigElement_Command() {}
    GCModelConfigElement_Command(void *ptr) : m_ptr(ptr) {}

    CUtlString GetCommand() const { return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_Command", "m_Command"); }
    void SetCommand(CUtlString value) { SetSchemaValue(m_ptr, "CModelConfigElement_Command", "m_Command", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif