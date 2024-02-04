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
        void *Precacher_AddModel = FetchFunctionPtr(nullptr, "scripting_Precacher_AddModel");
        if (Precacher_AddModel)
            reinterpret_cast<Server_AddPrecacheModel>(Precacher_AddModel)(model);
        else
            NOT_SUPPORTED("scripting_Precacher_AddModel");
    }

    void AddSound(const char *path)
    {
        void *Precacher_AddSound = FetchFunctionPtr(nullptr, "scripting_Precacher_AddSound");
        if (Precacher_AddSound)
            reinterpret_cast<Server_AddPrecacheModel>(Precacher_AddSound)(path);
        else
            NOT_SUPPORTED("scripting_Precacher_AddSound");
    }
};

#endif