#ifndef _gjumpcorrectionmethod_h
#define _gjumpcorrectionmethod_h

enum class JumpCorrectionMethod : uint64_t
{
    ScaleMotion = 0x0,
    AddCorrectionDelta = 0x1,
};

#endif