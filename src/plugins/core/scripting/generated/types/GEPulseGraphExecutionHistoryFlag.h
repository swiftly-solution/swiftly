#ifndef _gepulsegraphexecutionhistoryflag_h
#define _gepulsegraphexecutionhistoryflag_h

enum class EPulseGraphExecutionHistoryFlag : uint64_t
{
    NO_FLAGS = 0x0,
    CURSOR_ADD_TAG = 0x1,
    CURSOR_REMOVE_TAG = 0x2,
    CURSOR_RETIRED = 0x4,
    REQUIREMENT_PASS = 0x8,
    REQUIREMENT_FAIL = 0x10,
};

#endif