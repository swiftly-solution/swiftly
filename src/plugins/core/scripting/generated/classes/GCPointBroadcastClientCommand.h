class GCPointBroadcastClientCommand;

#ifndef _gccpointbroadcastclientcommand_h
#define _gccpointbroadcastclientcommand_h

#include "../../../scripting.h"




class GCPointBroadcastClientCommand
{
private:
    void *m_ptr;

public:
    GCPointBroadcastClientCommand() {}
    GCPointBroadcastClientCommand(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif