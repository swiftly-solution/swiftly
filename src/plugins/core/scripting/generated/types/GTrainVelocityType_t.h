#ifndef _gtrainvelocitytype_t_h
#define _gtrainvelocitytype_t_h

enum class TrainVelocityType_t : uint64_t
{
    TrainVelocity_Instantaneous = 0x0,
    TrainVelocity_LinearBlend = 0x1,
    TrainVelocity_EaseInEaseOut = 0x2,
};

#endif