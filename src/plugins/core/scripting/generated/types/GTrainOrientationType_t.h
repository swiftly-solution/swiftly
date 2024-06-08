#ifndef _gtrainorientationtype_t_h
#define _gtrainorientationtype_t_h

enum class TrainOrientationType_t : uint64_t
{
    TrainOrientation_Fixed = 0x0,
    TrainOrientation_AtPathTracks = 0x1,
    TrainOrientation_LinearBlend = 0x2,
    TrainOrientation_EaseInEaseOut = 0x3,
};

#endif