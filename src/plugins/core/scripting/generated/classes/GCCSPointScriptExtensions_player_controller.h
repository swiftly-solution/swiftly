class GCCSPointScriptExtensions_player_controller;

#ifndef _gcccspointscriptextensions_player_controller_h
#define _gcccspointscriptextensions_player_controller_h

#include "../../../scripting.h"




class GCCSPointScriptExtensions_player_controller
{
private:
    void *m_ptr;

public:
    GCCSPointScriptExtensions_player_controller() {}
    GCCSPointScriptExtensions_player_controller(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif