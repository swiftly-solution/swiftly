#ifndef _gshakecommand_t_h
#define _gshakecommand_t_h

enum class ShakeCommand_t : uint64_t
{
    SHAKE_START = 0x0,
    SHAKE_STOP = 0x1,
    SHAKE_AMPLITUDE = 0x2,
    SHAKE_FREQUENCY = 0x3,
    SHAKE_START_RUMBLEONLY = 0x4,
    SHAKE_START_NORUMBLE = 0x5,
};

#endif