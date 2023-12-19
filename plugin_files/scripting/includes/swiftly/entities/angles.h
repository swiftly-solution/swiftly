#ifndef _swiftly_entities_angles_h
#define _swiftly_entities_angles_h

#include <map>
#include <string>

#include "../swiftly_memory.h"
#include "../swiftly.h"

std::map<std::string, float> DeserializeCoordsData(const char *jsonData);

typedef const char *(*Entity_GetAngles)(uint32_t);
typedef void (*Entity_SetAngles)(uint32_t, float, float, float);

class Angles
{
private:
    uint32_t entityId;

public:
    Angles(uint32_t eId) : entityId(eId) {}

    Vector *Get()
    {
        void *entity_GetAngles = FetchFunctionPtr(nullptr, "scripting_Entity_GetAngles");
        if (entity_GetAngles)
        {
            const char *ret_val = reinterpret_cast<Entity_GetAngles>(entity_GetAngles)(this->entityId);

            std::map<std::string, float> coords = DeserializeCoordsData(ret_val);
            if (!coords.size())
                return new Vector(0, 0, 0);

            return new Vector(coords.at("x"), coords.at("y"), coords.at("z"));
        }
        else
        {
            NOT_SUPPORTED("scripting_Entity_GetAngles");
            return new Vector(0, 0, 0);
        }
    }

    void Set(Vector *coords)
    {
        void *entity_SetAngles = FetchFunctionPtr(nullptr, "scripting_Entity_SetAngles");
        if (entity_SetAngles)
            reinterpret_cast<Entity_SetAngles>(entity_SetAngles)(this->entityId, coords->x, coords->y, coords->z);
        else
            NOT_SUPPORTED("scripting_Entity_SetAngles");
    }
};

#endif