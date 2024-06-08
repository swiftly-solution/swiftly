class GCCSPointScriptExtensions_player;

#ifndef _gcccspointscriptextensions_player_h
#define _gcccspointscriptextensions_player_h

#include "../../../scripting.h"




class GCCSPointScriptExtensions_player
{
private:
    void *m_ptr;

public:
    GCCSPointScriptExtensions_player() {}
    GCCSPointScriptExtensions_player(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif