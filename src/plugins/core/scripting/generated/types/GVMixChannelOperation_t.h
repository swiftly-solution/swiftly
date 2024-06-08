#ifndef _gvmixchanneloperation_t_h
#define _gvmixchanneloperation_t_h

enum class VMixChannelOperation_t : uint64_t
{
    VMIX_CHAN_STEREO = 0x0,
    VMIX_CHAN_LEFT = 0x1,
    VMIX_CHAN_RIGHT = 0x2,
    VMIX_CHAN_SWAP = 0x3,
    VMIX_CHAN_MONO = 0x4,
    VMIX_CHAN_MID_SIDE = 0x5,
};

#endif