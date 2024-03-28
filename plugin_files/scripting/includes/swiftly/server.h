#ifndef _swiftly_server_h
#define _swiftly_server_h

#include "swiftly_memory.h"
#include "swiftly_utils.h"
#include "types.h"
#include "convar.h"
#include <stdlib.h>

#include "server/precacher.h"

#ifdef GetCurrentTime
#undef GetCurrentTime
#endif

typedef void (*Server_QueuedMatchmaking)(bool);

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
        va_list ap;
        char buffer[2048];

        va_start(ap, str);
        UTIL_FormatArgs(buffer, sizeof(buffer), str, ap);
        va_end(ap);

        REGISTER_METHOD_VOID("scripting_Server_ExecuteCommand", buffer);
    }

    void ChangeLevel(const char *map)
    {
        this->ExecuteCommand("changelevel %s", map);
    }

    bool IsPistolRound()
    {
        REGISTER_METHOD_NOARGS(bool, false, scripting_Server_IsPistolRound);
    }

    int32_t GetTotalRounds()
    {
        REGISTER_METHOD_NOARGS(int32_t, 0, scripting_server_GetTotalRounds);
    }

    bool IsMapValid(const char *map)
    {
        REGISTER_METHOD_NOARGS(bool, false, scripting_Server_IsMapValid);
    }

    const char *GetMap()
    {
        REGISTER_METHOD_NOARGS(const char *, nullptr, scripting_Server_GetMapName);
    }

    uint16_t GetMaxPlayers()
    {
        REGISTER_METHOD_NOARGS(uint16_t, 0, scripting_Server_GetMaxPlayers)
    }

    float GetCurrentTime()
    {
        REGISTER_METHOD_NOARGS(float, 0.0f, scripting_Server_GetCurrentTime);
    }

    int32_t GetTickCount()
    {
        REGISTER_METHOD_NOARGS(int32_t, 0, scripting_Server_GetTickCount)
    }

    bool GetQueuedMatchmaking()
    {
        REGISTER_METHOD_NOARGS(bool, false, scripting_Server_GetQueuedMatchmaking)
    }

    void SetQueuedMatchmaking(bool status)
    {
        REGISTER_METHOD_VOID(scripting_Server_SetQueuedMatchmaking, status);
    }

    void SetQueuedMatchmakingMode(int mode)
    {
        REGISTER_METHOD_VOID(scripting_Server_SetQueuedMatchmakingMode, mode);
    }
};

extern Server *server;

#endif
