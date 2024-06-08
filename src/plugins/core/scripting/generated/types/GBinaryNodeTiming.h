#ifndef _gbinarynodetiming_h
#define _gbinarynodetiming_h

enum class BinaryNodeTiming : uint64_t
{
    UseChild1 = 0x0,
    UseChild2 = 0x1,
    SyncChildren = 0x2,
};

#endif