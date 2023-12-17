#ifndef _player_coords_h
#define _player_coords_h

#include <stdint.h>
#include <map>
#include <string>

#include "../swiftly_memory.h"
#include "../types.h"

#include <type_traits>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

typedef const char *(*Player_GetCoords)(uint32_t);
typedef void (*Player_SetCoords)(uint32_t, float, float, float);

std::map<std::string, float> DeserializeCoordsData(const char *jsonData);

class Coords
{
private:
    uint32_t m_playerSlot;

public:
    Coords(uint32_t playerSlot) : m_playerSlot(playerSlot) {}

    Vector *Get()
    {
        void *player_GetCoords = FetchFunctionPtr(nullptr, "scripting_Player_GetCoords");
        if (player_GetCoords)
        {
            const char *ret_val = reinterpret_cast<Player_GetCoords>(player_GetCoords)(this->m_playerSlot);

            std::map<std::string, float> coords = DeserializeCoordsData(ret_val);
            if (!coords.size())
                return new Vector(0, 0, 0);

            return new Vector(coords.at("x"), coords.at("y"), coords.at("z"));
        }
        else
            return new Vector(0, 0, 0);
    }

    void Set(Vector *coords)
    {
        void *player_SetCoords = FetchFunctionPtr(nullptr, "scripting_Player_SetCoords");
        if (player_SetCoords)
            reinterpret_cast<Player_SetCoords>(player_SetCoords)(this->m_playerSlot, coords->x, coords->y, coords->z);
    }
};

#endif