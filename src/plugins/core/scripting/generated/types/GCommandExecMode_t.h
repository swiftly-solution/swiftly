#ifndef _gcommandexecmode_t_h
#define _gcommandexecmode_t_h

enum class CommandExecMode_t : uint64_t
{
    EXEC_MANUAL = 0x0,
    EXEC_LEVELSTART = 0x1,
    EXEC_PERIODIC = 0x2,
    EXEC_MODES_COUNT = 0x3,
};

#endif