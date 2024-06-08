#ifndef _gseqposesetting_t_h
#define _gseqposesetting_t_h

enum class SeqPoseSetting_t : uint64_t
{
    SEQ_POSE_SETTING_CONSTANT = 0x0,
    SEQ_POSE_SETTING_ROTATION = 0x1,
    SEQ_POSE_SETTING_POSITION = 0x2,
    SEQ_POSE_SETTING_VELOCITY = 0x3,
};

#endif