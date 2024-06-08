#ifndef _gcvsoundformat_t_h
#define _gcvsoundformat_t_h

enum class CVSoundFormat_t : uint64_t
{
    PCM16 = 0x0,
    PCM8 = 0x1,
    MP3 = 0x2,
    ADPCM = 0x3,
};

#endif