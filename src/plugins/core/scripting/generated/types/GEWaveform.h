#ifndef _gewaveform_h
#define _gewaveform_h

enum class EWaveform : uint64_t
{
    Sine = 0x0,
    Square = 0x1,
    Saw = 0x2,
    Triangle = 0x3,
    Noise = 0x4,
};

#endif