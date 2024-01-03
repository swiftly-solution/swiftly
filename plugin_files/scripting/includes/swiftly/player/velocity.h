#ifndef _player_velocity_h
#define _player_velocity_h

#include <stdint.h>
#include <map>
#include <string>

#include "../swiftly_memory.h"
#include "../types.h"
#include "../swiftly_utils.h"

#include <type_traits>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

typedef const char *(*Player_GetVelocity)(uint32_t);
typedef void (*Player_SetVelocity)(uint32_t, float, float, float);

std::map<std::string, float> DeserializeCoordsData(const char *jsonData);

class Velocity
{
private:
    uint32_t m_playerSlot;

public:
    Velocity(uint32_t playerSlot) : m_playerSlot(playerSlot) {}

    Vector *Get()
    {
        void *player_GetVelocity = FetchFunctionPtr(nullptr, "scripting_Player_GetVelocity");
        if (player_GetVelocity)
        {
            const char *ret_val = reinterpret_cast<Player_GetVelocity>(player_GetVelocity)(this->m_playerSlot);

            std::map<std::string, float> coords = DeserializeCoordsData(ret_val);
            if (!coords.size())
                return new Vector(0, 0, 0);

            return new Vector(coords.at("x"), coords.at("y"), coords.at("z"));
        }
        else
        {
            NOT_SUPPORTED("scripting_Player_GetVelocity");
            return new Vector(0, 0, 0);
        }
    }

    void Set(Vector *coords)
    {
        void *player_SetVelocity = FetchFunctionPtr(nullptr, "scripting_Player_SetVelocity");
        if (player_SetVelocity)
            reinterpret_cast<Player_SetVelocity>(player_SetVelocity)(this->m_playerSlot, coords->x, coords->y, coords->z);
        else
            NOT_SUPPORTED("scripting_Player_SetVelocity");
    }
};

#endif