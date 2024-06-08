#ifndef _ganimvectorsource_h
#define _ganimvectorsource_h

enum class AnimVectorSource : uint64_t
{
    MoveDirection = 0x0,
    FacingDirection = 0x1,
    LookDirection = 0x2,
    VectorParameter = 0x3,
    WayPointDirection = 0x4,
    Acceleration = 0x5,
    SlopeNormal = 0x6,
    SlopeNormal_WorldSpace = 0x7,
    LookTarget = 0x8,
    LookTarget_WorldSpace = 0x9,
    WayPointPosition = 0xa,
    GoalPosition = 0xb,
    RootMotionVelocity = 0xc,
    ManualTarget_WorldSpace = 0xd,
};

#endif