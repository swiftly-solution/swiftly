#ifndef _ganimposecontrol_h
#define _ganimposecontrol_h

enum class AnimPoseControl : uint64_t
{
    NoPoseControl = 0x0,
    AbsolutePoseControl = 0x1,
    RelativePoseControl = 0x2,
};

#endif