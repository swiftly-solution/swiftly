class GCPointClientCommand;

#ifndef _gccpointclientcommand_h
#define _gccpointclientcommand_h

#include "../../../scripting.h"




class GCPointClientCommand
{
private:
    void *m_ptr;

public:
    GCPointClientCommand() {}
    GCPointClientCommand(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif