#ifndef _player_flashmaxalpha_h
#define _player_flashmaxalpha_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class FlashMaxAlpha
{
private:
    uint32_t m_playerSlot;

public:
    FlashMaxAlpha(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~FlashMaxAlpha() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetFlashMaxAlpha, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetFlashMaxAlpha, this->m_playerSlot, val);
    }
};

#endif