#ifndef _swiftly_player_eyeangle_h
#define _swiftly_player_eyeangle_h

#include <map>
#include <string>

#include "../swiftly_memory.h"
#include "../swiftly.h"

std::map<std::string, float> DeserializeCoordsData(const char *jsonData);

typedef const char *(*Player_GetAngles)(uint32_t);
typedef void (*Player_SetAngles)(uint32_t, float, float, float);

class EyeAngle
{
private:
    uint32_t m_playerSlot;

public:
    EyeAngle(uint32_t playerSlot) : m_playerSlot(playerSlot) {}

    Vector *Get()
    {
        void *player_GetAngles = FetchFunctionPtr(nullptr, "scripting_Player_GetEyeAngles");
        if (player_GetAngles)
        {
            const char *ret_val = reinterpret_cast<Player_GetAngles>(player_GetAngles)(this->m_playerSlot);

            std::map<std::string, float> coords = DeserializeCoordsData(ret_val);
            if (!coords.size())
                return new Vector(0, 0, 0);

            return new Vector(coords.at("x"), coords.at("y"), coords.at("z"));
        }
        else
        {
            NOT_SUPPORTED("scripting_Player_GetEyeAngles");
            return new Vector(0, 0, 0);
        }
    }

    void Set(Vector *coords)
    {
        if (!coords)
            return;

        REGISTER_METHOD_VOID(scripting_Player_SetEyeAngles, this->m_playerSlot, coords->x, coords->y, coords->z);
    }
};

#endif