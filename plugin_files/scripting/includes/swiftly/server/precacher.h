#ifndef _server_precacher_h
#define _server_precacher_h

#include "../swiftly_memory.h"
#include "../swiftly.h"

class Precacher
{
public:
    Precacher() {}

    ~Precacher() {}

    void AddModel(const char *model)
    {
        REGISTER_METHOD_VOID(scripting_Precacher_AddModel, model);
    }

    void AddSound(const char *path)
    {
        REGISTER_METHOD_VOID(scripting_Precacher_AddSound, path);
    }
};

#endif