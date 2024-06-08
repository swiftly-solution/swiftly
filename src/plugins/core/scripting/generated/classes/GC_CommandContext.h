class GC_CommandContext;

#ifndef _gcc_commandcontext_h
#define _gcc_commandcontext_h

#include "../../../scripting.h"




class GC_CommandContext
{
private:
    void *m_ptr;

public:
    GC_CommandContext() {}
    GC_CommandContext(void *ptr) : m_ptr(ptr) {}

    bool GetNeedsprocessing() const { return GetSchemaValue<bool>(m_ptr, "C_CommandContext", "needsprocessing"); }
    void SetNeedsprocessing(bool value) { SetSchemaValue(m_ptr, "C_CommandContext", "needsprocessing", false, value); }
    int32_t GetCommand_number() const { return GetSchemaValue<int32_t>(m_ptr, "C_CommandContext", "command_number"); }
    void SetCommand_number(int32_t value) { SetSchemaValue(m_ptr, "C_CommandContext", "command_number", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif