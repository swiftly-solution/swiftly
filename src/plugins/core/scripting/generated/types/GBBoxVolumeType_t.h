#ifndef _gbboxvolumetype_t_h
#define _gbboxvolumetype_t_h

enum class BBoxVolumeType_t : uint64_t
{
    BBOX_VOLUME = 0x0,
    BBOX_DIMENSIONS = 0x1,
    BBOX_MINS_MAXS = 0x2,
};

#endif