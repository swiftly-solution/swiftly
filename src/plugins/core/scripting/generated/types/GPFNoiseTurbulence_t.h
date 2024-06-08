#ifndef _gpfnoiseturbulence_t_h
#define _gpfnoiseturbulence_t_h

enum class PFNoiseTurbulence_t : uint64_t
{
    PF_NOISE_TURB_NONE = 0x0,
    PF_NOISE_TURB_HIGHLIGHT = 0x1,
    PF_NOISE_TURB_FEEDBACK = 0x2,
    PF_NOISE_TURB_LOOPY = 0x3,
    PF_NOISE_TURB_CONTRAST = 0x4,
    PF_NOISE_TURB_ALTERNATE = 0x5,
};

#endif