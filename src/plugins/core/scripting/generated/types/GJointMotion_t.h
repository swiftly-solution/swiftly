#ifndef _gjointmotion_t_h
#define _gjointmotion_t_h

enum class JointMotion_t : uint64_t
{
    JOINT_MOTION_FREE = 0x0,
    JOINT_MOTION_LOCKED = 0x1,
    JOINT_MOTION_COUNT = 0x2,
};

#endif