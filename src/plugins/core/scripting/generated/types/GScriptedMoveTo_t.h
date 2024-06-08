#ifndef _gscriptedmoveto_t_h
#define _gscriptedmoveto_t_h

enum class ScriptedMoveTo_t : uint64_t
{
    eWait = 0x0,
    eMoveWithGait = 0x3,
    eTeleport = 0x4,
    eWaitFacing = 0x5,
    eObsoleteBackCompat1 = 0x1,
    eObsoleteBackCompat2 = 0x2,
};

#endif