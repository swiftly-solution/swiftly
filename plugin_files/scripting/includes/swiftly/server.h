#ifndef _swiftly_server_h
#define _swiftly_server_h

#include "swiftly_memory.h"
#include "swiftly_utils.h"
#include "types.h"
#include "convar.h"
#include <stdlib.h>

class Server
{
public:
    Convars *cvars;

    Server()
    {
        this->cvars = new Convars();
    }

    void ExecuteCommand(const char *str, ...)
    {
        void *printfunc = FetchFunctionPtr(nullptr, "scripting_Server_ExecuteCommand");
        if (printfunc != nullptr)
        {
            va_list ap;
            char buffer[2048];

            va_start(ap, str);
            UTIL_FormatArgs(buffer, sizeof(buffer), str, ap);
            va_end(ap);

            reinterpret_cast<Server_ExecuteCommand>(printfunc)(buffer);
        }
    }

    void ChangeLevel(const char *map)
    {
        this->ExecuteCommand("changelevel %s", map);
    }
};

extern Server *server;

#endif