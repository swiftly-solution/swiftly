#ifndef _gscriptedconflictresponse_t_h
#define _gscriptedconflictresponse_t_h

enum class ScriptedConflictResponse_t : uint64_t
{
    SS_CONFLICT_ENQUEUE = 0x0,
    SS_CONFLICT_INTERRUPT = 0x1,
};

#endif