#ifndef _ganimvaluesource_h
#define _ganimvaluesource_h

enum class AnimValueSource : uint64_t
{
    MoveHeading = 0x0,
    MoveSpeed = 0x1,
    ForwardSpeed = 0x2,
    StrafeSpeed = 0x3,
    FacingHeading = 0x4,
    LookHeading = 0x5,
    LookPitch = 0x6,
    LookDistance = 0x7,
    Parameter = 0x8,
    WayPointHeading = 0x9,
    WayPointDistance = 0xa,
    BoundaryRadius = 0xb,
    TargetMoveHeading = 0xc,
    TargetMoveSpeed = 0xd,
    AccelerationHeading = 0xe,
    AccelerationSpeed = 0xf,
    SlopeHeading = 0x10,
    SlopeAngle = 0x11,
    SlopePitch = 0x12,
    SlopeYaw = 0x13,
    GoalDistance = 0x14,
    AccelerationLeftRight = 0x15,
    AccelerationFrontBack = 0x16,
    RootMotionSpeed = 0x17,
    RootMotionTurnSpeed = 0x18,
    MoveHeadingRelativeToLookHeading = 0x19,
    MaxMoveSpeed = 0x1a,
    FingerCurl_Thumb = 0x1b,
    FingerCurl_Index = 0x1c,
    FingerCurl_Middle = 0x1d,
    FingerCurl_Ring = 0x1e,
    FingerCurl_Pinky = 0x1f,
    FingerSplay_Thumb_Index = 0x20,
    FingerSplay_Index_Middle = 0x21,
    FingerSplay_Middle_Ring = 0x22,
    FingerSplay_Ring_Pinky = 0x23,
};

#endif