#ifndef _swiftly_server_h
#define _swiftly_server_h

#include "swiftly_memory.h"
#include "swiftly_utils.h"
#include "types.h"
#include "convar.h"
#include <stdlib.h>

#include "server/precacher.h"

class Server
{
public:
    Convars *cvars;
    Precacher *precacher;

    Server()
    {
        this->cvars = new Convars();
        this->precacher = new Precacher();
    }

    ~Server()
    {
        delete this->cvars;
        delete this->precacher;
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
        else
            NOT_SUPPORTED("scripting_Server_ExecuteCommand");
    }

    void ChangeLevel(const char *map)
    {
        this->ExecuteCommand("changelevel %s", map);
    }

    bool IsPistolRound()
    {
        void *IsPistolRoundFunc = FetchFunctionPtr(nullptr, "scripting_Server_IsPistolRound");
        if (IsPistolRoundFunc)
            return reinterpret_cast<Server_IsPistolRound>(IsPistolRoundFunc)();
        else
        {
            NOT_SUPPORTED("scripting_Server_IsPistolRound");
            return false;
        }
    }

    bool IsMapValid(const char *map)
    {
        void *IsMapValidFunc = FetchFunctionPtr(nullptr, "scripting_Server_IsMapValid");
        if (IsMapValidFunc)
            return reinterpret_cast<Server_IsMapValid>(IsMapValidFunc)(map);
        else
        {
            NOT_SUPPORTED("scripting_Server_IsMapValid");
            return false;
        }
    }

    const char *GetMap()
    {
        void *GetMapFunc = FetchFunctionPtr(nullptr, "scripting_Server_GetMapName");
        if (GetMapFunc)
            return reinterpret_cast<Server_GetMap>(GetMapFunc)();
        else
        {
            NOT_SUPPORTED("scripting_Server_GetMapName");
            return nullptr;
        }
    }

    uint16_t GetMaxPlayers()
    {
        void *GetMaxPlayersFunc = FetchFunctionPtr(nullptr, "scripting_Server_GetMaxPlayers");
        if (GetMaxPlayersFunc)
            return reinterpret_cast<Server_GetMaxPlayers>(GetMaxPlayersFunc)();
        else
        {
            NOT_SUPPORTED("scripting_Server_GetMaxPlayers");
            return 0;
        }
    }

    float GetCurrentTime()
    {
        void *GetCurrentTimeFunc = FetchFunctionPtr(nullptr, "scripting_Server_GetCurrentTime");
        if (GetCurrentTimeFunc)
            return reinterpret_cast<Server_GetCurrentTime>(GetCurrentTimeFunc)();
        else
        {
            NOT_SUPPORTED("scripting_Server_GetCurrentTime");
            return 0.0f;
        }
    }

    int32_t GetTickCount()
    {
        void *GetTickCountFunc = FetchFunctionPtr(nullptr, "scripting_Server_GetTickCount");
        if (GetTickCountFunc)
            return reinterpret_cast<Server_GetTickCount>(GetTickCountFunc)();
        else
        {
            NOT_SUPPORTED("scripting_Server_GetTickCount");
            return 0;
        }
    }
};

extern Server *server;

#endif
