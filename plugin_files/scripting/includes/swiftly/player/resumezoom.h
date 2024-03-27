#ifndef _player_resumezoom_h
#define _player_resumezoom_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class ResumeZoom
{
private:
    uint32_t m_playerSlot;

public:
    ResumeZoom(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~ResumeZoom() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetResumeZoom, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetResumeZoom, this->m_playerSlot, val);
    }
};

#endif