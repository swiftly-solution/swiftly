#ifndef _player_predict_h
#define _player_predict_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class Predict
{
private:
    uint32_t m_playerSlot;

public:
    Predict(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Predict() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetPredict, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetPredict, this->m_playerSlot, val);
    }
};

#endif