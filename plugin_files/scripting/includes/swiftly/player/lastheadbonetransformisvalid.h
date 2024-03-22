#ifndef _player_lastheadbonetransformisvalid_h
#define _player_lastheadbonetransformisvalid_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastHeadBoneTransformIsValid
{
private:
    uint32_t m_playerSlot;

public:
    LastHeadBoneTransformIsValid(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastHeadBoneTransformIsValid() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetLastHeadBoneTransformIsValid, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastHeadBoneTransformIsValid, this->m_playerSlot, val);
    }
};

#endif