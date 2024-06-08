class GCGamePlayerEquip;

#ifndef _gccgameplayerequip_h
#define _gccgameplayerequip_h

#include "../../../scripting.h"




class GCGamePlayerEquip
{
private:
    void *m_ptr;

public:
    GCGamePlayerEquip() {}
    GCGamePlayerEquip(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif