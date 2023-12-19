#ifndef _server_precacher_h
#define _server_precacher_h

#include "../swiftly_memory.h"

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
    }
};

#endif