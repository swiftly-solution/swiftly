#ifndef _gtrain_code_h
#define _gtrain_code_h

enum class TRAIN_CODE : uint64_t
{
    TRAIN_SAFE = 0x0,
    TRAIN_BLOCKING = 0x1,
    TRAIN_FOLLOWING = 0x2,
};

#endif