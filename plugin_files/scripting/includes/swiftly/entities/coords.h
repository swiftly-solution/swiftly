#ifndef _swiftly_entities_coords_h
#define _swiftly_entities_coords_h

#include <map>
#include <string>

#include "../swiftly_memory.h"
#include "../swiftly.h"

std::map<std::string, float> DeserializeCoordsData(const char *jsonData);

typedef const char *(*Entity_GetCoords)(uint32_t);
typedef void (*Entity_SetCoords)(uint32_t, float, float, float);

class ECoords
{
private:
    uint32_t entityId;

public:
    ECoords(uint32_t eId) : entityId(eId) {}

    Vector *Get()
    {
        void *entity_GetCoords = FetchFunctionPtr(nullptr, "scripting_Entity_GetCoords");
        if (entity_GetCoords)
        {
            const char *ret_val = reinterpret_cast<Entity_GetCoords>(entity_GetCoords)(this->entityId);

            std::map<std::string, float> coords = DeserializeCoordsData(ret_val);
            if (!coords.size())
                return new Vector(0, 0, 0);

            return new Vector(coords.at("x"), coords.at("y"), coords.at("z"));
        }
        else
        {
            NOT_SUPPORTED("scripting_Entity_GetCoords");
            return new Vector(0, 0, 0);
        }
    }

    void Set(Vector *coords)
    {
        REGISTER_METHOD_VOID(scripting_Entity_SetCoords, this->entityId, coords->x, coords->y, coords->z);
    }
};

#endif