#ifndef _gtrackorientationtype_t_h
#define _gtrackorientationtype_t_h

enum class TrackOrientationType_t : uint64_t
{
    TrackOrientation_Fixed = 0x0,
    TrackOrientation_FacePath = 0x1,
    TrackOrientation_FacePathAngles = 0x2,
};

#endif