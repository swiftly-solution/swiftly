#ifndef _gseqcmd_t_h
#define _gseqcmd_t_h

enum class SeqCmd_t : uint64_t
{
    SeqCmd_Nop = 0x0,
    SeqCmd_LinearDelta = 0x1,
    SeqCmd_FetchFrameRange = 0x2,
    SeqCmd_Slerp = 0x3,
    SeqCmd_Add = 0x4,
    SeqCmd_Subtract = 0x5,
    SeqCmd_Scale = 0x6,
    SeqCmd_Copy = 0x7,
    SeqCmd_Blend = 0x8,
    SeqCmd_Worldspace = 0x9,
    SeqCmd_Sequence = 0xa,
    SeqCmd_FetchCycle = 0xb,
    SeqCmd_FetchFrame = 0xc,
    SeqCmd_IKLockInPlace = 0xd,
    SeqCmd_IKRestoreAll = 0xe,
    SeqCmd_ReverseSequence = 0xf,
    SeqCmd_Transform = 0x10,
};

#endif