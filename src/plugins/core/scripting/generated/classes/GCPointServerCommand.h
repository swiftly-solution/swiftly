class GCPointServerCommand;

#ifndef _gccpointservercommand_h
#define _gccpointservercommand_h

#include "../../../scripting.h"




class GCPointServerCommand
{
private:
    void *m_ptr;

public:
    GCPointServerCommand() {}
    GCPointServerCommand(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif