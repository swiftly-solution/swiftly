#ifndef _swiftly_entities_colors_h
#define _swiftly_entities_colors_h

#include <map>
#include <string>

#include "../swiftly_memory.h"
#include "../swiftly.h"

#include <type_traits>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

std::map<std::string, int> DeserializeColorData(const char *jsonData);

typedef const char *(*Entity_GetColors)(uint32_t);
typedef void (*Entity_SetColors)(uint32_t, int, int, int, int);

class Colors
{
private:
    uint32_t entityId;

public:
    Colors(uint32_t eId) : entityId(eId) {}

    Color *Get()
    {
        void *entity_GetColors = FetchFunctionPtr(nullptr, "scripting_Entity_GetColors");
        if (entity_GetColors)
        {
            const char *ret_val = reinterpret_cast<Entity_GetColors>(entity_GetColors)(this->entityId);

            std::map<std::string, int> colors = DeserializeColorData(ret_val);
            if (!colors.size())
                return new Color(0, 0, 0, 0);

            return new Color(colors.at("r"), colors.at("g"), colors.at("b"), colors.at("a"));
        }
        else
        {
            NOT_SUPPORTED("scripting_Entity_GetColors");
            return new Color(0, 0, 0, 0);
        }
    }

    void Set(Color *color)
    {
        REGISTER_METHOD_VOID(scripting_Entity_SetColors, this->entityId, color->r, color->g, color->b, color->a);
    }
};

#endif